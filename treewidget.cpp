#include "treewidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent){
    view_ = new TreeView(this);
    view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    view_->setTree(data);

    QLabel *label = new QLabel("Введите элемент: ");
    lineEdit_ = new QLineEdit();
    button_ = new QPushButton("Добавить");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit_);
    layout->addWidget(button_);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view_);
    mainLayout->addLayout(layout);

    setLayout(mainLayout);

    connect(button_, &QPushButton::clicked, this, &TreeWidget::insert);
}

void TreeWidget::insert(){
    bool ok;
    int value = lineEdit_->text().toInt(&ok);
    if (ok == false) {
        QMessageBox::warning(this, "Вставка в бинарное дерево",
                             "Вы ввели не число!",
                             QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    data=BinTree::insert(data,value);
    view_->setTree(data);
    update();
}

