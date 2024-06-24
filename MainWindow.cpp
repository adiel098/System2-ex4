// mainwindow.cpp
#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Initialize QGraphicsView to display the tree
    treeView = new QGraphicsView(this);
    setCentralWidget(treeView);

    // Create a sample tree and draw it
    Tree<double> tree(2); // Example binary tree
    tree.add_root(1);
    Node<double>* root = tree.get_root_node();
    tree.add_sub_node(root, new Node<double>(2));
    tree.add_sub_node(root, new Node<double>(3));
    drawTree(tree);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::drawTree(Tree<double>& tree) {
    QGraphicsScene *scene = new QGraphicsScene(this);
    treeView->setScene(scene);

    std::function<void(Node<double>*, int, int, int)> drawNode = [&](Node<double>* node, int x, int y, int offset) {
        if (!node) return;
        scene->addEllipse(x, y, 30, 30, QPen(), QBrush(Qt::SolidPattern))->setToolTip(QString::number(node->data));
        if (!node->children.empty()) {
            int childX = x - offset;
            for (auto child : node->children) {
                scene->addLine(x + 15, y + 30, childX + 15, y + 80);
                drawNode(child, childX, y + 80, offset / 2);
                childX += offset;
            }
        }
    };

    drawNode(tree.get_root_node(), 400, 0, 200); // Start drawing from root
}