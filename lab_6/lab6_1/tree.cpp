#include "tree.h"

Tree::Tree()
{

}

size_t Tree::getHeight(shared_ptr<Node> node)
{
    return(node) ? node->height : 0;
}

size_t Tree::getBalance(shared_ptr<Node> node)
{
    return(node) ? getHeight(node->left) - getHeight(node->right) : 0;
}

shared_ptr<Node> Tree::rightRotate(shared_ptr<Node> node)
{
    shared_ptr<Node> left = node->left;
    shared_ptr<Node> leftRight = left->right;
    left->right = node;
    node->left = leftRight;

    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    left->height = std::max(getHeight(left->left), getHeight(left->right)) + 1;

    return left;
}

shared_ptr<Node> Tree::leftRotate(shared_ptr<Node> node)
{
    shared_ptr<Node> right = node->right;
    shared_ptr<Node> rightLeft = right->left;
    right->left = node;
    node->right = rightLeft;

    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    right->height = std::max(getHeight(right->left), getHeight(right->right)) + 1;

    return right;
}

shared_ptr<Node> Tree::insert(shared_ptr<Node> node, size_t key, std::string value)
{
    if(!node) return new Node(key,value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int  balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

shared_ptr<Node> Tree::minValueNode(shared_ptr<Node> node)
{
    shared_ptr<Node> current = node;

    while (current->left)
        current = current->left;

    return current;
}

 shared_ptr<Node> Tree::deleteNode(shared_ptr<Node> node, size_t key)
 {
    if (!node) return node;

    if (key < node->key)
        node->left = deleteNode(node->left, key);

    else if (key > node->key)
        node->right = deleteNode(node->right, key);

    else
    {
        if ((!node->left) || (!node->right))
        {
            shared_ptr<Node> temp = node->left ? node->left : node->right;

            if (!temp)
            {
                temp = node;
                node = shared_ptr<Node>();
            }
            else
                *node = *temp;
            }
        else
        {
            shared_ptr<Node> temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (!node)
        return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 &&
    getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 &&  getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void Tree::directBypass(shared_ptr<Node> node, std::vector<std::string>& vector)
{
    if (!node.get()) return;
    std::string information;
    information += QString::number(node->key).toStdString();
    information += " ";
    information += node->value.c_str();
    information += '\n';
    vector.push_back(information);
    directBypass(node->left, vector);
    directBypass(node->right, vector);
}

void Tree::reverseBypass(shared_ptr<Node> node, std::vector<std::string>& vector)
{
    if (!node.get()) return;
    directBypass(node->left, vector);
    directBypass(node->right, vector);
    std::string information;
    information += QString::number(node->key).toStdString();
    information += " ";
    information += node->value.c_str();
    information += '\n';
    vector.push_back(information);
}

shared_ptr<Node> Tree::findNode(shared_ptr<Node> node, size_t key)
{
    if(!node || node->key == key) return node;

    return(key < node->key) ? findNode(node->left, key) : findNode(node->right, key);
}
