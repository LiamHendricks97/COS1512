#pragma once
#include <iostream>
#include <vector>

#include <conio.h>

#include "player.h"

// controls & defines
constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;

class Dungeon
{
private:
	int x_axis_size{ 50 };
	int y_axis_size{ 20 };
	std::vector <std::vector<char>> level{};

public:
	Dungeon(Player player);

	void test(Player& player, Dungeon& dungeon, char direction);

	void draw_level();
	void display_level();
	char get_input();
	void place_player(Player player);
	void set_current_pos_blank(Player player);
	void move_player(Player& player, Dungeon& dungeon);

	std::vector<int> get_player_coordinates(Player player);
	int $x_axis_size();
	int $y_axis_size();

	
};