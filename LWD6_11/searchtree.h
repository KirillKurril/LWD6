#ifndef SEARCHTREE_H
#define SEARCHTREE_H


#include <QString>
#include <iostream>
#include <cstddef>
#include <string>
#include <exception>
#include "pair.h"

template <typename T>
class SearchTree {
    struct Node{
        Pair<size_t, T> data;
        Node* left_ = nullptr;
        Node* right_ = nullptr;
        Node* parent_ = nullptr;
        explicit Node (int key, T value = nullptr, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) : data(key, value), left_(left), right_(right), parent_(parent) {}
    };
public:

    void Insert(size_t key, T value);
    SearchTree() {root = nullptr;}
    bool IsEmpty();
    T IterSearch(size_t key);
    T RecSearch(size_t key);
    void remove(size_t key);
    void take_a_look();
    void pre_order_traversal(Node* ptr_, QString& output);
    void in_order_traversal(Node* ptr_, QString& output);
    void post_order_traversal(Node* ptr_, QString& output);
    void clear();
    Node* GetRoot();

private:
    Node* recsch(size_t key, Node* ptr_);
    Node* root = nullptr;
};




#endif // SEARCHTREE_H
