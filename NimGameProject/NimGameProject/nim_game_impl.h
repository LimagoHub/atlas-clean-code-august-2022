#pragma once

#include "game.h"
#include <iostream>
namespace atlas
{
	namespace games {
		

		class nim_game_impl: public  game
		{
			int stones;
			bool gameover;


			void execute_moves()
			{
				player_move();
				computer_move();
			}
			
			void player_move()
			{
				int move;

				while (true) {
					std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3!" << std::endl;
					std::cin >> move;
					if (move >= 1 && move <= 3)
						break;
					std::cout << "Unerlaubte Eingabe" << std::endl;
				}
				stones -= move;
			}

			void computer_move()
			{
				const  int zuege[] = { 3,1,1,2 };
				if(stones < 1)
				{
					std::cout << "Du Loser" << std::endl;
					gameover = true;
					return;
				}

				if (stones == 1)
				{
					std::cout << "Du hast nur Glueck gehabt!" << std::endl;
					gameover = true;
					return;
				}

				int move = zuege[stones % 4];
				std::cout << "Computer nimmt " << move << "Steine." <<  std::endl;
				stones -= move;
			}
			
		
		public:


			nim_game_impl()
			{
				stones = 23;
				gameover = false;
			}


			

			void play() override{

				while(! gameover)
				{
					execute_moves();
				}
			}

		};
	}
}

