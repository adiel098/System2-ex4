#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template<typename T>
class Node {

public:
    T data;
    std::vector<Node*> children;

    Node(T value)  //constructor
    {
        this->data=value;
    }

    T getData() const //will return data of the node
    {
        return data;
    }
};

#endif // NODE_HPP