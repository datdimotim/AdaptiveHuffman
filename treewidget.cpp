#include "treewidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include<QRegExpValidator>


TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent){
    view_ = new TreeView(this);
    view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel *label = new QLabel("Введите сообщение: ");
    lineEdit_ = new QLineEdit();

    QRegExp rx("[a-z]{0,26}");
    QValidator *validator = new QRegExpValidator(rx, this);
    lineEdit_->setValidator(validator);


    button_ = new QPushButton("Кодировать");

    QPushButton* back=new QPushButton("Предыдущий шаг");
    QPushButton* next=new QPushButton("Следующий шаг");
    QLabel *step = new QLabel("Номер шага = 0");
    code = new QLabel("Код: ");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit_);
    layout->addWidget(button_);

    QHBoxLayout *infLayout=new QHBoxLayout;
    infLayout->addWidget(back);
    infLayout->addWidget(step);
    infLayout->addWidget(next);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    mainLayout->addLayout(infLayout);
    mainLayout->addWidget(code);
    mainLayout->addWidget(view_);


    setLayout(mainLayout);

    connect(button_, &QPushButton::clicked, this, &TreeWidget::insert);
    connect(next, &QPushButton::clicked, this, &TreeWidget::next);
    connect(back, &QPushButton::clicked, this, &TreeWidget::back);

    insert();
}

void TreeWidget::next(){
    if(states.size()-1<=stateIndex)return;
    view_->setTree(states[++stateIndex]->root);
    update();
}

void TreeWidget::back(){
    if(stateIndex<1)return;
    view_->setTree(states[--stateIndex]->root);
    update();
}

void TreeWidget::insert(){
    stateIndex=0;
    char* str = new char[lineEdit_->text().length()+1];
    (*str)='\0';
    strcpy(str,lineEdit_->text().toLatin1().data());
    code_tree::demoEncode(states,str);
    view_->setTree(states[stateIndex]->root);
    code->setText(str);
    delete[] str;
    update();
}
