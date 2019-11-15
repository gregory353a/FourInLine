#include "game.hpp"
#include "board.hpp"
#include "token.hpp"
#include "player.hpp"
#include "human_player.hpp"
#include "ai_player.hpp"
#include "displayer.hpp"

Game::Game(Displayer& displayer_)
    : current_player{std::make_unique<HumanPlayer>("Embla", TokenColor::Red, displayer_)},
      next_player{std::make_unique<AIPlayer>("HAL2001", TokenColor::Yellow, displayer_)},
      board{std::make_unique<Board>()},
      displayer{displayer_} {
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
