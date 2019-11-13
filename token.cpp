#include "token.hpp"

Token::Token(TokenColor color_)
    : color{color_} {
}

TokenColor Token::getColor() const {
    return color;
}

char Token::getRepr() const {
    return color == TokenColor::Red ? 'X': 'O';
}
