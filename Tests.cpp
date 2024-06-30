#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>

TEST_CASE("Test Preorder traversal for k <= 2 with grandchildren") {
    Tree<int> tree(2);
    tree.add_root(10);
    auto root = tree.get_root_node();
    auto child1 = new Node<int>(20);
    auto child2 = new Node<int>(30);
    auto grandchild1 = new Node<int>(40);
    auto grandchild2 = new Node<int>(50);

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);

    auto it = tree.begin_pre_order();
    auto end = tree.end_pre_order();
    std::vector<int> preorder_values;
    for (; it != end; ++it) {
        preorder_values.push_back(*it);
    }
    std::vector<int> expected_preorder = {10, 20, 40, 50, 30};
    CHECK(preorder_values == expected_preorder);
}



TEST_CASE("Test Inorder traversal for k <= 2 with grandchildren") {
    Tree<int> tree(2);
    tree.add_root(10);
    auto root = tree.get_root_node();
    auto child1 = new Node<int>(20);
    auto child2 = new Node<int>(30);
    auto grandchild1 = new Node<int>(40);
    auto grandchild2 = new Node<int>(50);

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);

    auto it = tree.begin_in_order();
    auto end = tree.end_in_order();
    std::vector<int> inorder_values;
    for (; it != end; ++it) {
        inorder_values.push_back(*it);
    }
    std::vector<int> expected_inorder = {40, 20, 50, 10, 30};
    CHECK(inorder_values == expected_inorder);
}

TEST_CASE("Test BFS traversal for k > 2 with grandchildren") {
    Tree<int> tree(3);
    tree.add_root(10);
    auto root = tree.get_root_node();
    auto child1 = new Node<int>(20);
    auto child2 = new Node<int>(30);
    auto child3 = new Node<int>(40);
    auto grandchild1 = new Node<int>(50);
    auto grandchild2 = new Node<int>(60);

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(root, child3);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);

    auto it = tree.begin_bfs_scan();
    auto end = tree.end_bfs_scan();
    std::vector<int> bfs_values;
    for (; it != end; ++it) {
        bfs_values.push_back(*it);
    }
    std::vector<int> expected_bfs = {10, 20, 30, 40, 50, 60};
    CHECK(bfs_values == expected_bfs);
}

TEST_CASE("Test DFS traversal for k <= 2 with complex numbers") {
    Tree<Complex> tree(2);
    tree.add_root(Complex(1, 1));
    auto root = tree.get_root_node();
    auto child1 = new Node<Complex>(Complex(2, 2));
    auto child2 = new Node<Complex>(Complex(3, 3));

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);

    auto it = tree.begin_dfs_scan();
    auto end = tree.end_dfs_scan();
    std::vector<Complex> dfs_values;
    for (; it != end; ++it) {
        dfs_values.push_back(*it);
    }
    std::vector<Complex> expected_dfs = {Complex(1, 1), Complex(2, 2), Complex(3, 3)};
    CHECK(dfs_values == expected_dfs);
}

TEST_CASE("Test Postorder traversal for k <= 2 with multiple levels of grandchildren") {
    Tree<int> tree(2);
    tree.add_root(1);
    auto root = tree.get_root_node();
    auto child1 = new Node<int>(2);
    auto child2 = new Node<int>(3);
    auto grandchild1 = new Node<int>(4);
    auto grandchild2 = new Node<int>(5);
    auto greatgrandchild1 = new Node<int>(6);

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);
    tree.add_sub_node(grandchild1, greatgrandchild1);

    auto it = tree.begin_post_order();
    auto end = tree.end_post_order();
    std::vector<int> postorder_values;
    for (; it != end; ++it) {
        postorder_values.push_back(*it);
    }
    std::vector<int> expected_postorder = {6, 4, 5, 2, 3, 1};
    CHECK(postorder_values == expected_postorder);
}



