#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QWidget>

#include "bintree.h"

class TreeView : public QWidget{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = 0);
    void setTree(const BinTree *data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawNode(QPainter *painter, const BinTree* root, int x, int y);
    const BinTree* tree;
    const int nodeWidth{ 100 };
    const int nodeHeight{ 100 };
};

#endif // TREEVIEW_H
