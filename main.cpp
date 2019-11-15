#include "game.hpp"
#include "displayer.hpp"

int main() {
    Displayer displayer;
    Game game{displayer};
    game.run();
}
