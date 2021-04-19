// std
#include <iostream>
#include <string>

// non-std
#include <conio.h>

// local
#include "dunegon.h"
#include "player.h"

void foo(Player player, Dungeon dungeon)
{
	player.set_y_coordinate(2, dungeon);
	std::cout << player.$y_coordinate() << std::endl;
}

int main()
{	
	std::cout << "Welome Hero" << std::endl;
	std::cout << "The world is in danger and only you can save it!" << std::endl;
	//std::cout << "Great hero! What is your name?  ";
	//std::cout << "Yes, Yes " << Hero.$name() << "!" << std::endl;
	
	Player Hero;
	Dungeon Base(Hero);


	Base.display_level();
	Base.move_player(Hero, Base);

	foo(Hero, Base);
	std::cout << Hero.$y_coordinate() << std::endl;

	// Heres the problem... the value is being changed within the loop (loop called Dungeon::move_player) BUT not really.
	// As soon as the loop ends the value of the Base objects y_coordinate is set back to 10

	// ITS CAUSE WE MAKING A COPY1121
	// NEED TO PASS BY REF

}
// print out letter one by one in console sometimes using sleep.





// Useful stuff

// clears screen:
	//std::cout << "\033[2J\033[1;1H";

// removes echo:
	//HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//DWORD mode = 0;
	//GetConsoleMode(hStdin, &mode);
	//SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

// non-std library to take in keystokes w/o enter:
	// #include <conio.h>
	// 		c = _getch();

// init a vector of vectors:
	// vector<vector<int>> vec( n , vector<int> (m));
	// where n and m are int variables
	// https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
