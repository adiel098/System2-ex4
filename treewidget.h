#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "Tree.hpp"

class TreeWidget : public QWidget {
    Q_OBJECT

public:
    TreeWidget(QWidget *parent = nullptr);
    void setTree(Tree<double> *tree);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawNode(QPainter &painter, Node<double> *node, int x, int y, int level);

    Tree<double> *tree;
};

#endif // TREEWIDGET_H
