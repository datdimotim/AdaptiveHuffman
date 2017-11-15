#include "treeview.h"

#include <QPainter>
#include <QFontMetrics>

TreeView::TreeView(QWidget *parent): QWidget(parent), tree(nullptr){}

void TreeView::setTree(const code_tree::Node* tree){
    this->tree = tree;
    update();
}

void TreeView::paintEvent(QPaintEvent *){
    QPainter painter(this);
    drawNode(&painter, tree, 0, 0);
}

void TreeView::drawNode(QPainter *painter, const code_tree::Node* root, int x, int y){
    if(root==nullptr)return;

    painter->save();
    QPoint p(width() / pow(2, y) * x + width() / pow(2, y+1), nodeHeight * y);

    // circle
    QRect rec(p.x() - nodeWidth/4, p.y(), nodeWidth/2, nodeHeight/2);
    painter->setPen(Qt::blue);
    painter->drawRect(rec);
    painter->setPen(Qt::red);

    QFont font = painter->font() ;
    font.setPointSize(10);
    painter->setFont(font);

    QString text = fontMetrics().elidedText(
                QString::asprintf("%c\n%d",root->symbol,root->weight),
                Qt::ElideLeft, rec.width());
    painter->drawText(rec, Qt::AlignCenter, text);

    // lines
    painter->setPen(Qt::blue);
    if(root->left != nullptr) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() - width()/pow(2, y+2), p.y() + nodeHeight);
    }

    if(root->right != nullptr) {
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() + width()/pow(2, y+2), p.y() + nodeHeight);
    }
    painter->restore();

    // childs
    if(root->left != nullptr)drawNode(painter, root->left, 2*x, y+1);
    if(root->right != nullptr)drawNode(painter, root->right, 2*x + 1, y+1);
}
