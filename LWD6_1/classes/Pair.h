//
// Created by Урфин-Джус on 29.04.2023.
//

#ifndef LWD6_1_PAIR_H
#define LWD6_1_PAIR_H


template<typename T1, typename  T2>
class Pair{
public:
    T1& first() { return _first; }
    T2& second() { return _second; }

    void setFirst(const T1& first) { _first = first; }
    void setSecond(const T2& second) { _second = second; }
    Pair(T1 first, T2 second) : _first(first), _second(second){}
private:
    T1 _first = nullptr;
    T2 _second = nullptr;
};


#endif //LWD6_1_PAIR_H