TEST_CASE("Test BFS traversal for k <= 2 with multiple grandchildren") {
    Tree<int> tree(2);
    tree.add_root(1);
    auto root = tree.get_root_node();
    auto child1 = new Node<int>(2);
    auto child2 = new Node<int>(3);
    auto grandchild1 = new Node<int>(4);
    auto grandchild2 = new Node<int>(5);

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);

    auto it = tree.begin_bfs_scan();
    auto end = tree.end_bfs_scan();
    std::vector<int> bfs_values;
    for (; it != end; ++it) {
        bfs_values.push_back(*it);
    }
    std::vector<int> expected_bfs = {1, 2, 3, 4, 5};
    CHECK(bfs_values == expected_bfs);
}

TEST_CASE("Test tree with complex numbers and multiple iterators") {
    Tree<Complex> tree(2);
    tree.add_root(Complex(1, 1));
    auto root = tree.get_root_node();
    auto child1 = new Node<Complex>(Complex(2, 2));
    auto child2 = new Node<Complex>(Complex(3, 3));
    auto grandchild1 = new Node<Complex>(Complex(4, 4));
    auto grandchild2 = new Node<Complex>(Complex(5, 5));

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);

    SUBCASE("Preorder traversal") {
        auto it = tree.begin_pre_order();
        auto end = tree.end_pre_order();
        std::vector<Complex> preorder_values;
        for (; it != end; ++it) {
            preorder_values.push_back(*it);
        }
        std::vector<Complex> expected_preorder = {Complex(1, 1), Complex(2, 2), Complex(4, 4), Complex(5, 5), Complex(3, 3)};
        CHECK(preorder_values == expected_preorder);
    }

    SUBCASE("Postorder traversal") {
        auto it = tree.begin_post_order();
        auto end = tree.end_post_order();
        std::vector<Complex> postorder_values;
        for (; it != end; ++it) {
            postorder_values.push_back(*it);
        }
        std::vector<Complex> expected_postorder = {Complex(4, 4), Complex(5, 5), Complex(2, 2), Complex(3, 3), Complex(1, 1)};
        CHECK(postorder_values == expected_postorder);
    }

    SUBCASE("Inorder traversal") {
        auto it = tree.begin_in_order();
        auto end = tree.end_in_order();
        std::vector<Complex> inorder_values;
        for (; it != end; ++it) {
            inorder_values.push_back(*it);
        }
        std::vector<Complex> expected_inorder = {Complex(4, 4), Complex(2, 2), Complex(5, 5), Complex(1, 1), Complex(3, 3)};
        CHECK(inorder_values == expected_inorder);
    }

    SUBCASE("BFS traversal") {
        auto it = tree.begin_bfs_scan();
        auto end = tree.end_bfs_scan();
        std::vector<Complex> bfs_values;
        for (; it != end; ++it) {
            bfs_values.push_back(*it);
        }
        std::vector<Complex> expected_bfs = {Complex(1, 1), Complex(2, 2), Complex(3, 3), Complex(4, 4), Complex(5, 5)};
        CHECK(bfs_values == expected_bfs);
    }
}

TEST_CASE("Test edge cases") {
    Tree<int> tree(2);
    CHECK_THROWS_AS(tree.get_root(), std::runtime_error);
    
    CHECK_THROWS_AS(Tree<int> tree(-1);, std::overflow_error);

    tree.add_root(10);
    auto root = tree.get_root_node();
    CHECK_NOTHROW(tree.add_sub_node(root, new Node<int>(20)));
    CHECK_NOTHROW(tree.add_sub_node(root, new Node<int>(30)));
    CHECK_THROWS_AS(tree.add_sub_node(root, new Node<int>(40)), std::overflow_error);
}
TEST_CASE("Test using iterators with k>2") {
       Tree<int> tree(3);
    tree.add_root(10);
    auto root = tree.get_root_node();
    auto child1 = new Node<int>(20);
    auto child2 = new Node<int>(30);
    auto child3 = new Node<int>(40);
    auto grandchild1 = new Node<int>(50);
    auto grandchild2 = new Node<int>(60);

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(root, child3);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);
    CHECK_THROWS_AS(tree.begin_in_order(), std::runtime_error);
    CHECK_THROWS_AS(tree.end_in_order(), std::runtime_error);
    CHECK_THROWS_AS(tree.begin_post_order(), std::runtime_error);
    CHECK_THROWS_AS(tree.end_post_order(), std::runtime_error);
    CHECK_THROWS_AS(tree.begin_pre_order(), std::runtime_error);
    CHECK_THROWS_AS(tree.end_pre_order(), std::runtime_error);

}

