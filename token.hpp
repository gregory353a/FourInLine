#pragma once

enum class TokenColor {
    Red,
    Yellow
};

class Token {
public:
    Token(TokenColor color);

    // noncopyable
    Token(const Token&) = delete;
    Token& operator=(const Token&) = delete;

    TokenColor getColor() const;
    char getRepr() const;
private:
    const TokenColor color;
};
