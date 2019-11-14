#pragma once

#include <array>
#include <optional>
#include "token.hpp"

class Board {
public:
    constexpr static std::size_t BoardWidth = 7;
    constexpr static std::size_t BoardHeight = 6;
    using fields_t = std::array<std::array<std::optional<Token>, BoardWidth>, BoardHeight>;

    Board();
    void show() const;
    bool dropToken(const Token& token, unsigned column);
    bool isFull() const;
private:
    fields_t fields;
};
