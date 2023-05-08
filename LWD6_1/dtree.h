#ifndef DTREE_H
#define DTREE_H

#include <QString>
#include <cstddef>

struct Node{
    QString data_ = 0;
    int key_;
    Node* left = nullptr;
    Node* right = nullptr;
    size_t height;
    explicit Node (int key,const QString& value = nullptr, Node* left = nullptr, Node* right = nullptr) : key_(key), data_(value), left(left), right(right), height(0) {}
};

class DTree
{
public:
    Node* root = nullptr;
    size_t getHeight(Node*);
    Node* rightRotate(Node*);
    Node* leftRotate(Node*);
    size_t getBalance(Node*);
    Node* insert(Node*, size_t, QString);
    Node* minValueNode(Node*);
    Node* deleteNode(Node*, size_t);
    Node* findNode(Node*, size_t);
    void pre_order_traversal(Node *ptr_, QString &output, size_t& count);
    void in_order_traversal(Node *ptr_, QString &output, size_t& count);
    void post_order_traversal(Node *ptr_, QString &output, size_t& count);
};



#endif // DTREE_H
