#include "board.hpp"
#include "token.hpp"

int main() {
    Board board;
    Token token1 = Token(TokenColor::Red);
    Token token2 = Token(TokenColor::Yellow);
    while(board.dropToken(token2, 2)) {}
    while(board.dropToken(token1, 1)) {}
    while(board.dropToken(token2, 3)) {}
    board.show();
}
