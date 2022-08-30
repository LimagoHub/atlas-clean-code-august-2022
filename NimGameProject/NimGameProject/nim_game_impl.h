#pragma once

#include "game.h"
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

			class nim_game_impl : public  game
			{
				int stones;
				int move;
				game_player<int,int> * current_player;

				std::vector<game_player<int, int>*> players;

				game_player<int, int>* get_current_player() const
				{
					return current_player;
				}

				void set_current_player(game_player<int, int>* const current_player)
				{
					this->current_player = current_player;
				}

				

				void play_round()  
				{
					for(auto * player : players)
					{
						play_single_move_for_player(player);
					}

				}

				void play_single_move_for_player(game_player<int, int>* player)
				{
					set_current_player(player);
					play_single_move();
				}


				void play_single_move()
				{
					if (is_game_over()) return;
					execute_move();
					terminate_move();
				}



				void execute_move()
				{
					do
					{
						move = get_current_player()->do_turn(stones);
					} while (players_move_is_invalid());
				}



				bool players_move_is_invalid()
				{
					if (is_move_valid()) return false;
					std::cout << "Unerlaubter Zug" << std::endl;
					return true;
				}

				
				void terminate_move()
				{
					update_board();
					print_gameover_message_when_game_is_over();
				}

				void print_gameover_message_when_game_is_over()
				{
					if (is_game_over())
					{
						std::cout << current_player->get_name() << " hat verloren" << std::endl;
					}
				}

				bool is_move_valid()
				{
					return move >= 1 && move <= 3;
				}
				void update_board()
				{
					stones -= move;
				}

				bool is_game_over()
				{
					return stones < 1 || players.empty();
				}

			public:


				

				nim_game_impl()
				{
					stones = 23;

				}


				void addPlayer(game_player<int, int>* player)
				{
					players.emplace_back(player);
				}

				void play() override {

					while (!is_game_over())
					{
						play_round();
					}
				}

			};
		}
	}
}

