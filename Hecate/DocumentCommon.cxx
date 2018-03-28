#include "DocumentCommon.h"

#include "ApplicationCommon.h"
#include "Transparency.h"
#include "Material.h"
#include "View.h"

#include <QStatusBar>
#include <QApplication>
#include <QColor>
#include <QColorDialog>

#include <Aspect_DisplayConnection.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Graphic3d_NameOfMaterial.hxx>
#include <OpenGl_GraphicDriver.hxx>
#include <TCollection_AsciiString.hxx>

#include <TopoDS_Shape.hxx>
#include <AIS_Shape.hxx>
#include <AIS_Point.hxx>
#include "QFileDialog"
#include "QFileInfo"
#include "XCAFApp_Application.hxx"
#include "IFSelect_ReturnStatus.hxx"
#include "STEPCAFControl_Reader.hxx"
#include <STEPControl_Reader.hxx>
#include <XSControl_WorkSession.hxx>
#include "ImportOCAF.h"
#include <QMdiSubWindow>
#include "QMessageBox"
#include <QDebug>
#include "TopoDS_Vertex.hxx"
#include "TopoDS.hxx"
#include "BRep_Tool.hxx"
#include "Geom_Curve.hxx"
#include "TopoDS_Edge.hxx"
#include "Geom_Circle.hxx"
#include "BRepPrimAPI_MakeCylinder.hxx"
#include "BRepPrimAPI_MakeSphere.hxx"

TopoDS_Shape
MakeBottle(const Standard_Real myWidth, const Standard_Real myHeight, const Standard_Real myThickness);

// =======================================================================
// function : Viewer
// purpose  :
// =======================================================================
Handle(V3d_Viewer) DocumentCommon::Viewer (const Standard_ExtString ,
                                           const Standard_CString ,
                                           const Standard_Real theViewSize,
                                           const V3d_TypeOfOrientation theViewProj,
                                           const Standard_Boolean theComputedMode,
                                           const Standard_Boolean theDefaultComputedMode )
{
  static Handle(OpenGl_GraphicDriver) aGraphicDriver;

  if (aGraphicDriver.IsNull())
  {
    Handle(Aspect_DisplayConnection) aDisplayConnection;
#if !defined(_WIN32) && !defined(__WIN32__) && (!defined(__APPLE__) || defined(MACOSX_USE_GLX))
    aDisplayConnection = new Aspect_DisplayConnection (qgetenv ("DISPLAY").constData());
#endif
    aGraphicDriver = new OpenGl_GraphicDriver (aDisplayConnection);
  }

  Handle(V3d_Viewer) aViewer = new V3d_Viewer (aGraphicDriver);
  aViewer->SetDefaultViewSize (theViewSize);
  aViewer->SetDefaultViewProj (theViewProj);
  aViewer->SetComputedMode (theComputedMode);
  aViewer->SetDefaultComputedMode (theDefaultComputedMode);
  return aViewer;
}


void DocumentCommon::timerEvent(QTimerEvent *event)
{
	QList<PartModel*> listPart = m_Project->getPartModelList();
	//m_partModelList;
	if (!m_AISShapeList.empty())
	{
		// �Ȼ��֡��������֡����, �ڰ���ÿһ֡��Model��λ�ø���
		int nTrsSize = listPart.at(0)->getPartModelTransform().size();
		if (nTrsSize==0)
		{			
			return;
		}

		for (int nCurrent = 0; nCurrent < m_AISShapeList.size(); ++nCurrent)
		{
			Handle(AIS_Shape) ipCurrentAIS = m_AISShapeList.value(nCurrent);
			PartModel* pCurrentPartModel = listPart.at(nCurrent);
			gp_Trsf tempTrs = pCurrentPartModel->getPartModelTransform().at(m_CurrentFrame);
			TopLoc_Location oCurrentLocation(tempTrs);

			myContext->SetLocation(ipCurrentAIS, oCurrentLocation);
			myContext->UpdateCurrentViewer();
		}
		m_CurrentFrame++;
		if (m_CurrentFrame>=nTrsSize)
		{
			m_CurrentFrame = 0;
			onKillTimer(m_TimerID);
		}


	}
	//throw std::logic_error("The method or operation is not implemented.");
}

