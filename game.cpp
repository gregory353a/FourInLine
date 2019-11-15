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
    for(;;) {
        // Tu implementacja
    }
}
