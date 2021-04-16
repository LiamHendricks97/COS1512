#include <iostream>
#include <string>
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
	return 0;
}


// print out letter one by one in console sometimes using sleep.