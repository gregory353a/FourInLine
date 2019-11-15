#pragma once

#include <string>
#include "player.hpp"

class Displayer;

class HumanPlayer: public Player {
public:
	HumanPlayer(std::string_view name, TokenColor color, Displayer& displayer);
	unsigned getColumn() override;
};

