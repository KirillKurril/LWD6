#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <cstdlib>
#include"mystack.h"
#include <QString>



// Универсальная хеш-функция
class UniversalHash {
public:
    UniversalHash(int size = 5) {
        m_a = (rand() % (size - 1)) + 1;
        m_b = rand() % size;
        m_p = 1000000007;
        m_size = size;
    }

    UniversalHash() = default;

    int operator()(int key) const {
        return ((m_a * key + m_b) % m_p) % m_size;
    }

private:
    int m_a;
    int m_b;
    int m_p;
    int m_size;
};

class HashTable {
public:

    MyStack* m_table = new MyStack[m_size];
    int m_size = 5;
    int m_count = 0;
    UniversalHash m_hash;

    HashTable() = default;
    HashTable(int size) : m_hash(size), m_size(size) {
    }

    void insert(int key, QString value) {
        int hash = m_hash(key);
        m_table[hash].push(Pair<int, QString>(key, value));
        ++m_count;
    }

    QString get(int key) {
        //int hash = m_hash(key);
        for(int i = 0; i < m_size; i++)
        {
            Node* ptr = m_table[i].topElement();
            while(ptr)
            {
                if (ptr->element.first == key)
                    return ptr->element.second;
                ptr = ptr->prev;
            }
        }


        return "";
    }

    void remove(int key) {
        int hash = m_hash(key);
        while (!m_table[hash].isEmpty()) {
            if (m_table[hash].topElement()->element.first == key) {
                m_table[hash].pop();
                m_count--;
                return;
            }

            hash = (hash + 1) % m_size;
        }
    }

private:

};




#endif // HASHTABLE_H
