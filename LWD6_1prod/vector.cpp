#include "vector.h"

template<typename T>
DVector<T>::DVector()
{
    arr = NULL;
    cap = 1;
    sz = 0;
    //reserve(1);
}

template<typename T>
DVector<T>::DVector(T& a1, T& a2, T& a3)
{
    arr = NULL;
    cap = 1;
    sz = 0;
    //reserve(3);
    this->push_back(a1);
    this->push_back(a2);
    this->push_back(a3);
}
template<typename T>
DVector<T>::DVector(T& a1, T& a2)
{
    arr = NULL;
    cap = 1;
    sz = 0;
    //reserve(2);
    this->push_back(a1);
    this->push_back(a2);
}

template<typename T>
DVector<T>::Iterator::Iterator(DVector<T>* vector, int nIndex) : itVector(vector), itIndex(nIndex) {}

template<typename T>
const T& DVector<T>::Iterator::operator*() const {
    return itVector->operator[](itIndex);
}

template<typename T>
typename DVector<T>::Iterator& DVector<T>::Iterator::operator++() {
    ++itIndex;
    return *this;
}

template<typename T>
bool DVector<T>::Iterator::operator!=(const Iterator& other) const {
    return itIndex != other.itIndex;
}

template<typename T>
typename DVector<T>::Iterator& DVector<T>::Iterator::operator+(const int& other) {
    itIndex += other;
    return *this;
}

template<typename T>
typename DVector<T>::Iterator& DVector<T>::Iterator::operator-(const int& other) {
    itIndex -= other;
    return *this;
}

template<typename T>
DVector<T>::rIterator::rIterator(DVector<T>* vector, int nIndex) : itVector(vector), itIndex(nIndex) {}

template<typename T>
const T& DVector<T>::rIterator::operator*() const {
    return itVector->operator[](itIndex);
}

template<typename T>
typename DVector<T>::rIterator& DVector<T>::rIterator::operator++() {
    --itIndex;
    return *this;
}

template<typename T>
bool DVector<T>::rIterator::operator!=(const rIterator& other) const {
    return itIndex != other.itIndex;
}

template<typename T>
typename DVector<T>::rIterator& DVector<T>::rIterator::operator+(const int& other) {
    itIndex -= other;
    return *this;
}

template<typename T>
typename DVector<T>::rIterator& DVector<T>::rIterator::operator-(const int& other) {
    itIndex += other;
    return *this;
}

template<typename T>
void DVector<T>::assign(size_t n, T value)
{
    while (!this->empty())
        this->pop_back();
    for (int i = 0; i < n; i++)
        this->push_back(value);
 }

template<typename T>
T& DVector<T>::operator[](const size_t i)
{
    if (i >= sz) throw std::out_of_range("....");
    return arr[i];
}

template<typename T>
T* DVector<T>::at(size_t i)
{
    if (i >= sz) throw std::out_of_range('....');
    return &arr[i];
}

template<typename T>
T* DVector<T>::back()
{
    return &arr[sz - 1];
}

template<typename T>
size_t DVector<T>::capacity()
{
    return cap;
}

template<typename T>
const T* DVector<T>::cbegin()
{
    return &arr[0];
}

template<typename T>
T* DVector<T>::data()
{
    return arr;
}

template<typename T>
bool DVector<T>::empty()
{
    return sz == 0;
}

template<typename T>
size_t DVector<T>::max_size()
{
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength = sizeof(memoryStatus);

    GlobalMemoryStatusEx(&memoryStatus);

    size_t freeMemory = static_cast<size_t>(memoryStatus.ullAvailPhys);

    return freeMemory / sizeof(T);
}

template<typename T>
void DVector<T>::pop_back()
{
    if (this->empty()) return;
    (arr + sz - 1)->~T();
    --sz;
}

template<typename T>
void DVector<T>::push_back(const T& value)
{
    if (sz == 0)
    {
        reserve(1);
    }
    if (sz == cap)
    {
        reserve(cap *= 2);
    }
    new (arr + sz) T(value);
    ++sz;
}

template<typename T>
void DVector<T>::reserve(size_t n)
{
    if (n < cap) return;
    T* newarr = reinterpret_cast<T*>(new uint8_t[n * sizeof(T)]);
    memcpy(newarr, arr, sz * sizeof(T));
    /*
    for (size_t i = 0; i < sz; ++i)
    {
        new(newarr + i) T(arr[i]);
    }
    for (size_t i = 0; i < sz; ++i)
    {
        (arr + i)->~T();
    }
*/
    if (arr != NULL) {
        delete[] reinterpret_cast<uint8_t*>(arr);
        arr = NULL;
    }

    arr = reinterpret_cast<T*>(new uint8_t[n * sizeof(T)]);
    memcpy(arr, newarr, sz * sizeof(T));

    delete[] reinterpret_cast<uint8_t*>(newarr);
    newarr = NULL;
    //arr = newarr;
}

