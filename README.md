
# Tree Library with GUI Support

This project provides a template-based tree implementation in C++ with support for various traversal methods, conversion to a minimal heap, and a GUI for visualizing the tree using Qt Creator.

## Features

- **Tree Structure**: Supports k-ary trees (trees where each node can have up to k children).
- **Traversal Methods**: Includes Preorder, Postorder, Inorder (for binary trees), BFS (Breadth-First Search), and DFS (Depth-First Search) traversal iterators.
- **Minimal Heap Conversion**: Converts the tree to a minimal heap, ensuring that the value of each node is less than or equal to the values of its children.
- **Complex Numbers**: Supports tree nodes with complex number values.
- **GUI Support**: Visualize the tree structure using Qt Creator.

## Class Definitions

### Tree Class

The `Tree` class template provides methods for managing a tree structure:

- `Tree(int k = 2)`: Constructor to initialize a tree with up to k children per node (default is binary tree).
- `~Tree()`: Destructor to clean up the tree.
- `add_root(T value)`: Adds or updates the root node with the given value.
- `add_sub_node(Node<T>* parent, Node<T>* child)`: Adds a child node to the specified parent node.
- `T get_root() const`: Returns the value of the root node.
- `Node<T>* get_root_node() const`: Returns the root node.
- `int getK() const`: Returns the maximum number of children per node.
- `void to_minimal_heap()`: Converts the tree to a minimal heap.

### Iterators

The `Tree` class provides the following iterators:

- `PreorderIterator`: Preorder traversal.
- `PostorderIterator`: Postorder traversal.
- `InorderIterator`: Inorder traversal (for binary trees).
- `BFSIterator`: Breadth-First Search traversal.
- `DFSIterator`: Depth-First Search traversal.

### Node Class

The `Node` class template represents individual nodes in the tree, holding data of type `T` and a list of child nodes.

### Complex Class

The `Complex` class represents complex numbers and includes comparison operators to support tree operations.

## Usage

### Running Demo

```sh
make tree
./tree
```
### Running Tests

```sh
make tests
./tests
```

```
