#pragma once

#include <string>
#include <random>
#include "player.hpp"

class AIPlayer: public Player {
public:
	AIPlayer(std::string_view name, TokenColor color, Displayer& displayer);
	unsigned getColumn() override;
private:
	std::random_device rd;
	std::mt19937_64 generator;
	std::uniform_int_distribution<unsigned> distribution;
};
