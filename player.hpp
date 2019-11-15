#pragma once

#include <string>
#include "token.hpp"

class Player {
public:
    Player(const std::string& name, TokenColor color);

    // noncopyable
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    TokenColor getColor() const;
    const std::string& getName() const;
    unsigned getColumn() const;
private:
    const std::string name;
    const TokenColor color;
};
