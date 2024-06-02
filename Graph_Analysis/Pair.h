#pragma once
//Implementation STL pair struct
template <typename FIRST, typename SECOND>
class Pair {
private:
    FIRST firstEl;
    SECOND secondEl;

public:
    Pair() : firstEl(FIRST()), secondEl(SECOND()) {}
    Pair(const FIRST& first, const SECOND& second) : firstEl(first), secondEl(second) {}

    FIRST getFirst() const { return firstEl; }
    SECOND getSecond() const { return secondEl; }
    void setFirst(const FIRST& first) {
        firstEl = first;
    }
    void setSecond(const SECOND& second) {
        secondEl = second;
    }
};