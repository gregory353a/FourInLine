#include "player.hpp"
#include "settings.hpp"
#include "displayer.hpp"

Player::Player(std::string_view name_, TokenColor color_, Displayer& displayer_)
    : name{name_}, color{color_}, displayer{displayer_} {
}

Player::~Player() = default;

TokenColor Player::getColor() const {
    return color;
}

const std::string& Player::getName() const {
    return name;
}
