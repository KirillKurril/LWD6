//
// Created by Урфин-Джус on 29.04.2023.
//

#include "SearchTree.h"

template <typename T>
bool SearchTree<T>::IsEmpty()
{
    if(!root->data.first()) return true;
    else return false;
}

template <typename T>
T SearchTree<T>::IterSearch(size_t key)
{
    if (this->IsEmpty())
    {
        std::cout<<"The tree's empty";
        system("pause");
        exit(1);
    }
    Node* ptr = root;
    while(ptr)
    {
        if (ptr->data.first() == key)
            return ptr->data.second();
        else if (ptr->data.first() < key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    return nullptr;

}

template <typename T>
typename SearchTree<T>::Node* SearchTree<T>::recsch(size_t key, Node* ptr_)
{
    if (ptr_->data.first() == key || ptr_ == nullptr)
        return ptr_;
    else if(ptr_->data.first() < key)
        return recsch(key, ptr_->left_);
    else
        return recsch(key, ptr_->right_);
}

template <typename T>
T SearchTree<T>::RecSearch(size_t key)
{
    Node* node = recsch(key, root);
    if(node)
        return node->data.second();
    else
        return nullptr;
}

template <typename T>
void SearchTree<T>::Insert(size_t key, T value)
{
    Node* ptr_ = root;
    while(ptr_)
    {
        if (ptr_->data.first() == key)
            return;
        else if (ptr_->data.first() < key) {
            ptr_->parent_ = ptr_;
            ptr_ = ptr_->left;
        }
        else {
            ptr_->parent_ = ptr_;
            ptr_ = ptr_->right;
        }
    }
    ptr_ = new Node(key, value);
    if (ptr_->data.first() < ptr_->parent_->data.first()) {
        ptr_->parent_->left_ = ptr_;
    }
    else {
        ptr_->parent_->right_ = ptr_;
    }
}

template <typename T>
void SearchTree<T>::remove(size_t key)
{
    Node* node = recsch(key, root);
    if(!node)
        return;
    else
    {
        if (!node->right_ && !node->left_)
        {
            if(node == root)
            {
                root = nullptr;
                return;
            }
            if (node->data.first() < node->parent_->data.first()) {
                node->parent_->left_ = nullptr;
            }
            else {
                node->parent_->right_ = nullptr;
            }
        }
        if(node->right_ && !node->left_)
        {
            if(node == root)
            {
                root = node->right_;
                return;
            }
            if (node->right_->data.first() < node->parent_->data.first()) {
                node->parent_->left_ = node->right_;
                node->right_->parent_ = node->parent_;
            }
            else {
                node->parent_->right_ = node->right_;
                node->right_->parent_ = node->parent_;
            }
        }
        if(!node->right_ && node->left_)
        {
            if(node == root)
            {
                root = node->left_;
                return;
            }
            if (node->left_->data.first() < node->parent_->data.first()) {
                node->parent_->left_ = node->left_;
                node->left_->parent_ = node->parent_;
            }
            else {
                node->parent_->right_ = node->left_;
                node->left_->parent_ = node->parent_;
            }
        }
        if(node->right_ && node->left_)
        {
            Node* ptr_ = node->right_;
            while (ptr_)
                ptr_ = ptr_->left_;
            ptr_=ptr_->parent_;
            node->data.setFirst() = ptr_->data.first();
            node->data.setSecond() = ptr_->data.second();
            if(ptr_->right_)
            {
                ptr_->parent_->left_ = ptr_->right_;
                ptr_->right_->parent_ = ptr_->parent_;
            }
            else
            ptr_->parent_->left_ = nullptr;
        }
    }
}