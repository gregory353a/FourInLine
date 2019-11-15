#include "ai_player.hpp"
#include "settings.hpp"

AIPlayer::AIPlayer(std::string_view name_, TokenColor color_, Displayer& displayer_)
	: Player{name_, color_, displayer_},
	  rd{},
	  generator{rd()},
	  distribution(1, BoardWidth) {

}

unsigned AIPlayer::getColumn() {
	return distribution(generator);
}
