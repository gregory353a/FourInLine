#pragma once

#include <array>
#include <optional>

class Board {
public:
    constexpr static std::size_t BoardWidth = 7;
    constexpr static std::size_t BoardHeight = 6;
    using fields_t = std::array<std::array<std::optional<char>, BoardWidth>, BoardHeight>;

    Board();
    void show() const;
private:
    fields_t fields;
};
