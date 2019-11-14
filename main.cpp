#include "board.hpp"
#include "token.hpp"

int main() {
    Board board;
    for(auto i = 0U; i < 5; ++i) {
        board.dropToken(Token(TokenColor::Red), 2);
    }
    board.show();
}
