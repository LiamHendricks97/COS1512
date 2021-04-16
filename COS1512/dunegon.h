#pragma once
#include <iostream>
#include <vector>
#include "player.h"

class Dungeon
{
private:
	//First level
	int x_axis_size{ 50 };
	int y_axis_size{ 20 };
	std::vector <std::vector<char>> level{};

public:
	void draw_level();
	void display_level();
	std::vector<int> get_player_coordinates(Player hero);

};