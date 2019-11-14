#pragma once

#include <array>
#include <optional>
#include "token.hpp"

class Displayer;

class Board {
public:
    constexpr static std::size_t BoardWidth = 7;
    constexpr static std::size_t BoardHeight = 6;
    using fields_t = std::array<std::array<std::optional<Token>, BoardWidth>, BoardHeight>;

    Board();
    [[nodiscard]] bool dropToken(Token&& token, unsigned column);
    bool isFull() const;
    void accept(Displayer& displayer) const;

private:
    fields_t fields;
};
