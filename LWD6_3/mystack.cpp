#include "mystack.h"

MyStack::MyStack()
{
    amount = 0;
    top = nullptr;
}

MyStack::~MyStack()
{
    while(!this->isEmpty()){
        this->pop();
    }
}

void MyStack::push(Pair<int, QString> a)
{
    Node* temp = new Node;
    temp->element = a;
    temp->prev = this->topElement();
    top = temp;
    ++amount;
}

Node *MyStack::pop()
{
    if(!this->isEmpty()){
        Node* temp = new Node;
        temp->prev = top->prev;
        temp->element = top->element;
        top = top->prev;
        --amount;
        return temp;
    }
}

Node* MyStack::topElement()
{
    return top;
}

int MyStack::count()
{
    return amount;
}

bool MyStack::isEmpty()
{
    if (!amount) return 1;
    return 0;
}

Node::Node()
{
    prev = nullptr;
}

Node::Node(const Node &ref)
{
    prev = ref.prev;
    element = ref.element;
}

Node::~Node()
{
    delete this->prev;
    delete this;
}