DocumentCommon::DocumentCommon(const int theIndex, ApplicationCommonWindow* app)
: QObject( app ),
myApp( app ),
myIndex( theIndex ),
myNbViews( 0 ),
m_Project(nullptr)
{
	m_CurrentFrame = 0;
  TCollection_ExtendedString a3DName ("Visu3D");

  myViewer = Viewer (a3DName.ToExtString(), "", 1000.0, V3d_XposYnegZpos, Standard_True, Standard_True);

  myViewer->SetDefaultLights();
  myViewer->SetLightOn();

  myContext = new AIS_InteractiveContext (myViewer);
  //setSelectType(TopAbs_SHAPE);
  m_SelectEnum = TopAbs_SHAPE;
  //m_partModelList.clear();

  makeAixs();
}

DocumentCommon::~DocumentCommon()
{
}

ApplicationCommonWindow* DocumentCommon::getApplication()
{
  return myApp;
}

MDIWindow* DocumentCommon::createNewMDIWindow()
{
  QMdiArea* ws = myApp->getWorkspace();
  return new MDIWindow (this, ws, 0);
}

void DocumentCommon::onCreateNewView()
{
	m_Project = new HCProject;
  QMdiArea* ws = myApp->getWorkspace();
  MDIWindow* w = createNewMDIWindow();
  w->getView()->rotation();
  
  if (!w)
    return;

  ws->addSubWindow (w);
  myViews.append (w);

  connect( w,    SIGNAL( selectionChanged() ),
           this, SIGNAL( selectionChanged() ) );
  connect( w, SIGNAL( message( const QString&, int ) ),
           myApp->statusBar(), SLOT( showMessage( const QString&, int ) ) );
  connect( w, SIGNAL( sendCloseView( MDIWindow* ) ),
           this, SLOT( onCloseView( MDIWindow* ) ) );
  connect(this, SIGNAL(selectionChanged()), this, SLOT(onSelectedModel()));

  QString aName;
  w->setWindowTitle( aName.sprintf( "Document %d:%d", myIndex, ++myNbViews ) );
  QString dir = ApplicationCommonWindow::getResourceDir() + QString( "/" );
  
  w->setWindowIcon( QPixmap( dir + QObject::tr("ICON_DOC") ) );

  if ( ws->subWindowList().isEmpty() )
  {
    // Due to strange Qt4.2.3 feature the child window icon is not drawn
    // in the main menu if showMaximized() is called for a non-visible child window
    // Therefore calling show() first...
    w->show();
    w->showMaximized();
  }
  else
    w->show();

  w->setFocus();

  getApplication()->onSelectionChanged();
}

void DocumentCommon::onCloseView(MDIWindow* theView)
{
    removeView(theView);
    if( countOfWindow() == 0 )
        emit sendCloseDocument( this );
}

void DocumentCommon::removeView(MDIWindow* theView)
{
    if ( myViews.count( theView ) )
    {
    myViews.removeAll(theView);
    delete theView;
  }
}
void DocumentCommon::removeViews()
{
  while( myViews.count() )
  {
    removeView( myViews.first() );
  }
}

int DocumentCommon::countOfWindow()
{
  return myViews.count();
}

Handle(AIS_InteractiveContext) DocumentCommon::getContext()
{
  return myContext;
}

void DocumentCommon::fitAll()
{
  QList<MDIWindow*>::iterator i;
  for ( i = myViews.begin(); i != myViews.end(); i++ )
    (*i)->fitAll();
}


void DocumentCommon::onMakeBottle()
{
	QApplication::setOverrideCursor(Qt::WaitCursor);
	TopoDS_Shape aBottle = MakeBottle(50, 70, 30);
	Handle(AIS_Shape) AISBottle = new AIS_Shape(aBottle);
	getContext()->SetMaterial(AISBottle, Graphic3d_NOM_GOLD, Standard_False);
	getContext()->SetDisplayMode(AISBottle, 1, Standard_False);
	getContext()->Display(AISBottle, Standard_False);
	const Handle(AIS_InteractiveObject)& anIOAISBottle = AISBottle;
	getContext()->SetSelected(anIOAISBottle, Standard_False);
	emit selectionChanged();
	fitAll();
	QApplication::restoreOverrideCursor();
}


