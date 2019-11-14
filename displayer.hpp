#pragma once

#include "board.hpp"

class Displayer {
public:
    using container_t = int[Board::BoardHeight][Board::BoardWidth];
    Displayer();
    void visit(container_t tab);
    void show() const;
private:
    container_t fields;
};
