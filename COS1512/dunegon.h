#pragma once
#include <iostream>
#include <vector>

#include <conio.h>
#include <windows.h>

#include "player.h"

// controls & defines
constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;
// os key repeat handling, could help with faster movement along the x-axis

class Dungeon
{
private:
	int x_axis_size{ 22 };
	int y_axis_size{ 22 };
	char blank_tile{ ' ' };
	char wall_tile{ '#' };
	std::vector <std::vector<char>> level{};

public:
	// Default constructor
	Dungeon(Player player);

	void move_into_direction(Player& player, Dungeon dungeon);
	void choose_direction(Player& player, Dungeon dungeon, int direction);

	void cls();
	void set_cursor_position(int x, int y);

	char get_input();
	void initial_draw_level();
	void intial_place_player_into_dungeon(Player player);
	void display_level();

	std::vector<int> get_player_coordinates(Player player);

	// getters
	int get_x_axis_size();
	int get_y_axis_size();
};