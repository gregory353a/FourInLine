#include "board.hpp"
#include "token.hpp"
#include <iostream>

int main() {
    Board board;
    std::cout << board.isFull() << '\n';
    for(auto col = 0U; col < 7; ++col) {
        for(auto i = 0U; i < 6; ++i) {
            board.dropToken(Token(static_cast<TokenColor>(i % 2)), col + 1);
        }
    }
    board.show();
    std::cout << board.isFull() << '\n';
}
