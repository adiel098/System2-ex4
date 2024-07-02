//id:207988213,email:haleviadiel@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

#include <vector>
#include <stdexcept>
#include <iostream>


TEST_CASE("Test all traversals for k <= 2 with grandchildren") 
{
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

    SUBCASE("Preorder traversal") {
        auto it = tree.begin_pre_order();
        auto end = tree.end_pre_order();
        std::vector<int> preorder_values;
        for (; it != end; ++it) {
            preorder_values.push_back(*it);
        }
        std::vector<int> expected_preorder = {10, 20, 40, 50, 30};
        CHECK(preorder_values == expected_preorder);
    }

    SUBCASE("Inorder traversal") {
        auto it = tree.begin_in_order();
        auto end = tree.end_in_order();
        std::vector<int> inorder_values;
        for (; it != end; ++it) {
            inorder_values.push_back(*it);
        }
        std::vector<int> expected_inorder = {40, 20, 50, 10, 30};
        CHECK(inorder_values == expected_inorder);
    }

    SUBCASE("Postorder traversal") {
        auto it = tree.begin_post_order();
        auto end = tree.end_post_order();
        std::vector<int> postorder_values;
        for (; it != end; ++it) {
            postorder_values.push_back(*it);
        }
        std::vector<int> expected_postorder = {40, 50, 20, 30, 10};
        CHECK(postorder_values == expected_postorder);
    }

    SUBCASE("BFS traversal") {
        auto it = tree.begin_bfs_scan();
        auto end = tree.end_bfs_scan();
        std::vector<int> bfs_values;
        for (; it != end; ++it) {
            bfs_values.push_back(*it);
        }
        std::vector<int> expected_bfs = {10, 20, 30, 40, 50};
        CHECK(bfs_values == expected_bfs);
    }

    SUBCASE("DFS traversal") {
        auto it = tree.begin_dfs_scan();
        auto end = tree.end_dfs_scan();
        std::vector<int> dfs_values;
        for (; it != end; ++it) {
            dfs_values.push_back(*it);
        }
        std::vector<int> expected_dfs = {10, 20, 40, 50, 30};
        CHECK(dfs_values == expected_dfs);
    }
}
TEST_CASE("Test all traversals with complex numbers and multiple iterators") 
{
    Tree<Complex> tree(2);
    tree.add_root(Complex(10, 1));
    auto root = tree.get_root_node();
    auto child1 = new Node<Complex>(Complex(20, 2));
    auto child2 = new Node<Complex>(Complex(30, 3));
    auto grandchild1 = new Node<Complex>(Complex(40, 4));
    auto grandchild2 = new Node<Complex>(Complex(50, 5));

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
        std::vector<Complex> expected_preorder = {Complex(10, 1), Complex(20, 2), Complex(40, 4), Complex(50, 5), Complex(30, 3)};
        CHECK(preorder_values == expected_preorder);
    }

    SUBCASE("Inorder traversal") {
        auto it = tree.begin_in_order();
        auto end = tree.end_in_order();
        std::vector<Complex> inorder_values;
        for (; it != end; ++it) {
            inorder_values.push_back(*it);
        }
        std::vector<Complex> expected_inorder = {Complex(40, 4), Complex(20, 2), Complex(50, 5), Complex(10, 1), Complex(30, 3)};
        CHECK(inorder_values == expected_inorder);
    }

    SUBCASE("Postorder traversal") {
        auto it = tree.begin_post_order();
        auto end = tree.end_post_order();
        std::vector<Complex> postorder_values;
        for (; it != end; ++it) {
            postorder_values.push_back(*it);
        }
        std::vector<Complex> expected_postorder = {Complex(40, 4), Complex(50, 5), Complex(20, 2), Complex(30, 3), Complex(10, 1)};
        CHECK(postorder_values == expected_postorder);
    }

    SUBCASE("BFS traversal") {
        auto it = tree.begin_bfs_scan();
        auto end = tree.end_bfs_scan();
        std::vector<Complex> bfs_values;
        for (; it != end; ++it) {
            bfs_values.push_back(*it);
        }
        std::vector<Complex> expected_bfs = {Complex(10, 1), Complex(20, 2), Complex(30, 3), Complex(40, 4), Complex(50, 5)};
        CHECK(bfs_values == expected_bfs);
    }

    SUBCASE("DFS traversal") {
        auto it = tree.begin_dfs_scan();
        auto end = tree.end_dfs_scan();
        std::vector<Complex> dfs_values;
        for (; it != end; ++it) {
            dfs_values.push_back(*it);
        }
        std::vector<Complex> expected_dfs = {Complex(10, 1), Complex(20, 2), Complex(40, 4), Complex(50, 5), Complex(30, 3)};
        CHECK(dfs_values == expected_dfs);
    }

}

