#ifndef AVLTREE_H
#define AVLTREE_H

#include <QString>
#include "pair.h"
#include <algorithm>
#include <cstddef>

template<typename T>
class AVLTree {
public:
    struct Node {
        Pair<size_t, T> data;
        Node* left_ = nullptr;
        Node* right_ = nullptr;
        Node* parent_ = nullptr;
        size_t height_ = 1;

        explicit Node(int key, T value = nullptr, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr)
            : data(key, value), left_(left), right_(right), parent_(parent) {}
    };

    void pre_order_traversal(Node* ptr_, QString& output){
        if (ptr_) {
            output += ptr_->data.second() + ' ';
            pre_order_traversal(ptr_->left_, output);
            pre_order_traversal(ptr_->right_, output);
        }
    }
    void in_order_traversal(Node* ptr_, QString& output)
    {
        if (ptr_) {
            in_order_traversal(ptr_->left_, output);
            output += ptr_->data.second() + ' ';
            in_order_traversal(ptr_->right_, output);

        }
    }
    void post_order_traversal(Node* ptr_, QString& output)
    {
        if (ptr_) {
            post_order_traversal(ptr_->right_, output);
            post_order_traversal(ptr_->left_, output);
            output += ptr_->data.second() + ' ';
        }
    }

    // Вставка ключа в дерево
    void insert(int key, T value) {
        if (!root_) {
            root_ = new Node(key, value);
        } else {
            insertHelper(root_, key, value);
        }
    }

    // Удаление ключа из дерева
    void remove(int key) {
        if (!root_) {
            return;
        }

        Node* node = findNode(root_, key);
        if (!node) {
            return;
        }

        if (!node->left_ || !node->right_) {
            removeNode(node);
        } else {
            Node* successor = findSuccessor(node);
            node->data = successor->data;
            removeNode(successor);
        }
    }

    // Вспомогательный метод для вставки узла в дерево
    Node* insertHelper(Node* node, int key, T value) {
        if (!node) {
            return new Node(key, value);
        }

        if (key < node->data.first()) {
            node->left_ = insertHelper(node->left_, key, value);
        } else {
            node->right_ = insertHelper(node->right_, key, value);
        }

        updateHeight(node);
        return balanceNode(node);
    }

    // Вспомогательный метод для удаления узла из дерева
    void removeNode(Node* node) {
        Node* parent = node->parent_;
        Node* child = node->left_ ? node->left_ : node->right_;

        if (child) {
            child->parent_ = parent;
        }

        if (!parent) {
            root_ = child;
        } else if (node == parent->left_) {
            parent->left_ = child;
        } else {
            parent->right_ = child;
        }

        delete node;
        rebalance(parent);
    }

    // Вспомогательный метод для поиска узла по ключу
    Node* findNode(Node* node, int key) const {
        if (!node) {
            return nullptr;
        }

        if (key == node->data.first() ) {
            return node;
        } else if (key < node->data.first()) {
            return findNode(node->left_, key);
        } else {
            return findNode(node->right_, key);
        }
    }

    Node* GetRoot(){
        return root_;
    }

    Node* findSuccessor(Node* node) const {
        Node* current = node->right_;
        while (current->left_) {
            current = current->left_;
        }
        return current;
    }

    // Вспомогательный метод для пересчета высоты узла
    void updateHeight(Node* node) {
        node->height_ = 1 + std::max(getHeight(node->left_), getHeight(node->right_));
    }

    // Вспомогательный метод для пересчета баланса узла
    int getBalanceFactor(Node* node) const {
        return getHeight(node->right_) - getHeight(node->left_);
    }

    // Вспомогательный метод для поворота вправо
    Node* rotateRight(Node* node) {
        Node* new_root = node->left_;
        node->left_ = new_root->right_;
        if (new_root->right_) {
            new_root->right_->parent_ = node;
        }
        new_root->right_ = node;
        new_root->parent_ = node->parent_;
        node->parent_ = new_root;
        updateHeight(node);
        updateHeight(new_root);
        return new_root;
    }

    // Вспомогательный метод для поворота влево
    Node* rotateLeft(Node* node) {
        Node* new_root = node->right_;
        node->right_ = new_root->left_;
        if (new_root->left_) {
            new_root->left_->parent_ = node;
        }
        new_root->left_ = node;
        new_root->parent_ = node->parent_;
        node->parent_ = new_root;
        updateHeight(node);
        updateHeight(new_root);
        return new_root;
    }

    // Вспомогательный метод для балансировки узла
    Node* balanceNode(Node* node) {
        updateHeight(node);
        int balance_factor = getBalanceFactor(node);
        if (balance_factor == 2) {
            if (getBalanceFactor(node->right_) < 0) {
                node->right_ = rotateRight(node->right_);
            }
            return rotateLeft(node);
        }
        if (balance_factor == -2) {
            if (getBalanceFactor(node->left_) > 0) {
                node->left_ = rotateLeft(node->left_);
            }
            return rotateRight(node);
        }
        return node;
    }
    Node* deleteNode(Node* node) {
        if (!node->left_ && !node->right_) {
            if (node->parent_) {
                if (node == node->parent_->left_) {
                    node->parent_->left_ = nullptr;
                } else {
                    node->parent_->right_ = nullptr;
                }
                delete node;
                return balanceNode(node->parent_);
            } else {
                delete node;
                return nullptr;
            }
        } else if (!node->left_) {
            node->right_->parent_ = node->parent_;
            Node* new_root = node->right_;
            delete node;
            return balanceNode(new_root);
        } else if (!node->right_) {
            node->left_->parent_ = node->parent_;
            Node* new_root = node->left_;
            delete node;
            return balanceNode(new_root);
        } else {
                // Node has two children
                Node* successor = findSuccessor(node);
                std::swap(node->data, successor->data);
                return deleteNode(successor);
            }
        }
    int getHeight(Node* node) const {
           if (!node) {
               return 0;
           }
           return node->height_;
       }

       void rebalance(Node* node) {
           if (!node) {
               return;
           }
           if (getHeight(node->left_) - getHeight(node->right_) > 1) {
               if (getHeight(node->left_->left_) >= getHeight(node->left_->right_)) {
                   node = rotateRight(node);
               } else {
                   node->left_ = rotateLeft(node->left_);
                   node = rotateRight(node);
               }
           } else if (getHeight(node->right_) - getHeight(node->left_) > 1) {
               if (getHeight(node->right_->right_) >= getHeight(node->right_->left_)) {
                   node = rotateLeft(node);
               } else {
                   node->right_ = rotateRight(node->right_);
                   node = rotateLeft(node);
               }
           }
           if (node->parent_) {
               rebalance(node->parent_);
           } else {
               root_ = node;
           }
       }
private:
    Node* root_ = nullptr;
};



#endif // AVLTREE_H
