// std
#include <iostream>
#include <string>

// non-std
#include <conio.h>
#include <windows.h>

// local
#include "dunegon.h"
#include "player.h"
#include <windows.h>

#define HARLIAMONTI

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}


int main()
{	
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);	ShowConsoleCursor(false);
	//system("pause");

	std::cout << "Welome Hero" << std::endl;
	std::cout << "The world is in danger and only you can save it!" << std::endl;
	std::cout << "Great hero! What is your name?  ";
	
	Player Hero;
	Dungeon Base(Hero);

	std::cout << "Yes, Yes " << Hero.$name() << "!" << std::endl;
	Base.cls();

	Base.display_level();
	Base.test(Hero, Base);	

	Base.cls();
	std::cout << "Thanks for playing" << std::endl;

	return 0;
}



// print out letter one by one in console sometimes using sleep.
// May need to make a console object to handle all class related stuff, colour, font size, window size, flicker etc

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

// reduce flicker
	//https://stackoverflow.com/questions/34842526/update-console-without-flickering-c
	// set_cursor_position(10, 5);
	//std::cout << "CHEESE";