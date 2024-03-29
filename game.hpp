#pragma once

#include <memory>

class Player;
class Board;
class Displayer;

class Game {
public:
    Game(Displayer& displayer);
    void run();
    ~Game();
private:
    void showBoard() const;

    std::unique_ptr<Player> current_player;
    std::unique_ptr<Player> next_player;
    const std::unique_ptr<Board> board;
    Displayer& displayer;
};
