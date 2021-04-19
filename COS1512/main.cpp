// std
#include <iostream>
#include <string>

// non-std
#include <conio.h>
#include <windows.h>

// local
#include "dunegon.h"
#include "player.h"

// defines
constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;

// func
int test_move(Player player, Dungeon dungeon);

int main()
{	
	// removes echo
	//HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//DWORD mode = 0;
	//GetConsoleMode(hStdin, &mode);
	//SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	std::cout << "Welome Hero" << std::endl;
	std::cout << "The world is in danger and only you can save it!" << std::endl;
	//std::cout << "Great hero! What is your name?  ";
	//std::cout << "Yes, Yes " << Hero.$name() << "!" << std::endl;
	
	Player Hero;
	Dungeon Base(Hero);	
	Base.display_level();

	test_move(Hero, Base);
}



int test_move(Player player, Dungeon dungeon)
{
	std::cout << "test";
	char c{};
	while (true)
	{
		c = _getch();
		//std::cout << c;

		if (c == 'q')
		{
			std::cout << "Thanks for playing" << std::endl;
			return 0;
		}
		else if (c == KEY_UP)
		{
			//std::cout << "UP";
			dungeon.set_current_pos_blank(player);
			int y_coordinate{ player.$y_coordinate() };
			player.set_y_coordinate(y_coordinate - 1);
			dungeon.put_hero_in_level(player);
			dungeon.display_level();

			// need to add bounds protection
			// need to clear screen after each movement

		}
		else if (c == KEY_DOWN)
		{
			//std::cout << "DOWN";
		}
		else if (c == KEY_LEFT)
		{
			//std::cout << "LEFT";
		}
		else if (c == KEY_RIGHT)
		{
			//std::cout << "RIGHT";
		}
		// convert above to a switch statement
	}
}

// print out letter one by one in console sometimes using sleep.