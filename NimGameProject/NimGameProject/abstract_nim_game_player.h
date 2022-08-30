#pragma once

#include "abstract_player.h"
namespace atlas
{
	namespace games
	{

		namespace nim_game
		{
			namespace player
			{

				using namespace atlas::games::player;
				
				class abstract_nim_game_player : public abstract_player<int,int>
				{

					

				public:


					abstract_nim_game_player(const std::string& name)
						: abstract_player<int, int>(name)
					{
					}

					
				};

				
			}
		}
	}
}