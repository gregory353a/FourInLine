#include <iostream>

template<int VAL>
struct Fractional {
    //enum { value = Fractional<VAL - 1>::value * VAL };
    constexpr static int value = Fractional<VAL - 1>::value * VAL; // > C++11
};

template<>
struct Fractional<0> {
    //enum { value = 1 };
    constexpr static int value = 1;
};

template<int INDEX>
struct Fibonacci {
    constexpr static int value = Fibonacci<INDEX - 2>::value + Fibonacci<INDEX - 1>::value;
};

template<>
struct Fibonacci<1> {
    constexpr static int value = 1;
};

template<>
struct Fibonacci<0> {
    constexpr static int value = 0;
};

int main() {
    std::cout << Fractional<12>::value << '\n';
    std::cout << Fibonacci<6>::value << '\n';
}
