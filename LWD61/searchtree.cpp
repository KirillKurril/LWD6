#include "searchtree.h"


//
// Created by Урфин-Джус on 29.04.2023.
//


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
            ptr = ptr->left_;
        else
            ptr = ptr->right_;
    }
    return nullptr;

}

template <typename T>
typename SearchTree<T>::Node* SearchTree<T>::recsch(size_t key, Node* ptr_)
{
    if (ptr_ == nullptr || ptr_->data.first() == key)
        return ptr_;
    else if(key > ptr_->data.first())
        return recsch(key, ptr_->right_);
    else
        return recsch(key, ptr_->left_);
}

int balance(SearchTree<T>::Node* node) {
       if (node == NULL) {
           return 0;
       }
       return height(node->left) - height(node->right);
   }

template <typename T>
   SearchTree<T>::Node* rightRotate(SearchTree<T>::Node* node) {
       SearchTree<T>::Node* left = node->left;
       SearchTree<T>::Node* rightOfLeft = left->right;

       left->right = node;
       node->left = rightOfLeft;

       node->height = max(height(node->left), height(node->right)) + 1;
       left->height = max(height(left->left), height(left->right)) + 1;

       return left;
   }

   template <typename T>
   SearchTree<T>::Node* leftRotate(SearchTree<T>::Node* node) {
       SearchTree<T>::Node* right = node->right_;
       SearchTree<T>::Node* leftOfRight = right->left_;

       right->left_ = node;
       node->right_ = leftOfRight;

       node->height = max(height(node->left_), height(node->right_)) + 1;
       right->height = max(height(right->left_), height(right->right_)) + 1;

       return right;
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
    if (!root)
    {
        root = new Node(key, value);
        return;
    }
    Node* ptr_ = root;
    while(true)
    {
        if (ptr_->data.first() == key)
            return;
        else if (key > ptr_->data.first()) {
            if (!ptr_->right_) break;
            ptr_->parent_ = ptr_;
            ptr_ = ptr_->right_;
        }
        else {
            if (!ptr_->left_) break;
            ptr_->parent_ = ptr_;
            ptr_ = ptr_->left_;
        }
    }

    if (key < ptr_->data.first()) {
        qDebug() << ptr_->left_;
        ptr_->left_ = new Node(key, value);
        ptr_->left_->parent_ = ptr_;
        qDebug() << ptr_->left_->parent_;
    }
    else {
        qDebug() << ptr_->right_;
        ptr_->right_ = new Node(key, value);
        ptr_->right_->parent_ = ptr_;
        qDebug() << ptr_->right_->parent_;
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
            node->data.setFirst(ptr_->data.first());
            node->data.setSecond(ptr_->data.second());
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

template <typename T>
void SearchTree<T>::pre_order_traversal(Node* ptr_, QString& output)
{
    if (ptr_) {
        output += ptr_->data.second() + ' ';
        pre_order_traversal(ptr_->left_, output);
        pre_order_traversal(ptr_->right_, output);
    }
}

template <typename T>
void SearchTree<T>::in_order_traversal(Node* ptr_, QString& output)
{
    if (ptr_) {
        in_order_traversal(ptr_->left_, output);
        output += ptr_->data.second() + ' ';
        in_order_traversal(ptr_->right_, output);

    }
}

template <typename T>
void SearchTree<T>::post_order_traversal(Node* ptr_, QString& output)
{
    if (ptr_) {
        post_order_traversal(ptr_->right_, output);
        post_order_traversal(ptr_->left_, output);
        output += ptr_->data.second() + ' ';
    }
}

template <typename T>
void SearchTree<T>::clear()
{
    root = nullptr;
}

template <typename T>
typename SearchTree<T>::Node* SearchTree<T>::GetRoot(){
    return root;
}
