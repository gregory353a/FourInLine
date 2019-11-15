#include "game.hpp"
#include "token.hpp"
#include "player.hpp"
#include "displayer.hpp"

Game::Game()
    : current_player{std::make_unique<Player>("Embla", TokenColor::Red)},
      next_player{std::make_unique<Player>("George", TokenColor::Yellow)},
      board{std::make_unique<Board>()},
      displayer{std::make_unique<Displayer>()} {
}

Game::~Game() = default;

void Game::run() {
    showBoard();
    while(! board->isFull()) {
        displayer->showPlayerInfo(current_player->getName(), current_player->getColor());
        auto column = current_player->getColumn();
        if(! board->dropToken(Token(current_player->getColor()), column)) {
            displayer->showIncorrectMove();
            continue;
        }
        showBoard();
        current_player.swap(next_player);
    }
}

void Game::showBoard() const {
    board->accept(*displayer);
    displayer->showBoard();
}
