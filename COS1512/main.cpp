// std
#include <iostream>
#include <string>

// non-std
#include <conio.h>

// local
#include "dunegon.h"
#include "player.h"

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

	return 0;
}




// print out letter one by one in console sometimes using sleep.

// Useful stuff
// forward declaration with classes when they include from one anouther:
	// in one file, declare the class that needs to be used and put the #include at the bottom of the file
	//eg class a;
	// class b{};
	// #include 'where_is_class_a'
	// Only done to one file, other can use normal #include


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
