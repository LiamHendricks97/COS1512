#pragma once
#include <iostream>
#include <string>

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

	int x_coordinate{1};
	int y_coordinate{1};
	char player_symbol{ 'X' };


public:
	// Method prototypes
	void set_name(std::string name);

	// Contructor
	Player();

	// Dollar sign used to express it returns a value from private access
	std::string $name();
	int $x_coordinate();
	int $y_coordinate();
	char $symbol();
};

