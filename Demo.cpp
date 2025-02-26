//id:207988213,email:haleviadiel@gmail.com
#include "Node.hpp"
#include "Complex.hpp"
#include "Tree.hpp"
#include <iostream>
using namespace std;

int main() {
    try {
        Tree<double> tree;
        cout << "k: " << tree.getK() << endl;
        tree.add_root(5.2);
        cout << "Root: " << tree.get_root() << endl;
        
        auto root = tree.get_root_node();
        auto child1 = new Node<double>(1.2);
        auto child2 = new Node<double>(1.3);

        auto grandchild1 = new Node<double>(1.4);
        auto grandchild2 = new Node<double>(1.5);

        tree.add_sub_node(root, child1);
        tree.add_sub_node(root, child2);

        tree.add_sub_node(child1, grandchild1);
        tree.add_sub_node(child1, grandchild2);

        auto it = tree.begin_pre_order();
        auto end = tree.end_pre_order();

        std::cout << "Preorder Traversal: ";
        for (; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        auto post_it = tree.begin_post_order();
        auto post_end = tree.end_post_order();

        std::cout << "Postorder Traversal: ";
        for (; post_it != post_end; ++post_it) {
            std::cout << *post_it << " ";
        }
        std::cout << std::endl;

        auto in_it = tree.begin_in_order();
        auto in_end = tree.end_in_order();

        std::cout << "Inorder Traversal: "<< endl;
        for (; in_it != in_end; ++in_it) {
            std::cout << *in_it << " ";
        }
        std::cout << std::endl;

        auto bfs_it = tree.begin_bfs_scan();
        auto bfs_end = tree.end_bfs_scan();

        std::cout << "BFS Traversal: "<<endl;
        for (; bfs_it != bfs_end; ++bfs_it) {
            std::cout << *bfs_it << " ";
        }
        std::cout << std::endl;

        auto dfs_it = tree.begin_dfs_scan();
        auto dfs_end = tree.end_dfs_scan();

        std::cout << "DFS Traversal: " <<endl;
        for (; dfs_it != dfs_end; ++dfs_it) {
            std::cout << *dfs_it << " ";
        }
        std::cout << std::endl;

        // Converting the tree to a minimal heap
        std::cout << "Converting the tree to a minimal heap..." << std::endl;
        tree.myHeap();

        // Print the tree structure after converting to minimal heap
        bfs_it = tree.begin_bfs_scan();
        bfs_end = tree.end_bfs_scan();

        std::cout << "BFS Traversal after converting to minimal heap: "<<endl;
        for (; bfs_it != bfs_end; ++bfs_it) {
            std::cout << *bfs_it << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
    Tree<int> treeInt;
        cout << "k: " << treeInt.getK() << endl;
        treeInt.add_root(1);
        cout << "Root: " << treeInt.get_root() << endl;
        
        auto root = treeInt.get_root_node();
        auto child1 = new Node<int>(2);
        auto child2 = new Node<int>(3);

        auto grandchild1 = new Node<int>(4);
        auto grandchild2 = new Node<int>(5);

        treeInt.add_sub_node(root, child1);
        treeInt.add_sub_node(root, child2);

        treeInt.add_sub_node(child1, grandchild1);
        treeInt.add_sub_node(child1, grandchild2);

        auto it = treeInt.begin_pre_order();
        auto end = treeInt.end_pre_order();

        std::cout << "Preorder Traversal: ";
        for (; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        auto post_it = treeInt.begin_post_order();
        auto post_end = treeInt.end_post_order();

        std::cout << "Postorder Traversal: ";
        for (; post_it != post_end; ++post_it) {
            std::cout << *post_it << " ";
        }
        std::cout << std::endl;

        auto in_it = treeInt.begin_in_order();
        auto in_end = treeInt.end_in_order();

        std::cout << "Inorder Traversal: "<< endl;
        for (; in_it != in_end; ++in_it) {
            std::cout << *in_it << " ";
        }
        std::cout << std::endl;

        auto bfs_it = treeInt.begin_bfs_scan();
        auto bfs_end = treeInt.end_bfs_scan();

        std::cout << "BFS Traversal: "<<endl;
        for (; bfs_it != bfs_end; ++bfs_it) {
            std::cout << *bfs_it << " ";
        }
        std::cout << std::endl;

        auto dfs_it = treeInt.begin_dfs_scan();
        auto dfs_end = treeInt.end_dfs_scan();

        std::cout << "DFS Traversal: " <<endl;
        for (; dfs_it != dfs_end; ++dfs_it) {
            std::cout << *dfs_it << " ";
        }
        std::cout << std::endl;

        // Converting the tree to a minimal heap
        std::cout << "Converting the tree to a minimal heap..." << std::endl;
        treeInt.myHeap();

        // Print the tree structure after converting to minimal heap
        bfs_it = treeInt.begin_bfs_scan();
        bfs_end = treeInt.end_bfs_scan();

        std::cout << "BFS Traversal after converting to minimal heap: "<<endl;
        for (; bfs_it != bfs_end; ++bfs_it) {
            std::cout << *bfs_it << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Tree<Complex> tree;
        cout << "k: " << tree.getK() << endl;
        tree.add_root(Complex(5.2, 1.0));
        cout << "Root: " << tree.get_root() << endl;
        
        auto root = tree.get_root_node();
        auto child1 = new Node<Complex>(Complex(1.2, 2.0));
        auto child2 = new Node<Complex>(Complex(1.3, 3.0));

        auto grandchild1 = new Node<Complex>(Complex(1.4, 4.0));
        auto grandchild2 = new Node<Complex>(Complex(1.5, 5.0));

        tree.add_sub_node(root, child1);
        tree.add_sub_node(root, child2);

        tree.add_sub_node(child1, grandchild1);
        tree.add_sub_node(child1, grandchild2);

        auto it = tree.begin_pre_order();
        auto end = tree.end_pre_order();

        std::cout << "Preorder Traversal: ";
        for (; it != end; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        auto post_it = tree.begin_post_order();
        auto post_end = tree.end_post_order();

        std::cout << "Postorder Traversal: ";
        for (; post_it != post_end; ++post_it) {
            std::cout << *post_it << " ";
        }
        std::cout << std::endl;

        auto in_it = tree.begin_in_order();
        auto in_end = tree.end_in_order();

        std::cout << "Inorder Traversal: "<< endl;
        for (; in_it != in_end; ++in_it) {
            std::cout << *in_it << " ";
        }
        std::cout << std::endl;

        auto bfs_it = tree.begin_bfs_scan();
        auto bfs_end = tree.end_bfs_scan();

        std::cout << "BFS Traversal: "<<endl;
        for (; bfs_it != bfs_end; ++bfs_it) {
            std::cout << *bfs_it << " ";
        }
        std::cout << std::endl;

        auto dfs_it = tree.begin_dfs_scan();
        auto dfs_end = tree.end_dfs_scan();

        std::cout << "DFS Traversal: " <<endl;
        for (; dfs_it != dfs_end; ++dfs_it) {
            std::cout << *dfs_it << " ";
        }
        std::cout << std::endl;

        // Converting the tree to a minimal heap
        std::cout << "Converting the tree to a minimal heap..." << std::endl;
        tree.myHeap();

        // Print the tree structure after converting to minimal heap
        bfs_it = tree.begin_bfs_scan();
        bfs_end = tree.end_bfs_scan();

        std::cout << "BFS Traversal after converting to minimal heap: "<<endl;
        for (; bfs_it != bfs_end; ++bfs_it) {
            std::cout << *bfs_it << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
