#include <iostream>

void foo(int&& val) {
    std::cout << "foo()\n";
}

void runner(void (*fun)(int&&), int&& val) {
    fun(std::move(val));
}

template<typename Function, typename... Args>
void trunner(Function fun, Args&&... args) {
    std::cout << "Przekazano " << sizeof...(args) << " argument\n";
    fun(std::forward<Args>(args)...);
}

int main() {
    runner(foo, int(12));
    trunner(foo, int(12));

}