void DocumentCommon::makeAixs()
{
	TopoDS_Shape originPoint = BRepPrimAPI_MakeSphere(0.2);

	TopoDS_Shape XShape = BRepPrimAPI_MakeCylinder(gp_Ax2(gp_Pnt(0, 0, 0.),
		gp_Dir(1., 0., 0.)),
		0.2, 20.);
	TopoDS_Shape YShape = BRepPrimAPI_MakeCylinder(gp_Ax2(gp_Pnt(0, 0, 0.),
		gp_Dir(0., 1., 0.)),
		0.2, 20.);
	TopoDS_Shape ZShape = BRepPrimAPI_MakeCylinder(gp_Ax2(gp_Pnt(0, 0, 0.),
		gp_Dir(0., 0., 1.)),
		0.2, 20.);

	Handle(AIS_Shape) iporiginPoint = new AIS_Shape(originPoint);
	//iporiginPoint->SetHilightAttributes()
	getContext()->SetColor(iporiginPoint, Quantity_Color(Quantity_NOC_RED), Standard_False);
	getContext()->SetDisplayMode(iporiginPoint, 1, Standard_False);
	getContext()->Display(iporiginPoint, Standard_False);

	Handle(AIS_Shape) ipXAxis = new AIS_Shape(XShape);
	getContext()->SetColor(ipXAxis, Quantity_Color(Quantity_NOC_RED), Standard_False);
	getContext()->SetDisplayMode(ipXAxis, 1, Standard_False);
	getContext()->Display(ipXAxis, Standard_False);

	Handle(AIS_Shape) ipYAxis = new AIS_Shape(YShape);
	getContext()->SetColor(ipYAxis, Quantity_Color(Quantity_NOC_GOLD), Standard_False);
	getContext()->SetDisplayMode(ipYAxis, 1, Standard_False);
	getContext()->Display(ipYAxis, Standard_False);

	Handle(AIS_Shape) ipZAxis = new AIS_Shape(ZShape);
	getContext()->SetColor(ipZAxis, Quantity_Color(Quantity_NOC_BLUE1), Standard_False);
	getContext()->SetDisplayMode(ipZAxis, 1, Standard_False);
	getContext()->Display(ipZAxis, Standard_False);

}

void DocumentCommon::updatePartList()
{
	QList<PartModel*> listCurrent = m_Project->getPartModelList();
	if (listCurrent.isEmpty())
	{
		return;
	}
	for (int nCurrent = 0; nCurrent < listCurrent.size(); ++nCurrent)
	{
		PartModel* pCurrentPart = listCurrent.value(nCurrent);
		TopoDS_Shape pCurrentShape = pCurrentPart->getPartShape();

		Handle(AIS_Shape) pAISCurrentShape = new AIS_Shape(pCurrentShape);
		m_AISShapeList.append(pAISCurrentShape);
		
		getContext()->SetColor(pAISCurrentShape, pCurrentPart->getQuantityColor(), Standard_False);
		getContext()->SetDisplayMode(pAISCurrentShape, 1, Standard_False);
		getContext()->Display(pAISCurrentShape, Standard_False);
	}
	QMdiArea* ws = myApp->getWorkspace();
	MDIWindow* window = qobject_cast<MDIWindow*>(ws->activeSubWindow()->widget());
	window->setModelTree(listCurrent);
	emit selectionChanged();
	fitAll();

}


HCProject* DocumentCommon::getProject()
{
	return m_Project;
}

QList<PartModel*> DocumentCommon::getPartModelList()
{
	return m_Project->getPartModelList();

}


