#ifndef LZWMODELTREE_H
#define LZWMODELTREE_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMouseEvent>
#include "PartModel.h"

class lzwModelTree : public QTreeWidget
{
    Q_OBJECT
public:
    explicit lzwModelTree(QWidget *parent = 0);
    virtual ~lzwModelTree();
    void addModel(PartModel* pPartModel);

signals:

public slots:

private:
    QTreeWidgetItem *modelNode;


    // QWidget interface
protected:

};

#endif // LZWMODELTREE_H
