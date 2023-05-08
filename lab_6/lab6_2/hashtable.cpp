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

void HashTable::add(std::string key , std::string value)
{
    size_t index = hashFunction(key, capacity_);
    size_t i = index;

    for(i = index;i < capacity_ && !hashTable[i].first.empty(); ++i);

    if(!hashTable[i].first.empty())return;

    hashTable[i].first = key;
    hashTable[i].second = value;
    ++size_;
}

size_t HashTable::find(std::string key)
{
    int index = hashFunction(key,capacity_);

    for (size_t i = index; i < capacity_; i++)
        if (hashTable[i].first == key)
            return i;
    return -1;
}
