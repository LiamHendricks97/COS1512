#pragma once
#include <iostream>
#include <string>

class Dungeon; // Fwd declaration together with the #include at the bottom
class Player
{
private:
	// Attributes
	// Generally speaking, attributes should only be accessed by their public methods
	// check above comment, should it really and why?

	std::string name{"OLDMAN"};
	int health{};
	int exp{};
	int offence{};
	int defence{};

	int x_coordinate{1};
	int y_coordinate{1};
	char player_symbol{ 'O' };


public:
	// Method prototypes
	//setters
	void set_name(std::string name);
	void set_x_coordinate(int coordinate, Dungeon dungeon);
	void set_y_coordinate(int coordinate, Dungeon dungeon);

	// default contructor
	Player();

	// Friend function
	//friend std::vector <int> position_player();

	// getters
	std::string get_name();
	int get_xcoord();
	int get_ycoord();
	char get_player_symbol();
};


#include "dunegon.h"