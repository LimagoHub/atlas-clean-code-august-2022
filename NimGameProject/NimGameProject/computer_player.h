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
				class computer_player : public abstract_nim_game_player
				{
				public:
					computer_player(const std::string& name)
						: abstract_nim_game_player(name)
					{
					}

					int do_turn(const int& stones) override
					{
						
						const  int zuege[] = { 3,1,1,2 };


						int move = zuege[stones % 4];
						std::cout << "Computer nimmt " << move << " Steine." << std::endl;

						return move;
					}
				};


			}
		}
	}
}