#pragma once

#include <string>

namespace atlas
{
	namespace games {

		namespace player {

			template<class BOARD, class MOVE>
				class game_player
				{
					public:
						virtual std::string get_name() const = 0;
						virtual MOVE do_turn(const BOARD& board) = 0;
				};

			}
		}
	}
