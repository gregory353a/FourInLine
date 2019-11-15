#pragma once

#include <string>
#include "token.hpp"

class Player {
public:
    Player(const std::string& name, TokenColor color);
    TokenColor getColor() const;
    const std::string& getName() const;
    unsigned getColumn() const;
private:
    std::string name;
    TokenColor color;
};
