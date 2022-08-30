#pragma once

#include "abstract_game.h"
#include <iostream>
#include <string>
#include <vector>

#include "player.h"

namespace atlas
{
	namespace games {

		namespace nim_game {
			using namespace atlas::games;
			using namespace atlas::games::player;

			class nim_game_impl : public  abstract_game<int,int>
			{
				
			protected:
				
				bool is_move_valid() override
				{
					return get_move() >= 1 && get_move() <= 3;
				}
				void update_board() override
				{
					set_board(get_board() - get_move());
				}

				bool is_game_over() override
				{
					return get_board() < 1 || get_players().empty();
				}

			public:


				nim_game_impl(writer& writer)
					: abstract_game<int, int>(writer)
				{
					set_board(23);
				}
			};
		}
	}
}

