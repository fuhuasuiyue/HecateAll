#pragma once

#include <QtWidgets/QMainWindow>
#include <QtitanRibbon.h>
#include <QAction>
#include <QToolBar>
#include <QMenu>
#include <QMdiArea>
#include <QList>
#include <QComboBox>

#include "DocumentCommon.h"

class ApplicationCommonWindow : public Qtitan::RibbonMainWindow
{
	Q_OBJECT
public:
	enum { FileNewId, FilePrefUseVBOId, FileCloseId, FilePreferencesId, FileQuitId, ViewToolId, ViewStatusId, HelpAboutId };
	enum { ToolWireframeId, ToolShadingId, ToolColorId, ToolMaterialId, ToolTransparencyId, ToolDeleteId };

public:
	ApplicationCommonWindow(QWidget *parent = Q_NULLPTR);
	~ApplicationCommonWindow();
	static QMdiArea*				getWorkspace();
	static ApplicationCommonWindow* getApplication();
	static QString                  getResourceDir();

	virtual void                     updateFileActions();
	QList<QAction*>*                 getToolActions();
	QList<QAction*>*                 getMaterialActions();

protected:
	virtual DocumentCommon*          createNewDocument();
	int&                             getNbDocument();

public slots:

	DocumentCommon*                 onNewDoc();
	void                            onCloseWindow();
	void                            onUseVBO();
	virtual void                    onCloseDocument(DocumentCommon* theDoc);
	virtual void                    onSelectionChanged();
	virtual void                    onAbout();
	void                            onViewToolBar();
	void                            onViewStatusBar();
	void                            onToolAction();
	void                            onCreateNewView();
	void                            onWindowActivated(QWidget * w);
	void                            windowsMenuAboutToShow();
	void                            windowsMenuActivated(bool checked/*int id*/);
	void                            onSetMaterial(int theMaterial);
	void							onCreateOCCBottle();
	void onImportStepFile();
	void onMotionCalculator();
	void onStartAnimation();
	void onStopAnimation();
	void onResetAnimation();
	void onSelectedID(int selectdID);

protected:
	virtual void                    resizeEvent(QResizeEvent*);
	bool                            isDocument();
	QList<QAction *>                getFilePopup();
	QAction*                        getFileSeparator();
	QToolBar*                       getCasCadeBar();

private:
	void                            createStandardOperations();
	void                            createCasCadeOperations();
	void                            createWindowPopup();
	void							createMenuFile();
	void							createRibbon();
	void							createGroupClipboard(Qtitan::RibbonPage* page);
	void createGroupSimulation(Qtitan::RibbonPage* page);

private:
	int                             myNbDocuments;
	bool                            myIsDocuments;

	QList<QAction*>                 myStdActions;
	QList<QAction*>                 myToolActions;
	QList<QAction*>                 myMaterialActions;

	QToolBar*                       myStdToolBar;
	QToolBar*                       myCasCadeBar;
	QList<QAction *>                myFilePopup;
	QMenu*                          myWindowPopup;
	QAction*                        myFileSeparator;

protected:
	QList<DocumentCommon*>          myDocuments;
	Qtitan::RibbonStyle* m_ribbonStyle;
	QComboBox* m_SelectedID;

private:
};
