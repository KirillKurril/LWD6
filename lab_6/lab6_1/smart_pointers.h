#ifndef SMART_POINTERS_H
#define SMART_POINTERS_H

#include "iostream"

template<typename T>
class shared_ptr
{
private:
    T *ptr = nullptr;
    int *countOf = nullptr;
public:
    shared_ptr() {}

    shared_ptr(shared_ptr const &second)
    {
        this->ptr = second.ptr;
        this->countOf = second.countOf;
        if (countOf != nullptr) {
            (*countOf)++;
        }
    }

    shared_ptr(T *p)
    {
        this->ptr = p;
        this->countOf = new int(1);
    }

    void operator=(T* p)
    {
        this->ptr = p;
        this->countOf = new int(1);
    }

    ~shared_ptr()
    {
        if (countOf != nullptr) {
            (*countOf)--;
            if (*countOf == 0) {
                delete ptr;
                delete countOf;
            }
        }
    }

    operator bool() const
    {
        if (countOf == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    int use_count()
    {
        if (countOf != nullptr) {
            return *countOf;
        }
    }

    void swap(shared_ptr &second) {
        std::swap(this->ptr, second.ptr);
        std::swap(this->countOf, second.countOf);
    }

    T *get()
    {
        return ptr;
    }

    void operator=(const shared_ptr &second) {
        if (this != &second) {
            if (countOf != nullptr) {
                (*countOf)--;
                if (*countOf == 0) {
                    delete ptr;
                    delete countOf;
                }
            }
            ptr = second.ptr;
            countOf = second.countOf;
            if (countOf != nullptr) {
                (*countOf)++;
            }
        }
    }

    T *operator->() {
        return this->ptr;
    }

    T& operator*() {
//        if (this->ptr != nullptr)
            return *this->ptr;
    }

    void reset(T *p= nullptr) {
        shared_ptr pt(p);
        this->swap(pt);
    }
};

template<typename T,typename... Args>
shared_ptr<T> make_shared(Args&&... args) {
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T>
class shared_ptr<T[]> {
private:
private:
    T *ptr = nullptr;
    int *countOf = nullptr;
public:
    shared_ptr() {}

    shared_ptr(const shared_ptr  &second) {
        this->ptr = second.ptr;
        this->countOf = second.countOf;
        if (countOf != nullptr) {
            (*countOf)++;
        }
    }

    shared_ptr(T *p) {
        this->ptr = p;
        this->countOf = new int(1);
    }

    void operator=(T* p)
    {
        this->ptr = p;
        this->countOf = new int(1);
    }

    ~shared_ptr() {
        if (countOf != nullptr) {
            (*countOf)--;
            if (*countOf == 0) {
                delete[] ptr;
                delete countOf;
            }
        }
    }

    operator bool() const{
        if (countOf == nullptr) {
            return false;
        } else {
            return true;
        }
    }

    int use_count() {
        if (countOf != nullptr) {
            return *countOf;
        }
    }

    void swap(shared_ptr &second) {
        std::swap(this->ptr, second.ptr);
        std::swap(this->countOf, second.countOf);
    }

    T *get()
    {
        return ptr;
    }

    void operator=(const shared_ptr &second) {
        if (this != &second) {
            if (countOf != nullptr) {
                (*countOf)--;
                if (*countOf == 0) {
                    delete[] ptr;
                    delete countOf;
                }
            }
            ptr = second.ptr;
            countOf = second.countOf;
            if (countOf != nullptr) {
                (*countOf)++;
            }
        }
    }

    T *operator->()
    {
        return this->ptr;
    }

    T &operator*()
    {
            return *this->ptr;
    }

    void reset(T *p= nullptr)
    {
        shared_ptr pt(p);
        this->swap(pt);
    }
};
template<typename T,typename... Args>
shared_ptr<T[]> make_shared(Args&&... args) {
    return shared_ptr<T[]>(new T(std::forward<Args>(args)...));
}

template<typename T>
class UniquePtr {
private:
    T *ptr = nullptr;
public:
    UniquePtr() {
        ptr = nullptr;
    }

    UniquePtr(T *p) {
        ptr = p;
    }

    UniquePtr(UniquePtr const &second) = delete;

    UniquePtr(UniquePtr &&second) {
        ptr = second.ptr;
        second.ptr = nullptr;
    }

~UniquePtr() {
        delete ptr;
    }

    UniquePtr &operator=(UniquePtr &second) = delete;

    UniquePtr &operator=(UniquePtr &&second) noexcept {
        if (this != &second) {
            delete this->ptr;
            this->ptr = second.ptr;
            second.ptr = nullptr;
        }
        return *this;
    }

    T &operator*() noexcept {
        if (this->ptr != nullptr) {
            return *this->ptr;
        }
    }

    T *operator->() noexcept {
        if (this->ptr != nullptr) {
            return this->ptr;
        }
        return nullptr;
    }

    T *get() noexcept {
        if (this->ptr != nullptr) {
            return this->ptr;
        }
    }

    void reset(T *p) {
        delete ptr;
        ptr = p;
    }

    void swap(UniquePtr &second) noexcept {
        std::swap(this->ptr, second.ptr);
    }
};

template<typename T>
class UniquePtr<T[]> {
private:
    T *ptr = nullptr;
public:
    UniquePtr() {
        ptr = nullptr;
    }

    UniquePtr(T *p) {
        ptr = p;
    }

    UniquePtr(UniquePtr const &second) = delete;

    UniquePtr(UniquePtr &&second) {
        ptr = second.ptr;
        second.ptr = nullptr;
    }

    ~UniquePtr() {
        delete[] ptr;
    }

    UniquePtr &operator=(UniquePtr &second) = delete;

    UniquePtr &operator=(UniquePtr &&second) noexcept {
        if (this != &second) {
            delete[] this->ptr;
            this->ptr = second.ptr;
            second.ptr = nullptr;
        }
        return *this;
    }

    T &operator*() noexcept {
        if (this->ptr != nullptr) {
            return *this->ptr;
        }
    }

    T *operator->() noexcept {
        if (this->ptr != nullptr) {
            return this->ptr;
        }
        return nullptr;
    }

    T *get() noexcept {
        if (this->ptr != nullptr) {
            return this->ptr;
        }
    }

    void reset(T *p) {
        delete[] ptr;
        ptr = p;
    }

    void swap(UniquePtr &second) noexcept {
        std::swap(this->ptr, second.ptr);
    }
};

#endif // SMART_POINTERS_H
