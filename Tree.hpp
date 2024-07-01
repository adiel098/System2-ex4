#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdexcept>
#include <algorithm>


// Tree class definition
template<typename T>
class Tree {
private:
    Node<T>* root;
    int k; // Maximum number of children

public:
    Tree(int k = 2); // default to k=2
    ~Tree(); // Destructor
    bool node_exists(Node<T>* node, Node<T>* root) const; // Helper function to check if a node exists in the tree
    void add_root(T value);
    void add_sub_node(Node<T>* parent, Node<T>* child);
    T get_root() const;
    Node<T>* get_root_node() const;
    int getK() const;
    void myHeap();

    // Preorder iterator
    class PreorderIterator {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;

    public:
        PreorderIterator(Node<T>* root);

        bool operator!=(const PreorderIterator& other) const;
        bool operator==(const PreorderIterator& other) const;

        T& operator*() const;
        PreorderIterator& operator++();

    private:
        void advance();
    };

    PreorderIterator begin_pre_order();
    PreorderIterator end_pre_order();

    // Postorder iterator
    class PostorderIterator {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;
        std::stack<Node<T>*> visitStack;

    public:
        PostorderIterator(Node<T>* root);

        bool operator!=(const PostorderIterator& other) const;
        bool operator==(const PostorderIterator& other) const;

        T& operator*() const;
        PostorderIterator& operator++();

    private:
        void advance();
        void fillStack(Node<T>* node);
    };

    PostorderIterator begin_post_order();
    PostorderIterator end_post_order();

    // Inorder iterator
    class InorderIterator {
    private:
        Node<T>* current;
        std::stack<Node<T>*> stack;

    public:
        InorderIterator(Node<T>* root);

        bool operator!=(const InorderIterator& other) const;
        bool operator==(const InorderIterator& other) const;
        void pushLeftMost(Node<T>* node);

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
        bool operator==(const BFSIterator& other) const;

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
        bool operator==(const DFSIterator& other) const;

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

// Implementation of Tree class template

template<typename T>
Tree<T>::Tree(int k) : root(nullptr), k(k) {
    if(k < 0) {
        throw std::overflow_error("you can't create tree with negative k");
    }
}

template<typename T>
Tree<T>::~Tree() {
    deleteTreeRecursive(root);
    root = nullptr;
}

template<typename T>
void Tree<T>::deleteTreeRecursive(Node<T>* node) {
    if (node) {
        for (auto child : node->children) {
            deleteTreeRecursive(child);
        }
        delete node;
    }
}

template<typename T>
void Tree<T>::add_root(T value) {
    if (!root) {
        root = new Node<T>(value);
    } else {
        root->data = value;
    }
}

template<typename T>
bool Tree<T>::node_exists(Node<T>* node, Node<T>* root) const {
    if (!root) return false;
    if (root == node) return true;
    for (auto child : root->children) {
        if (node_exists(node, child)) return true;
    }
    return false;
}

template<typename T>
void Tree<T>::add_sub_node(Node<T>* parent, Node<T>* child) {
    if (!node_exists(parent, root)) {
        throw std::runtime_error("Parent node does not exist in the tree");
    }
    if (parent->children.size() < k) {
        parent->children.push_back(child);
    } else {
        throw std::overflow_error("You are trying to add more children than allowed (k)");
    }
}

template<typename T>
T Tree<T>::get_root() const {
    if (!root) {
        throw std::runtime_error("Tree is empty and does not have a root");
    }
    return root->data;
}

template<typename T>
Node<T>* Tree<T>::get_root_node() const {
    return root;
}

template<typename T>
int Tree<T>::getK() const {
    return k;
}

template<typename T>
void Tree<T>::myHeap() {
    if (!root) return;

    // Step 1: Gather all nodes in an array using BFS
    std::vector<Node<T>*> nodes;
    std::queue<Node<T>*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        nodes.push_back(current);
        for (auto child : current->children) {
            q.push(child);
        }
    }

