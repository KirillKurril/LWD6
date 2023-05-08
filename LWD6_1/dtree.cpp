#include "dtree.h"

size_t DTree::getHeight(Node* node) {
    if (!node)
        return 0;
    return node->height;
}

size_t DTree::getBalance(Node* node) {
    if (!node)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* DTree::rightRotate(Node* node) {
    Node* x = node->left;
    Node* T2 = x->right;

    // Выполняем поворот
    x->right = node;
    node->left = T2;

    // Обновляем высоту
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    // Возвращаем новый корень
    return x;
}

// Левый поворот
Node* DTree::leftRotate(Node* node) {
    Node* y = node->right;
    Node* T2 = y->left;

    // Выполняем поворот
    y->left = node;
    node->right = T2;

    // Обновляем высоту
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    // Возвращаем новый корень
    return y;
}

Node* DTree::insert(Node * node, size_t key, QString value)
{
    if (!node)
            return(new Node(key, value));

        if (key < node->key_) {
            node->left = insert(node->left, key, value);
        }
        else if (key > node->key_) {
            node->right = insert(node->right, key, value);
        }
        // Одинаковые ключи не допускаются
        else {
            return node;
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case выполняется правый поворот вокруг несбалансированного узла
            if (balance > 1 && key < node->left->key_)
                return rightRotate(node);

            // Right Right Case выполняется левый поворот вокруг несбалансированного узла
            if (balance < -1 && key > node->right->key_)
                return leftRotate(node);

            // Left Right Case выполняется левый поворот вокруг левого поддерева несбалансированного узла, а затем правый поворот вокруг несбалансированного узла
            if (balance > 1 && key > node->left->key_) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Right Left Case выполняется правый поворот вокруг правого поддерева несбалансированного узла, а затем левый поворот вокруг несбалансированного узла
            if (balance < -1 && key < node->right->key_) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }

            /* возвращаем (неизменный) указатель узла*/
            return node;
}

Node *DTree::minValueNode(Node * node)
{
    Node* current = node;

        /*Получаем самый левый лист*/
        while (current->left)
            current = current->left;

        return current;
}

Node *DTree::deleteNode(Node * root, size_t key)
{
    // 1: Выполняем стандартное удаление
        if (!root)
            return root;

        // Если ключ удаляемого элемента меньше
        // ключа корня, тогда он лежит
        // в левом поддереве
        if (key < root->key_) {
            root->left = deleteNode(root->left, key);
        }

        // Если ключ удаляемого элемента больше
        // ключа корня, тогда он лежит
        // в правом поддереве
        else if (key > root->key_) {
            root->right = deleteNode(root->right, key);
        }

        // Если ключ совпадает с ключем корня
        // то это удаляемый элемент
        else {
            // Узел имеет только одного потомка
            // Или не имеет ни одного
            if ((!root->left) || (!root->right)) {
                Node* temp = root->left ?
                    root->left :
                    root->right;

                // Нет потомка
                if (!temp) {
                    root = nullptr;
//                    temp = root;
//                    root = new Node();
                }
                // Один потомок
                else {
                    *root = *temp; // Копируем содержимое
                                   // непустого потомка
                }
            }
            else {
                // Узел с двумя потомками: Получим преемника
                // (минимальный в правом поддереве)
                Node* temp = minValueNode(root->right);

                // Копируем данные прееемника в этот узел
                root->key_ = temp->key_;
                root->data_ = temp->data_;

                // Удаляем преемника
                root->right = deleteNode(root->right, temp->key_);
            }
        }

        // Если дерево имеет только один узел
        if (!root)
            return root;

        // 2: Обновляем высоту текущего узла
        root->height = 1 + std::max(getHeight(root->left),
            getHeight(root->right));

        // 3: Получаем баланс-фактор этого узла
        // (чтобы проверить, стал ли этот узел несбалансированным)
        int balance = getBalance(root);

        // Если этот узел стал несбалансированным
        // То есть 4 случая

        // Left Left Case
        if ((balance > 1) && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if ((balance > 1) && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if ((balance < -1) && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if ((balance < -1) && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    /*Получаем самый левый лист*/
    while (current->left)
        current = current->left;

    return current;
}

Node* DTree::findNode(Node* node, size_t key)
{
    if(!node || node->key_ == key) return node;
    if(!(node->right) && !(node->left)) return new Node(key, " ");
    return(key < node->key_) ? findNode(node->left, key) : findNode(node->right, key);
}

void DTree::pre_order_traversal(Node* ptr_, QString& output , size_t& count)
{
    if (ptr_) {
        output += ptr_->data_ + ' ';
        count +=ptr_->data_.size();
        pre_order_traversal(ptr_->left, output, count);
        pre_order_traversal(ptr_->right, output, count);
    }
}

void DTree::in_order_traversal(Node* ptr_, QString& output , size_t& count)
{
    if (ptr_) {
        in_order_traversal(ptr_->left, output, count);
        output += ptr_->data_ + ' ';
        count +=ptr_->data_.size();
        in_order_traversal(ptr_->right, output, count);

    }
}

void DTree::post_order_traversal(Node* ptr_, QString& output, size_t& count)
{
    if (ptr_) {
        post_order_traversal(ptr_->right, output, count);
        post_order_traversal(ptr_->left, output, count);
        output += ptr_->data_ + ' ';
    }
}
