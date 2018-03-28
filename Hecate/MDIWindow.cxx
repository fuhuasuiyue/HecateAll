#include "MDIWindow.h"

#include "View.h"
#include "DocumentCommon.h"
#include "ApplicationCommon.h"

#include <QFrame>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow> 
#include <QVBoxLayout>
#include <QDockWidget>
#include "HCGUIHinge.h"

MDIWindow::MDIWindow(View* aView,
                     DocumentCommon* aDocument, 
                     QWidget* parent, 
                     Qt::WindowFlags wflags )
: QMainWindow( parent, wflags ),
m_GUIHinge(new HCGUIHinge(this))
{
  myView = aView;
  myDocument = aDocument;
  initDockWidget();
}

MDIWindow::MDIWindow( DocumentCommon* aDocument, QWidget* parent, Qt::WindowFlags wflags)
	: QMainWindow(parent, wflags),
	m_GUIHinge(new HCGUIHinge(this))
{
  QFrame *vb = new QFrame( this );
  QVBoxLayout *layout = new QVBoxLayout( vb );
  layout->setMargin( 0 );

  vb->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );

  setCentralWidget( vb );

  myDocument = aDocument;
  myView = new View (myDocument->getContext(), vb);
  layout->addWidget (myView);

  connect( myView, SIGNAL( selectionChanged() ),
           this,   SIGNAL( selectionChanged() ) );

  createViewActions();
  createRaytraceActions();

  resize( sizeHint() );

  initDockWidget();
  setFocusPolicy( Qt::StrongFocus );
}

MDIWindow::~MDIWindow()
{
}

DocumentCommon* MDIWindow::getDocument()
{
  return myDocument;
}

void MDIWindow::closeEvent(QCloseEvent* )
{
  emit sendCloseView(this);
}

void MDIWindow::fitAll()
{
  myView->fitAll();
}

void MDIWindow::createViewActions()
{
  // populate a tool bar with some actions
  QToolBar* aToolBar = addToolBar( tr( "View Operations" ) );
  
  QList<QAction*>* aList = myView->getViewActions();
  aToolBar->addActions( *aList );

  aToolBar->toggleViewAction()->setVisible(false);
  aList->at(View::ViewHlrOffId)->setChecked( true );
}

void MDIWindow::createRaytraceActions()
{
  // populate a tool bar with some actions
  QToolBar* aToolBar = addToolBar( tr( "Ray-tracing Options" ) );
  
  QList<QAction*>* aList = myView->getRaytraceActions();
  aToolBar->addActions( *aList );

  aToolBar->toggleViewAction()->setVisible (true);
  aList->at (View::ToolRaytracingId)->setChecked (false);
  aList->at (View::ToolShadowsId)->setChecked (true);
  aList->at (View::ToolReflectionsId)->setChecked (false);
  aList->at (View::ToolAntialiasingId)->setChecked (false);
}


void MDIWindow::initDockWidget()
{
	//QWidget *ut = new QWidget(this);
	QDockWidget *dock = new QDockWidget(QString().fromLocal8Bit("模型窗口"),this);

	
	//dock->setTitleBarWidget(ut);
	m_Modeltree = new lzwModelTree(this);
	dock->setAllowedAreas(Qt::AllDockWidgetAreas);
	dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
	dock->setWidget(m_Modeltree);
	addDockWidget(Qt::LeftDockWidgetArea, dock);

	QDockWidget *pPropertyDock = new QDockWidget(QString().fromLocal8Bit("属性窗口"),this);
	m_PartPropertyForm = new PartPropertyForm(this);
	m_PartPropertyForm->setMinimumWidth(200);
	pPropertyDock->setAllowedAreas(Qt::AllDockWidgetAreas);
	pPropertyDock->setFeatures(QDockWidget::AllDockWidgetFeatures/*| QDockWidget::DockWidgetVerticalTitleBar*/);
	pPropertyDock->setWidget(m_PartPropertyForm);
	addDockWidget(Qt::RightDockWidgetArea, pPropertyDock);
	tabifyDockWidget(dock, pPropertyDock);

}

void MDIWindow::onWindowActivated()
{
  getDocument()->getApplication()->onSelectionChanged();
}

void MDIWindow::dump()
{
  QString datadir = (QString(qgetenv ("CSF_OCCTDataPath").constData()) + "/images");
  QString filter = "Images Files (*.bmp *.ppm *.png *.jpg *.tiff *.tga *.gif *.exr)";
  QFileDialog fd ( 0 );
  fd.setModal( true );
  fd.setNameFilter ( filter );
  fd.setWindowTitle( QObject::tr("INF_APP_EXPORT") );
  fd.setFileMode( QFileDialog::AnyFile );
  int ret = fd.exec(); 

  /* update the desktop after the dialog is closed */
  qApp->processEvents();

  QStringList fileNames;
  fileNames = fd.selectedFiles();

  QString file ( (ret == QDialog::Accepted && !fileNames.isEmpty() )? fileNames[0] : QString::null);
  if ( !file.isNull() )
  {
    QApplication::setOverrideCursor( Qt::WaitCursor );
    if ( !QFileInfo( file ).completeSuffix().length() )
      file += QString( ".bmp" );

    const TCollection_AsciiString anUtf8Path (file.toUtf8().data());

    bool res = myView->dump( anUtf8Path.ToCString() );
    QApplication::restoreOverrideCursor();                
    if ( !res )
    {
      QWidgetList list = qApp->allWidgets();
      QWidget* mainWidget = NULL;
      for( int i = 0; i < list.size(); ++i )
      {
        if( qobject_cast<ApplicationCommonWindow*>( list.at( i ) ) )
        mainWidget = qobject_cast<ApplicationCommonWindow*>( list.at( i ) );
      }

      QMessageBox::information ( mainWidget, QObject::tr("TIT_ERROR"), QObject::tr("INF_ERROR"), QObject::tr("BTN_OK"),
                                 QString::null, QString::null, 0, 0 );
      qApp->processEvents();
    }
  }
}


void MDIWindow::onHingeConstraint()
{
	m_GUIHinge->show();
	
	
}

void MDIWindow::setModelTree(QList<PartModel*> partModelList)
{
	if (partModelList.isEmpty())
	{
		return;
	}
	for (int nCurrent = 0; nCurrent < partModelList.size(); ++nCurrent)
	{
		PartModel* pCurrentPart = partModelList.value(nCurrent);
		m_Modeltree->addModel(pCurrentPart);
	}
}

QSize MDIWindow::sizeHint() const
{
  return QSize( 450, 300 );
}

View* MDIWindow::getView()
{
	return myView;
}
