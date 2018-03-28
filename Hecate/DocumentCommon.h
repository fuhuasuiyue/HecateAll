#ifndef DOCUMENTCOMMON_H
#define DOCUMENTCOMMON_H

#include "MDIWindow.h"
//#include "IESample.h"

#include <QObject>
#include <QList>

#include <AIS_InteractiveContext.hxx>
#include <V3d_Viewer.hxx>
#include "PartModel.h"
#include "AIS_Shape.hxx"
#include "HCProject.h"

class ApplicationCommonWindow;

class DocumentCommon : public QObject
{
	Q_OBJECT

public:
	DocumentCommon( const int, ApplicationCommonWindow* );
	~DocumentCommon();

	ApplicationCommonWindow*       getApplication();
	Handle(AIS_InteractiveContext) getContext();
	void                           removeView( MDIWindow* );
	void                           removeViews();
	int                            countOfWindow();
	void                           fitAll();
	void                           onMakeBottle();
	void makeAixs();
	void updatePartList();
	HCProject* getProject();
	QList<PartModel*> getPartModelList();
	void setSelectType(TopAbs_ShapeEnum typeID);
	TopAbs_ShapeEnum getSelectType();
	QString ANSIFileConvertUtf8(QString fileName);
	TopoDS_Shape &getSelectShape();

protected:
	virtual MDIWindow* createNewMDIWindow();

signals:
	void                           selectionChanged();
	void                           sendCloseDocument( DocumentCommon* );

public slots:
	virtual void                   onCloseView( MDIWindow* );
	virtual void                   onCreateNewView();
	virtual void                   onMaterial();
	virtual void                   onMaterial( int );
	virtual void                   onDelete();

	void                           onWireframe();
	void                           onShading();
	void                           onColor();
	void                           onTransparency();
	void                           onTransparency( int );
	void onImportSTPFile();
	void onSelectedModel();
	void onStartAnimation();
	void onStopAnimation();
	void onKillTimer(int nID);
	void onResetLocation();
private:
	Handle(V3d_Viewer)             Viewer (const Standard_ExtString theName,
                                         const Standard_CString theDomain,
                                         const Standard_Real theViewSize,
                                         const V3d_TypeOfOrientation theViewProj,
                                         const Standard_Boolean theComputedMode,
                                         const Standard_Boolean theDefaultComputedMode );

	virtual void timerEvent(QTimerEvent *event) override;

protected:
	ApplicationCommonWindow*       myApp;
	QList<MDIWindow*>              myViews;
	Handle(V3d_Viewer)             myViewer;
	Handle(AIS_InteractiveContext) myContext;
	int                            myIndex;
	int                            myNbViews;
	HCProject *m_Project;
	//QList<PartModel*> m_partModelList;
	QList<Handle(AIS_Shape)> m_AISShapeList;
	int m_TimerID;
	int m_CurrentFrame;
	TopAbs_ShapeEnum m_SelectEnum;
	TopoDS_Shape m_selectedShape;
};

#endif


