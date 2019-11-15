#include "game.hpp"
#include "board.hpp"
#include "token.hpp"
#include "player.hpp"
#include "displayer.hpp"

Game::Game(Displayer& displayer_)
    : current_player{},
      next_player{},
      board{std::make_unique<Board>()},
      displayer{displayer_} {
    current_player= std::make_unique<Player>("Embla", TokenColor::Red, displayer);
    next_player = std::make_unique<Player>("George", TokenColor::Yellow, displayer);
}

Game::~Game() = default;

void Game::run() {
    showBoard();
    while(! board->isFull()) {
        displayer.showPlayerInfo(current_player->getName(), current_player->getColor());
        auto column = current_player->getColumn();
        if(! board->dropToken(Token(current_player->getColor()), column)) {
            displayer.showIncorrectMove();
            continue;
        }
        showBoard();
        current_player.swap(next_player);
    }
}

void Game::showBoard() const {
    board->accept(displayer);
    displayer.showBoard();
}