void DocumentCommon::setSelectType(TopAbs_ShapeEnum typeID)
{
	// /* ѡ��ģʽ
	//TopAbs_COMPOUND,
	//TopAbs_COMPSOLID,
	//TopAbs_SOLID,
	//TopAbs_SHELL,
	//TopAbs_FACE,
	//TopAbs_WIRE,
	//TopAbs_EDGE,
	//TopAbs_VERTEX,
	//TopAbs_SHAPE
	// */
	m_SelectEnum = typeID;
	myContext->CloseAllContexts(true);
	myContext->OpenLocalContext(true, true, false, false);
	switch (typeID)
	{
	case TopAbs_COMPOUND:
		myContext->ActivateStandardMode(TopAbs_COMPOUND);
		break;
	case TopAbs_COMPSOLID:
		myContext->ActivateStandardMode(TopAbs_COMPSOLID);
		break;
	case TopAbs_SOLID:
		myContext->ActivateStandardMode(TopAbs_SOLID);
		break;
	case TopAbs_SHELL:
		myContext->ActivateStandardMode(TopAbs_SHELL);
		break;
	case TopAbs_FACE:
		myContext->ActivateStandardMode(TopAbs_FACE);
		break;
	case TopAbs_WIRE:
		myContext->ActivateStandardMode(TopAbs_WIRE);
		break;
	case TopAbs_EDGE:
		myContext->ActivateStandardMode(TopAbs_EDGE);
		break;
	case TopAbs_VERTEX:
		myContext->ActivateStandardMode(TopAbs_VERTEX);
		break;
	case TopAbs_SHAPE:
		myContext->ActivateStandardMode(TopAbs_SHAPE);
		break;
	default:
		myContext->CloseAllContexts(true);
		break;
	}
	myContext->UpdateCurrentViewer();
}

TopAbs_ShapeEnum DocumentCommon::getSelectType()
{
	return m_SelectEnum;
}

// ��ANSI���ļ�ת��ΪUTF-8��ʽ
QString DocumentCommon::ANSIFileConvertUtf8(QString fileName)
{
	QFile oFileOpen(fileName);
	if (!oFileOpen.exists())
	{
		return QString("");
	}
	oFileOpen.open(QIODevice::ReadWrite);
	QTextStream strTextStream(&oFileOpen);
	QString strText = strTextStream.readAll();

	QFileInfo inputFileInfo(fileName);
	QString strOutFilePath = inputFileInfo.absolutePath() + QString("/");
	QString strOutFileBase = inputFileInfo.baseName() + QString("_ToUtf8.STEP");
	QString strOutFileName = strOutFilePath + strOutFileBase;

	QFile outPutFile(strOutFileName);
	if (outPutFile.exists())
	{
		return strOutFileName;
	}

	if (outPutFile.open(QIODevice::ReadWrite | QIODevice::Text))
	{
		QTextStream outTextStream(&outPutFile);
		outTextStream.setCodec("UTF-8");
		outTextStream << strText;
		outTextStream.flush();
		outPutFile.close();
		return strOutFileName;
	}
	return QString("");
}

TopoDS_Shape & DocumentCommon::getSelectShape()
{
	// TODO: �ڴ˴����� return ���
	return m_selectedShape;
}

void DocumentCommon::onWireframe()
{
    QApplication::setOverrideCursor( Qt::WaitCursor );
    for( myContext->InitSelected(); myContext->MoreSelected(); myContext->NextSelected() )
        myContext->SetDisplayMode( myContext->SelectedInteractive(), 0, false );
    myContext->UpdateCurrentViewer();
    getApplication()->onSelectionChanged();
    QApplication::restoreOverrideCursor();
}

void DocumentCommon::onShading()
{
    QApplication::setOverrideCursor( Qt::WaitCursor );
    for( myContext->InitSelected(); myContext->MoreSelected(); myContext->NextSelected() )
        myContext->SetDisplayMode( myContext->SelectedInteractive(), 1, false );
    myContext->UpdateCurrentViewer();
    getApplication()->onSelectionChanged();
    QApplication::restoreOverrideCursor();
}