TEST_CASE("Test edge cases") 
{
    Tree<int> tree(2);

    // Test getting root from an empty tree
    CHECK_THROWS_AS(tree.get_root(), std::runtime_error);

    // Test creating a tree with a negative value of k
    CHECK_THROWS_AS(Tree<int> tree(-1);, std::overflow_error);


    tree.add_root(10);
    auto root = tree.get_root_node();
    
    // Test adding nodes correctly
    CHECK_NOTHROW(tree.add_sub_node(root, new Node<int>(20)));
    CHECK_NOTHROW(tree.add_sub_node(root, new Node<int>(30)));

    // Test adding more children than allowed
    CHECK_THROWS_AS(tree.add_sub_node(root, new Node<int>(40)), std::overflow_error);
}
TEST_CASE("Test adding sub node to a non-existing parent") 
{
    Tree<int> tree(2);
    tree.add_root(10);
    auto non_existing_parent = new Node<int>(99);
    auto child = new Node<int>(20);

    CHECK_THROWS_AS(tree.add_sub_node(non_existing_parent, child), std::runtime_error);
}
TEST_CASE("Test tree traversal with a single node") 
{
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

    // Test tree traversal before deletion
    auto bfs_it = tree.begin_bfs_scan();
    auto bfs_end = tree.end_bfs_scan();
    std::vector<int> bfs_values;
    for (; bfs_it != bfs_end; ++bfs_it) {
        bfs_values.push_back(*bfs_it);
    }
    std::vector<int> expected_bfs_before_deletion = {1, 2, 3, 4, 5, 6, 7};
    CHECK(bfs_values == expected_bfs_before_deletion);

    // Test tree deletion
    CHECK_NOTHROW(tree.~Tree());
    CHECK(tree.get_root_node() == nullptr);
}


TEST_CASE("Test DFS and BFS traversal for k > 2 with multiple grandchildren") {
    Tree<int> tree(3); // k = 3, a 3-ary tree
    tree.add_root(10);
    auto root = tree.get_root_node();
    auto child1 = new Node<int>(20);
    auto child2 = new Node<int>(30);
    auto child3 = new Node<int>(40);
    auto grandchild1 = new Node<int>(50);
    auto grandchild2 = new Node<int>(60);
    auto grandchild3 = new Node<int>(70);
    auto grandchild4 = new Node<int>(80);

    tree.add_sub_node(root, child1);
    tree.add_sub_node(root, child2);
    tree.add_sub_node(root, child3);
    tree.add_sub_node(child1, grandchild1);
    tree.add_sub_node(child1, grandchild2);
    tree.add_sub_node(child2, grandchild3);
    tree.add_sub_node(child3, grandchild4);

    SUBCASE("DFS traversal") {
        auto it = tree.begin_dfs_scan();
        auto end = tree.end_dfs_scan();
        std::vector<int> dfs_values;
        for (; it != end; ++it) {
            dfs_values.push_back(*it);
        }
        std::vector<int> expected_dfs = {10, 20, 50, 60, 30, 70, 40, 80};
        CHECK(dfs_values == expected_dfs);
    }

    SUBCASE("BFS traversal") {
        auto it = tree.begin_bfs_scan();
        auto end = tree.end_bfs_scan();
        std::vector<int> bfs_values;
        for (; it != end; ++it) {
            bfs_values.push_back(*it);
        }
        std::vector<int> expected_bfs = {10, 20, 30, 40, 50, 60, 70, 80};
        CHECK(bfs_values == expected_bfs);
    }
}