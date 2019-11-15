#pragma once

#include <string>
#include "settings.hpp"

class Displayer;

class Player {
public:
    Player(std::string_view name, TokenColor color, Displayer& displayer);
    virtual ~Player();

    // noncopyable
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    virtual TokenColor getColor() const;
    virtual const std::string& getName() const;
    virtual unsigned getColumn() = 0;
protected:
    const std::string name;
    const TokenColor color;
    [[maybe_unused]] Displayer& displayer;
};
