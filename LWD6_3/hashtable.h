#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <cstdlib>
#include"mystack.h"



// Универсальная хеш-функция
class UniversalHash {
public:
    UniversalHash(int size) {
        m_a = rand() % (size - 1) + 1;
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
    HashTable(int size) {
        m_table.resize(size);
        m_size = size;
        m_count = 0;
        m_maxCollisions = 0;
        m_totalCollisions = 0;
        m_hash = UniversalHash(size);
    }

    void insert(int key, string value) {
        int hash = m_hash(key);
        while(m_table[hash].first != -1)
        {
            if (m_table[hash].first == key)
            {
                m_table[hash].second = value;
                return;
            }
            hash = (hash + 1) % m_size;
        }
        m_table[hash] = make_pair(key, value);

    }

    string get(int key) {
        int hash = m_hash(key);

        while (m_table[hash].first != -1) {
            if (m_table[hash].first == key) {
                return m_table[hash].second;
            }

            hash = (hash + 1) % m_size;
        }

        return "";
    }

    void remove(int key) {
        int hash = m_hash(key);
        while (m_table[hash].first != -1) {
            if (m_table[hash].first == key) {
                m_table[hash].first = -1;
                m_table[hash].second = "";
                m_count--;
                return;
            }

            hash = (hash + 1) % m_size;
        }
    }



private:
    m_table;
    int m_size;
    int m_count;
    int m_maxCollisions;
    int m_totalCollisions;
    UniversalHash m_hash;
};




#endif // HASHTABLE_H
