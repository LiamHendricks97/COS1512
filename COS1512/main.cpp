// std
#include <iostream>
#include <string>

// non-std
#include <conio.h>

// local
#include "dunegon.h"
#include "player.h"
#include <windows.h>

#define HARLIAMONTI

// Blanks screen
void cls();
void setCursorPosition(int x, int y);

int main()
{	
	std::cout << "Welome Hero" << std::endl;
	std::cout << "The world is in danger and only you can save it!" << std::endl;
	std::cout << "Great hero! What is your name?  ";
	
	Player Hero;
	Dungeon Base(Hero);

	std::cout << "Yes, Yes " << Hero.$name() << "!" << std::endl;
	cls();

	Base.display_level();
	Base.move_player(Hero, Base);

	// test	
	setCursorPosition(10, 5);
	std::cout << "CHEESE";
	setCursorPosition(10, 5);
	std::cout << 'W';
	setCursorPosition(11, 5);
	std::cout << 'H';
	setCursorPosition(12, 5);
	std::cout << 'E';
	setCursorPosition(13, 5);
	std::cout << 'E';
	setCursorPosition(14, 5);
	std::cout << 'Z';
	setCursorPosition(15, 5);
	std::cout << 'E';
	std::cout.flush();
	//cls();

	return 0;
}


void cls()
{
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
		// TODO: Handle failure!
		abort();
	}
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hOut, topLeft);
}

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
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

// reduce flicker
	//https://stackoverflow.com/questions/34842526/update-console-without-flickering-c