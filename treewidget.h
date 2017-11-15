#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

#include "treeview.h"
#include "codetree.h"

class TreeWidget : public QWidget{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = 0);

public slots:
    void insert();

private:
    TreeView *view_;
    QLineEdit *lineEdit_;
    QPushButton *button_;
    code_tree::Node* root;
    code_tree::DemoTree* data=new code_tree::DemoTree();
};

#endif // TREEWIDGET_H