template<typename T>
void DVector<T>::resize(size_t n)
{
    if (n >= cap) reserve(n * 2);
    T* newarr = new T[n];
    for (size_t i = 0; i < sz; ++i)
    {
        new(newarr + i) T(arr[i]);
    }
    for (size_t i = 0; i < sz; ++i)
    {
        (arr + i)->~T();
    }

    if (arr != NULL) {
        delete[] reinterpret_cast<uint8_t*>(arr);
        arr = NULL;
    }

    arr = reinterpret_cast<T*>(new uint8_t[n * sizeof(T)]);
    memcpy(arr, newarr, n * sizeof(T));

    delete[] reinterpret_cast<uint8_t*>(newarr);
    newarr = NULL;
    //arr = newarr;

}

template<typename T>
size_t DVector<T>::size()
{
    return sz;
}

template<typename T>
void DVector<T>::swap(DVector& newvector)
{
    size_t stp = sz;
    size_t ctp = cap;
    T* arrtp = arr;

    this->setSz(newvector.size());
    this->setCap(newvector.capacity());
    this->setArr(newvector.data());

    newvector.setSz(stp);
    newvector.setCap(ctp);
    newvector.setArr(arrtp);
}

template<typename T>
void DVector<T>::setSz(size_t value)
{
    sz = value;
}

template<typename T>
void DVector<T>::setCap(size_t value)
{
    cap = value;
}

template<typename T>
void DVector<T>::setArr(T* value)
{
    arr = value;
}

template<typename T>
void DVector<T>::erase(size_t index)
{

    if (index >= sz) return;
    for (size_t i = index + 1; i < sz; ++i) {
        /*arr[i - 1] = arr[i];*/ new(arr + i - 1) T(arr[i]);
    }
    sz--;

}
//+
template<typename T>
void DVector<T>::insert(const size_t index, T const& value)
{
    if (index > sz) return;
    if (index == sz)
    {
        push_back(value);
        return;
    }
    resize(++sz);


    for (size_t i = sz - 1; i != index; --i) {
        new(arr + i) T(arr[i - 1]);
    }
     new(arr + index) T(value);
}

template<typename T>
void DVector<T>::clear()
{
   while(sz)
    {
        (arr + sz - 1)->~T();
        sz--;
    }

    delete[] reinterpret_cast<uint8_t*>(arr);
    arr = NULL;
    cap = 1;
}

template<typename T>
T* DVector<T>::front()
{
    return &arr[0];
}

template<typename T>
typename DVector<T>::Iterator DVector<T>::begin() {
    Iterator it(this, 0);
    return it;
}

template<typename T>
typename DVector<T>::Iterator DVector<T>::end()
{
    Iterator it(this, sz - 1);
    return it;
}

template<typename T>
typename DVector<T>::rIterator DVector<T>::rbegin()
{
    rIterator it(this, sz - 1);
    return it;
}

template<typename T>
typename DVector<T>::rIterator DVector<T>::rend()
{
    Iterator it(this, 0);
    return it;
}

template<typename T>
void DVector<T>::print()
{
    for (int i = 0; i < sz; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

template<typename T>
void DVector<T>::del()
{
    for (size_t i = 0; i < sz; ++i)
    {
        (arr + i)->~T();
    }
    delete[] reinterpret_cast<uint8_t*>(arr);
}

template<typename T>
DVector<T>::~DVector()
{

}

template<typename T>
template<typename... T1>
void DVector<T>::emplace_back(T1&&... value)
{
    if (sz == 0)
    {
        reserve(1);
    }
    if (sz == cap)
    {
        reserve(cap *= 2);
    }
    new (arr + sz) T(std::forward<T1>(value)...);
    ++sz;
}

template<typename T>
template<typename... T1>
void DVector<T>::emplace(const size_t index, T1&&... value)
{
    if (index > sz) return;
    if (index == sz)
    {
        emplace_back(std::forward<T1>(value)...);
        return;
    }
    resize(++sz);


    for (size_t i = sz - 1; i != index; --i) {
        new(arr + i) T(arr[i - 1]);
    }
    new(arr + index) T(std::forward<T1>(value)...);
}