TEST_CASE("Test tree traversal with a single node") {
    Tree<int> tree(2);
    tree.add_root(42);

    SUBCASE("Preorder traversal") {
        auto it = tree.begin_pre_order();
        auto end = tree.end_pre_order();
        std::vector<int> preorder_values;
        for (; it != end; ++it) {
            preorder_values.push_back(*it);
        }
        std::vector<int> expected_preorder = {42};
        CHECK(preorder_values == expected_preorder);
    }

    SUBCASE("Postorder traversal") {
        auto it = tree.begin_post_order();
        auto end = tree.end_post_order();
        std::vector<int> postorder_values;
        for (; it != end; ++it) {
            postorder_values.push_back(*it);
        }
        std::vector<int> expected_postorder = {42};
        CHECK(postorder_values == expected_postorder);
    }

    SUBCASE("Inorder traversal") {
        auto it = tree.begin_in_order();
        auto end = tree.end_in_order();
        std::vector<int> inorder_values;
        for (; it != end; ++it) {
            inorder_values.push_back(*it);
        }
        std::vector<int> expected_inorder = {42};
        CHECK(inorder_values == expected_inorder);
    }

    SUBCASE("BFS traversal") {
        auto it = tree.begin_bfs_scan();
        auto end = tree.end_bfs_scan();
        std::vector<int> bfs_values;
        for (; it != end; ++it) {
            bfs_values.push_back(*it);
        }
        std::vector<int> expected_bfs = {42};
        CHECK(bfs_values == expected_bfs);
    }

    SUBCASE("DFS traversal") {
        auto it = tree.begin_dfs_scan();
        auto end = tree.end_dfs_scan();
        std::vector<int> dfs_values;
        for (; it != end; ++it) {
            dfs_values.push_back(*it);
        }
        std::vector<int> expected_dfs = {42};
        CHECK(dfs_values == expected_dfs);
    }
}

TEST_CASE("Test adding sub node to a non-existing parent") {
    Tree<int> tree(2);
    tree.add_root(10);
    auto non_existing_parent = new Node<int>(99);
    auto child = new Node<int>(20);

    CHECK_THROWS_AS(tree.add_sub_node(non_existing_parent, child), std::runtime_error);
}
TEST_CASE("Test tree deletion") {
    // Create a tree with k=2
    Tree<int> tree(2);

    // Add root and sub-nodes
    tree.add_root(1);
    auto root = tree.get_root_node();
    CHECK_NOTHROW(tree.add_sub_node(root, new Node<int>(2)));
    CHECK_NOTHROW(tree.add_sub_node(root, new Node<int>(3)));

    auto child1 = root->children[0];
    auto child2 = root->children[1];

    CHECK_NOTHROW(tree.add_sub_node(child1, new Node<int>(4)));
    CHECK_NOTHROW(tree.add_sub_node(child1, new Node<int>(5)));
    CHECK_NOTHROW(tree.add_sub_node(child2, new Node<int>(6)));
    CHECK_NOTHROW(tree.add_sub_node(child2, new Node<int>(7)));

   
    CHECK_NOTHROW(tree.~Tree());
 
    CHECK(tree.get_root_node() == nullptr);
}