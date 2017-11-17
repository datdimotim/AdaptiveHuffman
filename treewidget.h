#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include<QLabel>

#include "treeview.h"
#include "codetree.h"

class TreeWidget : public QWidget{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = 0);

public slots:
    void insert();
    void next();
    void back();

private:
    TreeView *view_;
    QLineEdit *lineEdit_;
    QPushButton *button_;
    QLabel *code ;

    std::vector<code_tree::State*> states;
    int stateIndex=0;
};

#endif // TREEWIDGET_H
