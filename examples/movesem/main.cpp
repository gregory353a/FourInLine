#include <iostream>
#include <string>
#include <vector>

struct X {
    explicit X(const std::string& name_)
      : name{new std::string(name_)} {
          std::cout << "Construct X name = " << *name << '\n';
    }
    X(const X& src) {
        std::cout << "Copy constructor X name = " << *(src.name) << '\n';
        name = new std::string(*(src.name));
    }
    X(X&& src) {
        std::cout << "Move constructor X src.name = " << *(src.name) << '\n';
        name = src.name;
        src.name = nullptr;
    }
    X& operator=(const X& src) {
        std::cout << "operator=(), name = " << (name == nullptr ? "nullptr": *name) << ", src.name = " << *(src.name) << '\n';
        if(this == &src) {
            std::cout << "GUARD!!!\n";
            return *this;
        }
        name = new std::string(*(src.name));
        return *this;
    }
    X& operator=(X&& src) {
        std::cout << "operator(&&), name = " << (name == nullptr ? "nullptr": *name) << ", src.name = " << *(src.name) << '\n';
        if(this == &src) {
            std::cout << "Move GUARD!!!\n";
            return *this;
        }
        name = src.name;
        src.name = nullptr;
        return *this;
    }
    ~X() {
        std::cout << "Destruct X name = " << (name == nullptr ? "nullptr": *name) << '\n';
    }
private:
    std::string * name;
};


int main() {
    X x1{"Ala"};
    X x2{"Tola"};
    x1 = x2; // operator=
    x1 = x1; // operator= & guard
    X x3{x1}; // Copy construct
    X x4{X("Zenek")}; // Nie ma przenoszącego więc kopiujący..
    X x5{std::move(x1)}; // Move constructor
    X x6 = std::move(x2); // Move construtor
    X x7 = X("Franek");

    x1 = X("Robert"); // Drogie dziecko. Tak "nie rup". x1 jest "pustakiem"
}