    // Step 2: Sort the array based on node values to create a minimal heap structure
    std::sort(nodes.begin(), nodes.end(), [](Node<T>* a, Node<T>* b) {
        return (a->data) < (b->data);
    });

    // Step 3: Reassign the values in the original tree to reflect the minimal heap
    q.push(root);
    size_t index = 0;
    
    while (!q.empty()) {
        Node<T>* current = q.front();
        q.pop();
        current->data = nodes[index++]->data;
        for (auto child : current->children) {
            q.push(child);
        }
    }
}

// PreorderIterator implementation
template<typename T>
Tree<T>::PreorderIterator::PreorderIterator(Node<T>* root) {
    current = nullptr;
    if (root) {
        stack.push(root);
    }
    advance();
}

template<typename T>
bool Tree<T>::PreorderIterator::operator!=(const PreorderIterator& other) const {
    return current != other.current;
}

template<typename T>
bool Tree<T>::PreorderIterator::operator==(const PreorderIterator& other) const {
    return current == other.current;
}

template<typename T>
T& Tree<T>::PreorderIterator::operator*() const {
    return current->data;
}

template<typename T>
typename Tree<T>::PreorderIterator& Tree<T>::PreorderIterator::operator++() {
    advance();
    return *this;
}

template<typename T>
void Tree<T>::PreorderIterator::advance() {
    if (!stack.empty()) {
        current = stack.top();
        stack.pop();
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            stack.push(*it);
        }
    } else {
        current = nullptr;
    }
}

template<typename T>
typename Tree<T>::PreorderIterator Tree<T>::begin_pre_order() {
    if (this->getK() > 2) {
        throw std::runtime_error("You can't use that on a non-binary tree");
    }
    return PreorderIterator(root);
}

template<typename T>
typename Tree<T>::PreorderIterator Tree<T>::end_pre_order() {
    if (this->getK() > 2) {
        throw std::runtime_error("You can't use that on a non-binary tree");
    }
    return PreorderIterator(nullptr);
}

// PostorderIterator implementation
template<typename T>
Tree<T>::PostorderIterator::PostorderIterator(Node<T>* root) {
    current = root;
    if (root) {
        fillStack(root);
        advance();
    }
}

template<typename T>
bool Tree<T>::PostorderIterator::operator!=(const PostorderIterator& other) const {
    return current != other.current;
}

template<typename T>
bool Tree<T>::PostorderIterator::operator==(const PostorderIterator& other) const {
    return current == other.current;
}

template<typename T>
T& Tree<T>::PostorderIterator::operator*() const {
    return current->data;
}

template<typename T>
typename Tree<T>::PostorderIterator& Tree<T>::PostorderIterator::operator++() {
    advance();
    return *this;
}

template<typename T>
void Tree<T>::PostorderIterator::advance() {
    if (!visitStack.empty()) {
        current = visitStack.top();
        visitStack.pop();
    } else {
        current = nullptr;
    }
}

template<typename T>
void Tree<T>::PostorderIterator::fillStack(Node<T>* node) {
    if (!node) return;
    std::stack<Node<T>*> tempStack;
    tempStack.push(node);
    while (!tempStack.empty()) {
        Node<T>* n = tempStack.top();
        tempStack.pop();
        visitStack.push(n);
        for (auto it = n->children.begin(); it != n->children.end(); ++it) {
            tempStack.push(*it);
        }
    }
}

template<typename T>
typename Tree<T>::PostorderIterator Tree<T>::begin_post_order() {
    if (this->getK() > 2) {
        throw std::runtime_error("You can't use that on a non-binary tree");
    }
    return PostorderIterator(root);
}

template<typename T>
typename Tree<T>::PostorderIterator Tree<T>::end_post_order() {
    if (this->getK() > 2) {
        throw std::runtime_error("You can't use that on a non-binary tree");
    }
    return PostorderIterator(nullptr);
}

// InorderIterator implementation
template<typename T>
Tree<T>::InorderIterator::InorderIterator(Node<T>* root) {
    current = root;
    while (current) {
        stack.push(current);
        current = current->children.empty() ? nullptr : current->children[0];
    }
    if (!stack.empty()) {
        current = stack.top();
        stack.pop();
    }
}

