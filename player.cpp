#include "player.hpp"
#include "settings.hpp"
#include "displayer.hpp"
#include <limits>

using namespace std::string_literals;

namespace {

bool checkColumnRange(unsigned column) {
    return (column > 0) && (column <= BoardWidth);
}

} // anonumous namespace

Player::Player(const std::string& name_, TokenColor color_, Displayer& displayer_)
    : name{name_}, color{color_}, displayer{displayer_} {
}

TokenColor Player::getColor() const {
    return color;
}

const std::string& Player::getName() const {
    return name;
}

unsigned Player::getColumn() const {
    std::string msg = "Column [1, "s + std::to_string(BoardWidth) + "]: "s;
    std::string err_msg = "Incorrect column! Try again!\n";
    return displayer.unsignedInput(msg, err_msg, checkColumnRange);
}
