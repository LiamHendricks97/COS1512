#include "dunegon.h"
#include "player.h"

Dungeon::Dungeon(Player Hero)
{
	draw_level();
	put_hero_in_level(Hero);
	display_level();
}


void Dungeon::put_hero_in_level(Player Hero)
{
	int x_coordinate{ Hero.$x_coordinate() };
	int y_coordinate{ Hero.$y_coordinate() };

	if (level.at(y_coordinate).at(x_coordinate) != '#')
	{
		level.at(y_coordinate).at(x_coordinate) = Hero.$symbol();
	}
}


void Dungeon::draw_level()
{
	std::vector <std::vector <char >> level(y_axis_size, std::vector<char>(x_axis_size));
	for (int i{}; i < y_axis_size; i++)
	{
		for (int j{}; j < x_axis_size; j++)
		{
			if (j == 0 || i == 0 || i == y_axis_size - 1 || j == x_axis_size - 1)
			{
				level.at(i).at(j) = '#';
			}
			else
			{
				level.at(i).at(j) = '*';
				// replace with empty space later
			}
		}
	}

	this->level = level;
}


void Dungeon::display_level()
{
	for (int i{}; i < y_axis_size; i++)
	{
		for (int j{}; j < x_axis_size; j++)
		{
			std::cout << level.at(i).at(j);

			if (j == x_axis_size - 1)
			{
				std::cout << std::endl;
			}
		}
	}
}

std::vector<int> Dungeon::get_player_coordinates(Player hero)
{
	int x = hero.$x_coordinate();
	int y = hero.$y_coordinate();
	std::vector<int>player_coordinates{x, y};
	return player_coordinates;
}

int Dungeon::$x_axis_size()
{
	return x_axis_size;
}

int Dungeon::$y_axis_size()
{
	return y_axis_size;
}