#include "dunegon.h"

Dungeon::Dungeon(Player player)
{
	draw_level();
	place_player(player);
}

char Dungeon::get_input()
{
	char move_direction{};
	move_direction = _getch();
	return move_direction;
}

void Dungeon::test(Player player, Dungeon dungeon, char direction)
{

	std::cout << "\033[2J\033[1;1H";
	dungeon.set_current_pos_blank(player);
	if (direction == KEY_UP)
	{
		player.set_y_coordinate(player.$y_coordinate() - 1, dungeon);
	}
	else if (direction == KEY_DOWN)
	{
		player.set_y_coordinate(player.$y_coordinate() + 1, dungeon);
	}
	dungeon.place_player(player);
	dungeon.display_level();

}

void Dungeon::move_player(Player player, Dungeon dungeon)
{
	bool run{ true };
	while (run)
	{
		char move_direction = get_input();

		if (move_direction == 'q')
		{
			std::cout << "Thanks for playing" << std::endl;
			run = false;
		}

		else if (move_direction == KEY_UP)
		{
			std::cout << "\033[2J\033[1;1H";
			dungeon.set_current_pos_blank(player);
			player.set_y_coordinate(player.$y_coordinate() - 1, dungeon); // Move player one space up
			dungeon.place_player(player);
			dungeon.display_level();
			//test(player, dungeon, move_direction);
		}
		else if (move_direction == KEY_DOWN)
		{
			//std::cout << "DOWN";
		}
		else if (move_direction == KEY_LEFT)
		{
			//std::cout << "LEFT";
		}
		else if (move_direction == KEY_RIGHT)
		{
			//std::cout << "RIGHT";
		}
		// convert above to a switch statement
	}
}


void Dungeon::place_player(Player player)
{
	int x_coordinate{ player.$x_coordinate() };
	int y_coordinate{ player.$y_coordinate() };

	if ((level.at(y_coordinate).at(x_coordinate) != '#'))
	{
		level.at(y_coordinate).at(x_coordinate) = player.$symbol();
	}
}

void Dungeon::set_current_pos_blank(Player player)
{
	int x_coordinate{ player.$x_coordinate() };
	int y_coordinate{ player.$y_coordinate() };

	level.at(y_coordinate).at(x_coordinate) = '*';
}

// Creates level from scratch
void Dungeon::draw_level()
{
	std::vector <std::vector <char>> level(y_axis_size, std::vector<char>(x_axis_size));
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

// displays level from: attribute level
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

std::vector<int> Dungeon::get_player_coordinates(Player player)
{
	int x = player.$x_coordinate();
	int y = player.$y_coordinate();
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
