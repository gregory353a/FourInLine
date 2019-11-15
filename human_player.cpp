#include "human_player.hpp"
#include "settings.hpp"
#include "displayer.hpp"
#include <limits>

using namespace std::string_literals;

namespace {

bool checkColumnRange(unsigned column) {
    return (column > 0) && (column <= BoardWidth);
}

} // anonumous namespace

HumanPlayer::HumanPlayer(std::string_view name_, TokenColor color_, Displayer& displayer_)
	: Player{name_, color_, displayer_} {
}

unsigned HumanPlayer::getColumn() {
    std::string msg = "Column [1, "s + std::to_string(BoardWidth) + "]: "s;
    std::string err_msg{"Incorrect column! Try again!\n"};
    return displayer.unsignedInput(msg, err_msg, checkColumnRange);
}
