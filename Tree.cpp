#include "Tree.hpp"

// Tree class implementation
template<typename T>
Tree<T>::Tree(int k) {

    this->root=nullptr;
    this->k=k;
}

template<typename T>
Tree<T>::~Tree() { //Destructor

    deleteTreeRecursive(root); //will use help recursive method to run all tree and delete all the nodes
}

//helper method
template<typename T>
void Tree<T>::deleteTreeRecursive(Node<T>* node) //will delete all the nodes in the tree
{ 
    
    if (node) 
    {
        for (auto child : node->children) {
            deleteTreeRecursive(child);
        }
        delete node;
    }
}


template<typename T>
void Tree<T>::add_root(T data) { //will add new root and if already exist its will update the value
    if (root==nullptr) 
    {
        root = new Node<T>(data);
    } else {
        root->data = data;
    }
}

template<typename T>
void Tree<T>::add_sub_node(Node<T>* parent, Node<T>* child) 
{

    if (parent->children.size() < k) 
    {

        parent->children.push_back(child);
    } 
    else 
    {

        throw std::overflow_error("You trying to add more child  than approve (k)");
    }
}

template<typename T>
T Tree<T>::get_root() const {

    if (root==nullptr) {
        throw std::runtime_error("Tree  empty and not have root");
    }
    return root->data; // if exist and not empty return the root data
}

template<typename T>
Node<T>* Tree<T>::get_root_node() const 
{
    return root;
}

template<typename T>
int Tree<T>::getK() const 
{

    return k;
}

// PreorderIterator//
template<typename T>
Tree<T>::PreorderIterator::PreorderIterator(Node<T>* root) {

    this->current=nullptr;
    if (root!=nullptr) 
    {
        stack.push(root);
    }
    advance();
}

template<typename T>
bool Tree<T>::PreorderIterator::operator!=(const PreorderIterator& other) const {
    return current != other.current;
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
void Tree<T>::PreorderIterator::advance() { // proceed next node in preorder 
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
typename Tree<T>::PreorderIterator Tree<T>::begin_pre_order() 
{
    //will return iterator of begin with preorder 
    return PreorderIterator(root);
}

template<typename T>
typename Tree<T>::PreorderIterator Tree<T>::end_pre_order() 
{
    //will return iterator of end with preorder
    return PreorderIterator(nullptr);
}

// PostorderIterator//
template<typename T>
Tree<T>::PostorderIterator::PostorderIterator(Node<T>* root) {

    this->current=root;
    if (root) {
        fillStack(root);
        advance();
    }
}

template<typename T>
bool Tree<T>::PostorderIterator::operator!=(const PostorderIterator& other) const 
{
    return current != other.current;
}

template<typename T>
T& Tree<T>::PostorderIterator::operator*() const 
{
    return current->data;
}

template<typename T>
typename Tree<T>::PostorderIterator& Tree<T>::PostorderIterator::operator++() 
{
    advance();
    return *this;
}

template<typename T>
void Tree<T>::PostorderIterator::advance() 
{ 
    // proceed next node in postorder 

    if (!visitStack.empty()) 
    {
        current = visitStack.top();
        visitStack.pop();
    } 
    else 
    {
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
typename Tree<T>::PostorderIterator Tree<T>::begin_post_order() 
{
    return PostorderIterator(root);    //will return iterator of begin with postorder 

}

template<typename T>
typename Tree<T>::PostorderIterator Tree<T>::end_post_order() 
{
    return PostorderIterator(nullptr); //will return iterator of end with postorder 
}

// InorderIterator//
template<typename T>
Tree<T>::InorderIterator::InorderIterator(Node<T>* root)
 {
    this->current=root;
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
bool Tree<T>::InorderIterator::operator!=(const InorderIterator& other) const 
{
    return current != other.current;
}

template<typename T>
T& Tree<T>::InorderIterator::operator*() const 
{
    return current->data;
}

template<typename T>
typename Tree<T>::InorderIterator& Tree<T>::InorderIterator::operator++() 
{
    advance();
    return *this;
}

template<typename T>
void Tree<T>::InorderIterator::advance() { // procced the iterator to next right node  and add him to the stack in inorder

    if (current==nullptr) //end or not exisst
        return;

    if (!current->children.empty() && current->children.size() > 1) 
    {
        Node<T>* temp = current->children[1];
        while (temp) 
        {
            stack.push(temp);
            temp = temp->children.empty() ? nullptr : temp->children[0];
        }
    }

    if (!stack.empty()) 
    {
        current = stack.top();
        stack.pop();
    } 
    else 
    {
        current = nullptr;
    }
}

template<typename T>
typename Tree<T>::InorderIterator Tree<T>::begin_in_order() 
{
    return InorderIterator(root); //will return iterator of begin with inorder 
}

template<typename T>
typename Tree<T>::InorderIterator Tree<T>::end_in_order() 
{
    return InorderIterator(nullptr); //will return iterator of end with inordder 
}

// BFSIterator//
template<typename T>
Tree<T>::BFSIterator::BFSIterator(Node<T>* root)
{
    this->current=nullptr;
    if (root) queue.push(root);
    advance();
}

template<typename T>
bool Tree<T>::BFSIterator::operator!=(const BFSIterator& other) const 
{
    return current != other.current;
}

template<typename T>
T& Tree<T>::BFSIterator::operator*() const 
{
    return current->data;
}

template<typename T>
typename Tree<T>::BFSIterator& Tree<T>::BFSIterator::operator++() 
{
    advance();
    return *this;
}

template<typename T>
void Tree<T>::BFSIterator::advance() { // procced to next node by run on all childrens of exist node and add to queque
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
typename Tree<T>::BFSIterator Tree<T>::begin_bfs_scan() 
{
    return BFSIterator(root); //will return iterator of begin with bfs 
}

template<typename T>
typename Tree<T>::BFSIterator Tree<T>::end_bfs_scan() 
{
    return BFSIterator(nullptr); //will return iterator of end with bfs 
}

// DFSIterator//
template<typename T>
Tree<T>::DFSIterator::DFSIterator(Node<T>* root)

{
    this->current=nullptr;
    if (root!=nullptr)
    {
        stack.push(root);
    } 
    advance();//procced to first node
}

template<typename T>
bool Tree<T>::DFSIterator::operator!=(const DFSIterator& other) const 
{
    return current != other.current;
}

template<typename T>
T& Tree<T>::DFSIterator::operator*() const 
{
    return current->data;
}

template<typename T>
typename Tree<T>::DFSIterator& Tree<T>::DFSIterator::operator++() {
    advance();
    return *this;
}

template<typename T>
void Tree<T>::DFSIterator::advance() { // procced to next in dfs
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
typename Tree<T>::DFSIterator Tree<T>::begin_dfs_scan() 
{
    return DFSIterator(root); //will return iterator of begin with dfs
}

template<typename T>
typename Tree<T>::DFSIterator Tree<T>::end_dfs_scan() 
{
    return DFSIterator(nullptr); //will return iterator of end with dfs
}




