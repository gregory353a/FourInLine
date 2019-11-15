#pragma once

#include "settings.hpp"

class Token {
public:
    Token(TokenColor color);

    // noncopyable
    Token(const Token&) = delete;
    Token& operator=(const Token&) = delete;

    // movable
    Token(Token&&) = default;
    Token& operator=(Token&&) = default;

    TokenColor getColor() const;
    char getRepr() const;
private:
    TokenColor color;
};
