
//id:207988213,email:haleviadiel@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T>
class Node {
public:
    T data;
    std::vector<Node<T>*> children;

    Node(T value) : data(value) {}
};

#endif // NODE_HPP
