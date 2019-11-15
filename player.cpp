#include "player.hpp"
#include "board.hpp"
#include <iostream>
#include <limits>

using namespace std::string_literals;

namespace {

template<typename Predicate>
unsigned unsignedInput(std::string_view msg, std::string_view err_msg, Predicate check) {
    unsigned column;
    for(;;) {
        std::cout << msg;
        std::cin >> column;
        if(std::cin && check(column)) {
            break;
        }
        std::cerr << err_msg;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return column;
}
} // anonumous namespace

Player::Player(const std::string& name_, TokenColor color_)
    : name{name_}, color{color_} {
}

TokenColor Player::getColor() const {
    return color;
}

const std::string& Player::getName() const {
    return name;
}

unsigned Player::getColumn() const {
    std::string msg = "Column [1, "s + std::to_string(Board::BoardWidth) + "]: "s;
    std::string err_msg = "Incorrect column! Try again!\n";
    return unsignedInput(msg, err_msg, [](unsigned value) { return (value > 0) && (value <= Board::BoardWidth); });
}
