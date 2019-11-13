#include <iostream>
#include <vector>

auto foo(int val) {
    if(val % 2) {
        return 42.3;
    }
    return 123.0;
}

template<typename T1, typename T2>
auto myMax(T1 a, T2 b) -> decltype(a + b) {
    return a > b ? a: b;
}

int main() {
    int a = 12;
    int b = 123.4;
    int c(1234.55);
    int d{1234.55};

    std::string name = "Ala";

    auto z = 12.3; // Inferencja typu...
    auto& q = z;
    const auto& r = z;

    decltype(z) g;

    std::vector<int> vec{12,3,4,5,6,7};
    for(const auto& v: vec) {
        std::cout << v << '\n';
    }

}
