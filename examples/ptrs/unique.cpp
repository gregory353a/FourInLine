#include <iostream>
#include <string>
#include <memory>

struct X {
    X(std::string_view name_)
      : name{name_} {
          std::cout << "X construct name = " << name << '\n';
      }
    ~X() {
        std::cout << "X destruct name = " << name << '\n';
    }

private:
    std::string name;
};

void foo(std::unique_ptr<X> x) {
    (void) x;
}

std::unique_ptr<X> makeX(const std::string& name) {
    return std::make_unique<X>(name);
}

int main() {
    std::unique_ptr<X> ptr1{new X("obj1")};
    std::unique_ptr<X> ptr4;
    {
        std::unique_ptr<X> ptr2 = std::make_unique<X>("obj2");
        std::unique_ptr<X> ptr3;
        ptr3 = std::move(ptr1);
        ptr4 = std::move(ptr3);
        if(!ptr3) {
            std::cout << "ptr3 nie ma obiektu\n";
        } else {
            std::cout << "ptr3 ma obiekt\n";
        }
    }
    std::cout << "End scope\n";
    std::unique_ptr<X> ptr5 = std::make_unique<X>("obj3");
    foo(std::move(ptr5));

    auto ptr6 = makeX("obj4");
    auto old_ptr = new X("obj5");
    ptr6.reset(old_ptr);

    std::cout << "End main\n";
}
