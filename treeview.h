#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QWidget>

#include "codetree.h"

class TreeView : public QWidget{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = 0);
    void setTree(const code_tree::BT* data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawNode(QPainter *painter, const code_tree::BT* root, int x, int y);
    const code_tree::BT* tree;
    const int nodeWidth{ 80 };
    const int nodeHeight{ 80 };
};

#endif // TREEVIEW_H
