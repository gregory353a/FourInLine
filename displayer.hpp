#pragma once

#include <string>
#include "token.hpp"
#include "board.hpp"

class Displayer {
public:
    using container_t = int[Board::BoardHeight][Board::BoardWidth];
    Displayer();
    void visit(container_t tab);
    void showBoard() const;
    void showPlayerInfo(std::string_view name, TokenColor color) const;
    void showIncorrectMove() const;
private:
    container_t fields;
};
