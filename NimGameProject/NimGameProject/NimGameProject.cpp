// NimGameProject.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "game_client.h"
#include "nim_game_impl.h"

using namespace atlas::games;

int main()
{
	nim_game_impl nim_game_impl_;
	game_client client{ nim_game_impl_ };
	client.run();
	
    std::cout << "Hello World!\n";
}

