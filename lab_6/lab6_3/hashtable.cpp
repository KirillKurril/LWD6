#include "hashtable.h"
#include <cmath>

size_t hashFunction(std::string& key, size_t size)
{
    static const double A = (sqrt(5) - 1) / 2;
    double value = std::hash<std::string>()(key) * A;
    value -= std::floor(value);
    return static_cast<size_t>(std::floor(size * value));
}

HashTable::HashTable()
{
    size_=0;
    capacity_ = 1;
}

HashTable::HashTable(size_t capacity)
{
    hashTable.resize(capacity);
    size_ = 0;
    capacity_ = capacity;
}

void HashTable::add(std::string key, std::string value)
{
    std::pair<std::string, std::string> s;
    s.first = key;
    s.second = value;
    hashTable[hashFunction(key, capacity_)].push(key,value);
}

std::string HashTable::find(std::string key)
{
    size_t index = hashFunction(key, capacity_);

    for (auto it = hashTable[index].begin; it != nullptr; it = it->next)
    {
        if (it->data.first == key)
        {
            return it->data.second;
        }
    }
    return "";
}

void HashTable::remove(std::string key)
{
    size_t index = hashFunction(key,capacity_);

    for (auto it = hashTable[index].begin; it != nullptr; it = it->next)
    {

        if (it->next)
        {
            if(it->next->data.first == key)
            {
            if(it->next->next)
            {
                auto it_ = it->next->next;
                it->next=nullptr;
                it->next = it_;
            }
            else
            {
                it->next = nullptr;
            }
            }
        }
        if(it->data.first == key)
        {
            hashTable[index].begin = it->next;
        }
    }
}

QString HashTable::print()
{
    QString information;
    for (size_t i = 0; i < capacity_; i++)
    {
            for (auto it = hashTable[i].begin; it != nullptr; it = it->next)
            {
                information += it->data.first.c_str();
                information += " ";
                information += it->data.second.c_str();
                information += '\n';
            }
    }
    return information;
}
