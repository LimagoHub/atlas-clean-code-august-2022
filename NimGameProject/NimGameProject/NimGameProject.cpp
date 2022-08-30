// NimGameProject.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "game_client.h"
#include "nim_game_impl.h"
#include "human_player.h"
#include "computer_player.h"
#include "console_writer.h"

using namespace atlas::games::nim_game;
using namespace atlas::games::nim_game::player;

int main()
{
	console_writer writer_;
	human_player human_player_{ "Fritz" };
	computer_player computer_player_{ "Computer" };
	
	nim_game_impl nim_game_impl_{ writer_ };

	nim_game_impl_.addPlayer(&human_player_);
	nim_game_impl_.addPlayer(&computer_player_);
	
	game_client client{ nim_game_impl_ };
	client.run();
	
   
}

