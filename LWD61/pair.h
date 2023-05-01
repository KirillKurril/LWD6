#ifndef PAIR_H
#define PAIR_H


template<typename T1, typename  T2>
class Pair{
public:
    T1& first() { return _first; }
    T2& second() { return _second; }

    void setFirst(const T1& first) { _first = first; }
    void setSecond(const T2& second) { _second = second; }
    Pair(T1 first, T2 second) : _first(first), _second(second){}
    Pair() : _first(), _second() {}


private:
    T1 _first = nullptr;
    T2 _second = nullptr;
};
#endif // PAIR_H
