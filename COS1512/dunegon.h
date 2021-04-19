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
	Dungeon(Player Hero);

	void draw_level();
	void display_level();
	void put_hero_in_level(Player Hero);
	void set_current_pos_blank(Player Hero);

	std::vector<int> get_player_coordinates(Player hero);
	int $x_axis_size();
	int $y_axis_size();

	
};