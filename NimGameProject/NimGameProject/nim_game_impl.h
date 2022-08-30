#pragma once

#include "game.h"
#include <iostream>
#include <string>
namespace atlas
{
	namespace games {

		typedef

		class nim_game_impl: public  game
		{
			int stones;
			int move;

			


			void execute_moves()  // Integration
			{
				player_move();
				computer_move();
				
			}

			

			void player_move()
			{
				if (is_game_over()) return;
				
				

				while (true) {
					std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
					std::cin >> move;
					if (move >= 1 && move <= 3)
						break;
					std::cout << "Unerlaubte Eingabe" << std::endl;
				}
				
				terminate_move("Mensch");
			}

			void computer_move() // Operation
			{

				if (is_game_over()) return;
				
				const  int zuege[] = { 3,1,1,2 };
				

				move = zuege[stones % 4];
				std::cout << "Computer nimmt " << move << "Steine." <<  std::endl;

				
				terminate_move("Computer");
			}


			

			void terminate_move(std::string player)
			{
				update_board();
				print_gameover_message_when_game_is_over(player);
			}
			
			void print_gameover_message_when_game_is_over(std::string player)
			{
				if (is_game_over())
				{
					std::cout << player << " hat verloren" << std::endl;
				}
			}

			void update_board()
			{
				stones -= move;
			}

			bool is_game_over()
			{
				return stones < 1;
			}
			
		public:


			nim_game_impl()
			{
				stones = 23;
				
			}


			

			void play() override{

				while(! is_game_over())
				{
					execute_moves();
				}
			}

		};
	}
}