void DocumentCommon::onColor()
{
    QColor aColor ;
    myContext->InitSelected();
    Handle(AIS_InteractiveObject) Current = myContext->SelectedInteractive() ;
	if ( Current->HasColor () )
    {
        Quantity_Color aShapeColor;
        myContext->Color( Current, aShapeColor );
        aColor.setRgb( aShapeColor.Red() * 255, aShapeColor.Green() * 255, aShapeColor.Blue() * 255 );
    }
    else
        aColor.setRgb( 255, 255, 255 );

    QColor aRetColor = QColorDialog::getColor( aColor );
    if ( aRetColor.isValid() )
    {
        Quantity_Color color( aRetColor.red() / 255., aRetColor.green() / 255.,
                        aRetColor.blue() / 255., Quantity_TOC_RGB );
        for (; myContext->MoreSelected(); myContext->NextSelected() )
            myContext->SetColor( myContext->SelectedInteractive(), color, Standard_False);
        myContext->UpdateCurrentViewer();
    }
}

void DocumentCommon::onMaterial( int theMaterial )
{
    for ( myContext->InitSelected(); myContext->MoreSelected (); myContext->NextSelected () )
        myContext->SetMaterial( myContext->SelectedInteractive(), (Graphic3d_NameOfMaterial)theMaterial, Standard_False);
    myContext->UpdateCurrentViewer();
}

void DocumentCommon::onMaterial()
{
    DialogMaterial* m = new DialogMaterial();
    connect( m, SIGNAL( sendMaterialChanged( int ) ), this, SLOT( onMaterial( int ) ) );
    m->exec();
}

void DocumentCommon::onTransparency( int theTrans )
{
    for( myContext->InitSelected(); myContext->MoreSelected(); myContext->NextSelected() )
        myContext->SetTransparency (myContext->SelectedInteractive(), ((Standard_Real)theTrans) / 10.0, Standard_False);
    myContext->UpdateCurrentViewer();
}

void DocumentCommon::onTransparency()
{
    DialogTransparency* aDialog = new DialogTransparency();
    connect( aDialog, SIGNAL( sendTransparencyChanged( int ) ), this, SLOT( onTransparency( int ) ) );
    aDialog->exec();
}


void DocumentCommon::onImportSTPFile()
{
	QMdiArea* ws = myApp->getWorkspace();
	QMdiSubWindow* pTempMdiSubWin = ws->activeSubWindow();
	MDIWindow* window = qobject_cast<MDIWindow*>(ws->activeSubWindow()->widget());

	QString openFileName = QFileDialog::getOpenFileName(window, "ImportFile", "", "Import Files (*.stp *.step *.igs *iges)");
	if (openFileName.isEmpty())
	{
		return;
	}
	// �����ļ�ת��
	openFileName = ANSIFileConvertUtf8(openFileName);
	QFileInfo openFileInfo(openFileName);
	ws->setActiveSubWindow(pTempMdiSubWin);

	Handle(XCAFApp_Application) hApp = XCAFApp_Application::GetApplication();
	Handle(TDocStd_Document) hDoc;
	hApp->NewDocument(TCollection_ExtendedString("MDTV-CAF"), hDoc);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	if (openFileInfo.suffix() == QString("stp") || openFileInfo.suffix() == QString("STEP"))
	{
		STEPCAFControl_Reader aReader;
		aReader.SetColorMode(true);
		aReader.SetNameMode(true);
		aReader.SetLayerMode(true);
		if (aReader.ReadFile((const char*)(openFileName.toStdString().c_str())) != IFSelect_RetDone) {
			//PyErr_SetString(Base::BaseExceptionFreeCADError, "cannot read STEP file");
			QApplication::restoreOverrideCursor();
			QMessageBox::warning(window, QString(tr("Warning")), QString(tr("OpenFile is failed!")));
			return ;
		}

		//Handle_Message_ProgressIndicator pi = new Part::ProgressIndicator(100);
		//aReader.Reader().WS()->MapReader()->SetProgress(pi);
		//pi->NewScope(100, "Reading STEP file...");
		//pi->Show();
		aReader.Transfer(hDoc);
	}
	ImportOCAF ocaf(hDoc, this, openFileInfo.baseName().toStdString());
	ocaf.loadShapes();
	updatePartList();
	QApplication::restoreOverrideCursor();
}


