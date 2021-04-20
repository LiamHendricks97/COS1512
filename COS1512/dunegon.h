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

class Dungeon
{
private:
	int x_axis_size{ 50 };
	int y_axis_size{ 20 };
	std::vector <std::vector<char>> level{};

public:
	// Default constructor
	Dungeon(Player player);

	void test(Player& player, Dungeon& dungeon);
	void cls();
	void set_cursor_position(int x, int y);


	char get_input();
	void draw_initial_level();
	void place_player_dungeon(Player player);
	void display_level();

	void position_player(Player& player, Dungeon& dungeon, char direction);
	void set_tile_blank(Player player);
	void move_player(Player& player, Dungeon& dungeon);
	std::vector<int> get_player_coordinates(Player player);

	// Attribute member functions (they get the values of the attributes)
	int $x_axis_size();
	int $y_axis_size();
};