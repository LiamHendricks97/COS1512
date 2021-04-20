#pragma once
#include <iostream>
#include <string>

class Dungeon; // Fwd declaration together with the #include at the bottom
class Player
{
private:
	// Attributes
	// Generally speaking, attributes should only be changed by their public methods

	std::string name{};
	int health{};
	int exp{};
	int offence{};
	int defence{};

	int x_coordinate{10};
	int y_coordinate{10};
	char player_symbol{ 'X' };


public:
	// Method prototypes
	void set_name(std::string name);
	void set_x_coordinate(int coordinate, Dungeon dungeon);
	void set_y_coordinate(int coordinate, Dungeon dungeon);

	// Contructor
	Player();

	// Friend function
	//friend std::vector <int> test();

	// Dollar sign used to express it returns a value from private access
	std::string $name();
	int $x_coordinate();
	int $y_coordinate();
	char $symbol();
};


#include "dunegon.h"