void DocumentCommon::onSelectedModel()
{
	myContext->InitSelected();
	//Handle(AIS_Shape) S = Handle(AIS_Shape)::DownCast(myContext->Interactive());
	if (myContext->MoreSelected())
	{
		Handle(AIS_Shape) aSelInteractive = (Handle(AIS_Shape)::DownCast(myContext->SelectedInteractive()));
		if (aSelInteractive.IsNull())
		{
			qDebug() << "No AIS_Shape is selected!";
			return;
		}
		//getContext()->SetColor(aSelInteractive, Quantity_Color(Quantity_NOC_RED), false);

		for (myContext->InitSelected(); myContext->MoreSelected(); myContext->NextSelected())
		{
			const TopoDS_Shape& aSelShape = myContext->SelectedShape();
			m_selectedShape = aSelShape;
			TopAbs_ShapeEnum nShapeEnum = aSelShape.ShapeType();
			switch (nShapeEnum)
			{
			case TopAbs_COMPOUND:
				break;
			case TopAbs_COMPSOLID:
				break;
			case TopAbs_SOLID:
				break;
			case TopAbs_SHELL:
				break;
			case TopAbs_FACE:
				break;
			case TopAbs_WIRE:
				break;
			case TopAbs_EDGE:
			{
				TopoDS_Edge aSelEdge = TopoDS::Edge(myContext->SelectedShape().Located(TopLoc_Location()));
				Standard_Real first, second;
				Handle(Geom_Curve) aCurve = BRep_Tool::Curve(aSelEdge, first, second);
				Handle(Standard_Type) oType = aCurve->DynamicType();
				if (!oType.IsNull())
				{
					if (std::string(oType->Name()).compare(std::string("Geom_Circle")) == 0)
					{
						qDebug() << "Geom_Circle ";
						Handle(Geom_Circle) ipCurrentCircle = Handle(Geom_Circle)::DownCast(aCurve);
						gp_Ax1 aCircleAx = ipCurrentCircle->Axis();
						qDebug() << "aCircleAx Location: " << aCircleAx.Location().X() << aCircleAx.Location().Y() << aCircleAx.Location().Z();

					}
					if (std::string(oType->Name()).compare(std::string("Geom_Line")) == 0)
					{
						qDebug() << "Geom_Line ";
					}

				}
			}
				break;
			case TopAbs_VERTEX:
			{
				TopoDS_Vertex aSleVertex = TopoDS::Vertex(myContext->SelectedShape().Located(TopLoc_Location()));
				gp_Pnt p = BRep_Tool::Pnt(aSleVertex);
				Standard_Real dTolerance = BRep_Tool::Tolerance(aSleVertex);
				qDebug() << "Vertex position: (" << p.X() << ", " << p.Y() << ", " << p.Z() << ")";
				qDebug() << "Vertex Tolerance: " << dTolerance;
				//std::cout << "Vertex orientation: " << DumpOrientation(v.Orientation()) << std::endl;
			}
				break;
			case TopAbs_SHAPE:
				break;
			default:
				break;
			}
			
		}
	}
	else
	{
		m_selectedShape = TopoDS_Shape();
	}	
}


void DocumentCommon::onStartAnimation()
{
	m_TimerID = startTimer(16);

	m_CurrentFrame = 0;

}

void DocumentCommon::onStopAnimation()
{
	onKillTimer(m_TimerID);
}


void DocumentCommon::onKillTimer(int nID)
{
	m_CurrentFrame = 0;
	killTimer(nID);
}


void DocumentCommon::onResetLocation()
{
	QList<PartModel*> listCurrent = m_Project->getPartModelList();
	for (int nCurrent = 0; nCurrent < m_AISShapeList.size(); ++nCurrent)
	{
		Handle(AIS_Shape) ipCurrentAIS = m_AISShapeList.value(nCurrent);
		PartModel* pCurrentPartModel = listCurrent.at(nCurrent);
		gp_Trsf tempTrs = pCurrentPartModel->getPartModelOriginal();
		TopLoc_Location oCurrentLocation(tempTrs);

		myContext->SetLocation(ipCurrentAIS, oCurrentLocation);
		myContext->UpdateCurrentViewer();
	}

}

void DocumentCommon::onDelete()
{
    myContext->EraseSelected (Standard_False);
    myContext->ClearSelected (Standard_False);
    myContext->UpdateCurrentViewer();
    getApplication()->onSelectionChanged();
}
