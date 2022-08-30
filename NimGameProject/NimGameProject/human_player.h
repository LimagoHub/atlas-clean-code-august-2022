#pragma once
#include <iostream>
#include "abstract_nim_game_player.h"
namespace atlas
{
	namespace games
	{

		namespace nim_game
		{
			namespace player
			{
				class human_player : public abstract_nim_game_player
				{
				public:
					human_player(const std::string& name)
						: abstract_nim_game_player(name)
					{
					}

					int do_turn(const int &stones) override
					{
						int move;
						std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3!" << std::endl;
						std::cin >> move;
						return move;
					}
				};


			}
		}
	}
}