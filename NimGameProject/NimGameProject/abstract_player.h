#pragma once

#include "player.h"
namespace atlas
{
	namespace games
	{

		
			namespace player
			{
				template<class BOARD, class MOVE>
				class abstract_player : public game_player<BOARD,MOVE>
				{

					std::string name;


				public:
					abstract_player(const std::string& name)
						: name(name)
					{
					}


					std::string get_name() const override
					{
						return name;
					}
				};


			}
		}
	
}