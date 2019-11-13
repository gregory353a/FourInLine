#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b) {
    if(b == 0) {
        return {};
    }
    return std::make_optional<int>(a / b);
}

int main() {
    auto result = divide(10, 0);
    if(result) {
        std::cout << "Rezultat to: " << *result << '\n';
    } else {
        std::cout << "Niestety nie ma wyniku! Ale w zamian masz: " << result.value_or(-1) << '\n';
    }
}
