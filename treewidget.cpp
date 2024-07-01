//id:207988213,email:haleviadiel@gmail.com

#include "treewidget.h"
#include <QPainter>
#include "Node.hpp"
#include "Tree.hpp"
TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent), tree(nullptr) {}

void TreeWidget::setTree(Tree<double> *tree) {
    this->tree = tree;
    update();
}

void TreeWidget::paintEvent(QPaintEvent *event) {
    if (!tree) return;

    QPainter painter(this);
    auto root = tree->get_root_node();
    if (root) {
        drawNode(painter, root, width() / 2, 30, 1);
    }
}

void TreeWidget::drawNode(QPainter &painter, Node<double> *node, int x, int y, int level) {
    if (!node) return;

    int hSpacing = 60 / level;
    int vSpacing = 50;

    painter.drawEllipse(x - 15, y - 15, 30, 30);
    painter.drawText(x - 10, y + 5, QString::number(node->data));

    int childX = x - (node->children.size() - 1) * hSpacing / 2;
    for (auto child : node->children) {
        painter.drawLine(x, y + 15, childX, y + vSpacing);
        drawNode(painter, child, childX, y + vSpacing, level + 1);
        childX += hSpacing;
    }
}
