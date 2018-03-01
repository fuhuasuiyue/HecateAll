#ifndef MDIWINDOW_H
#define MDIWINDOW_H

#include <QMainWindow>
#include "lzwmodeltree.h"
#include "PartModel.h"
#include "PartPropertyForm.h"

class DocumentCommon;
class View;

class MDIWindow: public QMainWindow
{
    Q_OBJECT

public:
  MDIWindow( DocumentCommon* aDocument, QWidget* parent, Qt::WindowFlags wflags );
  MDIWindow( View* aView, DocumentCommon* aDocument, QWidget* parent, Qt::WindowFlags wflags );
  ~MDIWindow();

	DocumentCommon*            getDocument();
	void                       fitAll();
  virtual QSize              sizeHint() const;
  View*						getView();
  void setModelTree(QList<PartModel*> partModelList);

signals:
  void                       selectionChanged();
  void                       message(const QString&, int );
	void                       sendCloseView(MDIWindow* theView);

public slots:
  void                       closeEvent(QCloseEvent* e);        
  void                       onWindowActivated ();
  void                       dump();


protected:
  void                       createViewActions();
  void                       createRaytraceActions();
  void initDockWidget();

protected:
  DocumentCommon*            myDocument;
  View*                      myView;
  lzwModelTree *m_Modeltree;
  PartPropertyForm* m_PartPropertyForm;
};

#endif