template<typename T>
bool Tree<T>::InorderIterator::operator!=(const InorderIterator& other) const {
    return current != other.current;
}

template<typename T>
bool Tree<T>::InorderIterator::operator==(const InorderIterator& other) const {
    return current == other.current;
}

template<typename T>
T& Tree<T>::InorderIterator::operator*() const {
    return current->data;
}

template<typename T>
typename Tree<T>::InorderIterator& Tree<T>::InorderIterator::operator++() {
    advance();
    return *this;
}

template<typename T>
void Tree<T>::InorderIterator::advance() {
    if (!current) return;

    if (!current->children.empty() && current->children.size() > 1) {
        Node<T>* temp = current->children[1];
        while (temp) {
            stack.push(temp);
            temp = temp->children.empty() ? nullptr : temp->children[0];
        }
    }

    if (!stack.empty()) {
        current = stack.top();
        stack.pop();
    } else {
        current = nullptr;
    }
}

template<typename T>
typename Tree<T>::InorderIterator Tree<T>::begin_in_order() {
    if (this->getK() > 2) {
        throw std::runtime_error("You can't use that on a non-binary tree");
    }
    return InorderIterator(root);
}

template<typename T>
typename Tree<T>::InorderIterator Tree<T>::end_in_order() {
    if (this->getK() > 2) {
        throw std::runtime_error("You can't use that on a non-binary tree");
    }
    return InorderIterator(nullptr);
}

// BFSIterator implementation
template<typename T>
Tree<T>::BFSIterator::BFSIterator(Node<T>* root) {
    current = nullptr;
    if (root) queue.push(root);
    advance();
}

template<typename T>
bool Tree<T>::BFSIterator::operator!=(const BFSIterator& other) const {
    return current != other.current;
}

template<typename T>
bool Tree<T>::BFSIterator::operator==(const BFSIterator& other) const {
    return current == other.current;
}

template<typename T>
T& Tree<T>::BFSIterator::operator*() const {
    return current->data;
}

template<typename T>
typename Tree<T>::BFSIterator& Tree<T>::BFSIterator::operator++() {
    advance();
    return *this;
}

template<typename T>
void Tree<T>::BFSIterator::advance() {
    if (!queue.empty()) {
        current = queue.front();
        queue.pop();
        for (auto child : current->children) {
            queue.push(child);
        }
    } else {
        current = nullptr;
    }
}

template<typename T>
typename Tree<T>::BFSIterator Tree<T>::begin_bfs_scan() {
    return BFSIterator(root);
}

template<typename T>
typename Tree<T>::BFSIterator Tree<T>::end_bfs_scan() {
    return BFSIterator(nullptr);
}

// DFSIterator implementation
template<typename T>
Tree<T>::DFSIterator::DFSIterator(Node<T>* root) {
    current = nullptr;
    if (root) {
        stack.push(root);
    }
    advance();
}

template<typename T>
bool Tree<T>::DFSIterator::operator!=(const DFSIterator& other) const {
    return current != other.current;
}

template<typename T>
bool Tree<T>::DFSIterator::operator==(const DFSIterator& other) const {
    return current == other.current;
}

template<typename T>
T& Tree<T>::DFSIterator::operator*() const {
    return current->data;
}

template<typename T>
typename Tree<T>::DFSIterator& Tree<T>::DFSIterator::operator++() {
    advance();
    return *this;
}

template<typename T>
void Tree<T>::DFSIterator::advance() {
    if (!stack.empty()) {
        current = stack.top();
        stack.pop();
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
            stack.push(*it);
        }
    } else {
        current = nullptr;
    }
}

template<typename T>
typename Tree<T>::DFSIterator Tree<T>::begin_dfs_scan() {
    return DFSIterator(root);
}

template<typename T>
typename Tree<T>::DFSIterator Tree<T>::end_dfs_scan() {
    return DFSIterator(nullptr);
}

#endif // TREE_HPP
