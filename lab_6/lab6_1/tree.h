#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include "smart_pointers.h"
#include <QtWidgets>
struct Node
{
    std::string value;
    size_t key, height = 0;
    shared_ptr<Node> left, right;
    Node();
    Node(size_t key, std::string value): key(key), value(value)
    {}
};

class Tree
{
public:
    Tree();
    size_t getHeight(shared_ptr<Node>);
    size_t getBalance(shared_ptr<Node>);
    shared_ptr<Node> rightRotate(shared_ptr<Node>);
    shared_ptr<Node> leftRotate(shared_ptr<Node>);
    shared_ptr<Node> insert(shared_ptr<Node>, size_t, std::string);
    shared_ptr<Node> minValueNode(shared_ptr<Node>);
    shared_ptr<Node> deleteNode(shared_ptr<Node>, size_t);
    shared_ptr<Node> findNode(shared_ptr<Node>, size_t);
    void directBypass(shared_ptr<Node>, std::vector<std::string>&);
    void reverseBypass(shared_ptr<Node>, std::vector<std::string>&);

    shared_ptr<Node> root;

};

#endif // TREE_H
