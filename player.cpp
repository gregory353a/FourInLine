#include "player.hpp"

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
    // Implementacja
    return 0;
}
