#pragma once

#include "game.h"

using namespace atlas::games;

class game_client
{
	game& game_;


public:
	game_client(game& game)
		: game_(game)
	{
	}

	void run()
	{
		game_.play();
	}
};
