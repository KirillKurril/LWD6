#ifndef MYSTACK_H
#define MYSTACK_H

#include "dvector.h"
#include <QString>

template <typename T1, typename T2>
class Pair {
public:
    Pair() : first(), second() {}
    Pair(const T1& t1, const T2& t2) : first(t1), second(t2) {}

    T1 first;
    T2 second;
};

class Node
{
public:
    DVector<Pair<int, QString>> element;
    Node* prev;
    Node();
    Node(const Node & ref);
    ~Node();
};

class MyStack
{
private:
    Node* top;
    int amount;

public:
    MyStack();
    ~MyStack();

    void push(char a);
    Node* pop();
    Node* topElement();
    int count();
    bool isEmpty();

};

#endif // MYSTACK_H
