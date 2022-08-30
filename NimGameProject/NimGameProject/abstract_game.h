#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "player.h"
namespace atlas
{
	namespace games {
		using namespace player;
		
		template<class BOARD, class MOVE>
		class abstract_game: public game
		{
			BOARD board;
			MOVE move;

			game_player<BOARD, MOVE>* current_player;

			std::vector<game_player<BOARD, MOVE>*> players;
			
			void set_current_player(game_player<BOARD, MOVE>* const current_player)
			{
				this->current_player = current_player;
			}

			void play_round()
			{
				for (game_player<BOARD, MOVE>* player : players)
				{
					play_single_move_for_player(player);
				}

			}

			void play_single_move_for_player(game_player<BOARD, MOVE>* player)
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
					move = get_current_player()->do_turn(board);
				} while (players_move_is_invalid());
			}


			bool players_move_is_invalid()
			{
				if (is_move_valid()) return false;
				write("Unerlaubter Zug");
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
					write( current_player->get_name() +  " hat verloren");
				}
			}

		protected:

			void write(std::string message)
			{
				std::cout << message << std::endl;
			}

			std::vector<game_player<BOARD, MOVE>*> get_players() const
			{
				return players;
			}

			void set_players(const std::vector<game_player<BOARD, MOVE>*>& players)
			{
				this->players = players;
			}

			game_player<BOARD, MOVE>* get_current_player() const
			{
				return current_player;
			}

			

			BOARD get_board() const
			{
				return board;
			}

			void set_board(const BOARD& board)
			{
				this->board = board;
			}

			MOVE get_move() const
			{
				return move;
			}

			void set_move(const MOVE& move)
			{
				this->move = move;
			}

			virtual bool is_move_valid() = 0;
			virtual void update_board() = 0;
			virtual bool is_game_over() = 0;

		public :
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
