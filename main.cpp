#include "board.hpp"
#include "token.hpp"
#include "displayer.hpp"
#include <iostream>
#include <iomanip>

int main() {
    Displayer displayer;
    Board board;

    board.accept(displayer);
    displayer.show();

    std::cout << "Board is full? " << std::boolalpha << board.isFull() << '\n';
    for(auto col = 0U; col < 7; ++col) {
        for(auto i = 0U; i < 6; ++i) {
            (void) board.dropToken(Token(static_cast<TokenColor>(i % 2)), ((col + i) % Board::BoardWidth) + 1);
        }
    }

    board.accept(displayer);
    displayer.show();
    std::cout << "Board is full? " << std::boolalpha << board.isFull() << '\n';
}
