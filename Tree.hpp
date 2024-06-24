#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdexcept>

// Tree class definition
template<typename T>
class Tree {
private:
    Node<T>* root;
    int k; // Maximum number of children

public:
    ~Tree(); //Destructor

    Tree(int k = 2); // default to k=2

    BFSIterator myHeap() ; //convert tree to minimal heap
    void heapify(Node<T>* node); // helper method for myHeap
    void add_root(T value);
    void add_sub_node(Node<T>* parent, Node<T>* child);
    T get_root() const;
    Node<T>* get_root_node() const;
    int getK() const;

    // Preorder iterator
    class PreorderIterator {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;

    public:
        PreorderIterator(Node<T>* root);

        bool operator!=(const PreorderIterator& other) const;
        T& operator*() const;
        PreorderIterator& operator++();

    private:
        void advance();
    };

    PreorderIterator begin_pre_order();
    PreorderIterator end_pre_order();

    // Post-order iterator
    class PostorderIterator {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
        std::stack<Node<T>*> visitStack;

    public:
        PostorderIterator(Node<T>* root);

        bool operator!=(const PostorderIterator& other) const;
        T& operator*() const;
        PostorderIterator& operator++();

    private:
        void advance();
        void fillStack(Node<T>* node);
    };

    PostorderIterator begin_post_order();
    PostorderIterator end_post_order();

    // In-order iterator
    class InorderIterator {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;

    public:
        InorderIterator(Node<T>* root);

        bool operator!=(const InorderIterator& other) const;
        T& operator*() const;
        InorderIterator& operator++();

    private:
        void advance();
    };

    InorderIterator begin_in_order();
    InorderIterator end_in_order();

    // BFS iterator
    class BFSIterator {
    private:
        Node<T>* current;
        std::queue<Node<T>*> queue;

    public:
        BFSIterator(Node<T>* root);
        

        bool operator!=(const BFSIterator& other) const;
        T& operator*() const;
        BFSIterator& operator++();

    private:
        void advance();
    };

    BFSIterator begin_bfs_scan();
    BFSIterator end_bfs_scan();

    // DFS iterator
    class DFSIterator {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;

    public:
        DFSIterator(Node<T>* root);

        bool operator!=(const DFSIterator& other) const;
        T& operator*() const;
        DFSIterator& operator++();

    private:
        void advance();
    };

    DFSIterator begin_dfs_scan();
    DFSIterator end_dfs_scan();

private:
    void deleteTreeRecursive(Node<T>* node);
};

#include "Tree.cpp"

#endif // TREE_HPP
