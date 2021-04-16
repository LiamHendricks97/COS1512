#include <iostream>
#include <string>
#include "dunegon.h"
#include "player.h"

void create_hero(Player& player);
void dungeon();

int main()
{	
	Player Hero;

	std::cout << "Welome Hero" << std::endl;
	std::cout << "The world is in danger and only you can save it!" << std::endl;
	std::cout << "Great hero! What is your name?  ";

	create_hero(Hero);

	std::cout << "Yes, Yes " << Hero.$name() << "!" << std::endl;

	Dungeon demo_level;
	demo_level.draw_level();
	demo_level.display_level();
	std::cout << "press x to enter dunegeon" << std::endl;

	return 0;
}
void create_hero(Player& player)
{
	//std::string name{};
	//std::getline(std::cin, name);
	//Hero.create_name(name);
	// Make hero name all caps
	player.set_name("OLD MAN");
	player.set_stats(100, 0, 5, 6);
}

void dungeon()
{
	// add random events here
}

// print out letter one by one in console sometimes using sleep.