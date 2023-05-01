//
// Created by Урфин-Джус on 29.04.2023.
//

#include <iostream>
#include <cstddef>
#include <string>
#include <exception>
#include "Pair.h"

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
    void pre_order_traversal(Node* ptr_, size_t& counter);
    void in_order_traversal(Node* ptr_, size_t& counter);
    void post_order_traversal(Node* ptr_, size_t& counter);
    void clear();
    Node* GetRoot();

private:
    Node* recsch(size_t key, Node* ptr_);
    Node* root = nullptr;
};


