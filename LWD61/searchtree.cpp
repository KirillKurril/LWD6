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
size_t SearchTree<T>::height(SearchTree<T>::Node* node) {
        if (node == NULL) {
            return 0;
        }
        return node->height_;
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

template <typename T>
size_t SearchTree<T>::balance(SearchTree<T>::Node* node) {
       if (node == NULL) {
           return 0;
       }
       return height(node->left_) - height(node->right_);
   }

template <typename T>
typename   SearchTree<T>::Node* SearchTree<T>::rightRotate(SearchTree<T>::Node* node) {
       SearchTree<T>::Node* left = node->left_;
       SearchTree<T>::Node* rightOfLeft = left->right_;

       left->right_ = node;
       node->left_ = rightOfLeft;

       node->height_ = std::max(height(node->left_), height(node->right_)) + 1;
       left->height_ = std::max(height(left->left_), height(left->right_)) + 1;

       return left;
   }

   template <typename T>
typename SearchTree<T>::Node* SearchTree<T>::leftRotate(SearchTree<T>::Node* node) {
       SearchTree<T>::Node* right = node->right_;
       SearchTree<T>::Node* leftOfRight = right->left_;

       right->left_ = node;
       node->right_ = leftOfRight;

       node->height_ = std::max(height(node->left_), height(node->right_)) + 1;
       right->height_ = std::max(height(right->left_), height(right->right_)) + 1;

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
typename SearchTree<T>::Node* SearchTree<T>::Insert(size_t key, T value)
{
    if (!root)
    {
        root = new Node(key, value);
        return root;
    }
    Node* ptr_ = root;
    while(true)
    {
        if (ptr_->data.first() == key)
            return ptr_;
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
        ptr_->left_ = new Node(key, value);
        ptr_->left_->parent_ = ptr_;
        ptr_ = ptr_->left_;
    }
    else {
        ptr_->right_ = new Node(key, value);
        ptr_->right_->parent_ = ptr_;
        ptr_ = ptr_->right_;

    }

    ptr_->height_ = std::max(height(ptr_->left_), height(ptr_->right_)) + 1;
            int balanceFactor = balance(ptr_);

            if (balanceFactor > 1 && key < ptr_->left_->data.first()) {
                return rightRotate(ptr_);
            }
            if (balanceFactor > 1 && key > ptr_->left_->data.first()) {
                ptr_->left_ = leftRotate(ptr_->left_);
                return rightRotate(ptr_);
            }
            if (balanceFactor < -1 && key > ptr_->right_->data.first()) {
                return leftRotate(ptr_);
            }
            if (balanceFactor < -1 && key < ptr_->right_->data.first()) {
                ptr_->right_ = rightRotate(ptr_->right_);
                return leftRotate(ptr_);
            }
}

template <typename T>
typename SearchTree<T>::Node* SearchTree<T>::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left_ != NULL) {
        current = current->left_;
    }
    return current;
}

template <typename T>
typename SearchTree<T>::Node* SearchTree<T>::remove(SearchTree<T>::Node* node, size_t key)
{
    if (node == NULL) return node;
    else
    {
        if(node == root)
            {
             if (!node->right_ && !node->left_)
             {
                root = nullptr;
                return root;
             }
             else if(node->right_ && !node->left_)
             {
                root = node->right_;
                return root;
             }
             else if(!node->right_ && node->left_)
             {
                root = node->left_;
                return root;
             }
              else if(node->right_ && node->left_)
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
                 return root;
             }
            }
        if (key < node->data.first()) {
            node->left_ = remove(node->left_, key);
        } else if (key > node->data.first()) {
            node->right_ = remove(node->right_, key);
        } else {
            if (node->left_ == NULL) {
                Node* temp = node->right_;
                delete node;
                return temp;
            } else if (node->right_ == NULL) {
                Node* temp = node->left_;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right_);
            node->data.first() = temp->data.first();
            node->right_ = remove(node->right_, temp->data.first());
        }

        if (node == NULL) {
            return node;
        }

        node->height_ = 1 + std::max(height(node->left_), height(node->right_));

        int balance_ = balance(node);

        if (balance_ > 1 && balance(node->left_) >= 0) {
            return rightRotate(node);
        }

        if (balance_ > 1 && balance(node->left_) < 0) {
            node->left_ = leftRotate(node->left_);
            return rightRotate(node);
        }

        if (balance_ < -1 && balance(node->right_) <= 0) {
            return leftRotate(node);
        }

        if ((balance_ < -1) && balance(node->right_) > 0) {
            node->right_ = rightRotate(node->right_);
            return leftRotate(node);
        }

        return node;
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
