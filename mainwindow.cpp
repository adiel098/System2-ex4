#include "mainwindow.h"
#include <QVBoxLayout>
#include "Node.hpp"
#include "Tree.hpp"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    treeWidget = new TreeWidget(this);
    setCentralWidget(treeWidget);
    this->resize(1024, 768); // Width: 1024, Height: 768
    tree = new Tree<double>(2); // Initialize with k = 2
    tree->add_root(5.2);

    auto root = tree->get_root_node();
    auto child1 = new Node<double>(1.2);
    auto child2 = new Node<double>(1.3);

    auto grandchild1 = new Node<double>(1.4);
    auto grandchild2 = new Node<double>(1.5);
    auto grandchild3 = new Node<double>(1.5);

    tree->add_sub_node(root, child1);
    tree->add_sub_node(root, child2);
    tree->add_sub_node(child2, grandchild3);

    tree->add_sub_node(child1, grandchild1);
    tree->add_sub_node(child1, grandchild2);

    treeWidget->setTree(tree);
}

MainWindow::~MainWindow() {
    delete tree;
}
