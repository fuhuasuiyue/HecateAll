#ifndef DOCUMENTCOMMON_H
#define DOCUMENTCOMMON_H

#include "MDIWindow.h"
//#include "IESample.h"

#include <QObject>
#include <QList>

#include <AIS_InteractiveContext.hxx>
#include <V3d_Viewer.hxx>
#include "PartModel.h"

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
	PartModel* addPartModel();
	PartModel* getPartModel(TopoDS_Shape selectedShape);
	int getUniquePartModelID(int partID);
	void updatePartList();
	QList<PartModel*> getPartModelList();
	
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
private:
	Handle(V3d_Viewer)             Viewer (const Standard_ExtString theName,
                                         const Standard_CString theDomain,
                                         const Standard_Real theViewSize,
                                         const V3d_TypeOfOrientation theViewProj,
                                         const Standard_Boolean theComputedMode,
                                         const Standard_Boolean theDefaultComputedMode );

protected:
	ApplicationCommonWindow*       myApp;
	QList<MDIWindow*>              myViews;
	Handle(V3d_Viewer)             myViewer;
	Handle(AIS_InteractiveContext) myContext;
	int                            myIndex;
	int                            myNbViews;
	QList<PartModel*> m_partModelList;
};

#endif


