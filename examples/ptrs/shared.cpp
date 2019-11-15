#include <iostream>
#include <string>
#include <memory>

struct X {
    X(std::string_view name_)
      : name{name_} {
          std::cout << "X construct name = " << name << '\n';
      }

    void info() const {
        std::cout << "My name = " << name << '\n';
    }
    ~X() {
        std::cout << "X destruct name = " << name << '\n';
    }

private:
    std::string name;
};

std::shared_ptr<X> foo(std::shared_ptr<X> x) {
    return x;
}

int main() {
    std::shared_ptr<X> ptr1{new X("obj1")};
    auto ptr2 = std::make_shared<X>("obj2");
    {
        auto ptr3 = std::move(ptr2);
        std::cout << "after move ptr2 count = " << ptr2.use_count() << '\n';
        auto ptr4 = ptr3;
        std::cout << "ptr3 count = " << ptr3.use_count() << '\n';
        ptr2 = std::move(ptr3);
        std::cout << "ptr2 count = " << ptr2.use_count() << '\n';
    }
    auto ptr6 = ptr2;
    auto ptr5 = foo(std::move(ptr2));
    std::cout << "in main ptr2 count = " << ptr2.use_count() << '\n';
    std::cout << "in main ptr6 count = " << ptr6.use_count() << '\n';
    std::cout << "in main ptr5 count = " << ptr5.use_count() << '\n';
    ptr5->info();
    (*ptr5).info();
    ptr6.swap(ptr1);

    std::cout << "End scope\n";
}
