#pragma once

#include <string>
#include "settings.hpp"

class Displayer {
public:
    using container_t = int[BoardHeight][BoardWidth];
    Displayer();
    void visit(container_t tab);
    void showBoard() const;
    void showPlayerInfo(std::string_view name, TokenColor color) const;
    void showIncorrectMove() const;
    unsigned unsignedInput(std::string_view msg, std::string_view err_msg, bool (*check)(unsigned));
private:
    container_t fields;
};
