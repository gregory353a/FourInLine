#include <future>
#include <iostream>

int worker() {
    std::cout << "Works!\n";
    return 42;
}

int main() {
    std::future<int> ftr = std::async(std::launch::async, worker);
    std::cout << ftr.get() << '\n';
    //std::cout << ftr.get() << '\n';
}
