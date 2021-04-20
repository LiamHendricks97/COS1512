#include "dunegon.h"

Dungeon::Dungeon(Player player)
{
	draw_initial_level();
	place_player_dungeon(player);
}

/// ////////////////////////////////////////////////////////////////////////
char Dungeon::get_input()
{
	char move_direction{};
	move_direction = _getch();
	return move_direction;
}

void Dungeon::position_player(Player& player, Dungeon& dungeon, char direction)
{
	std::cout << "\033[2J\033[1;1H";
	dungeon.set_tile_blank(player);
	switch (direction)
	{
		// make this case work by changing only the tile that needs to be changed
	case KEY_UP:
		player.set_y_coordinate(player.$y_coordinate() - 1, dungeon);
		break;
	case KEY_DOWN:
		player.set_y_coordinate(player.$y_coordinate() + 1, dungeon);
		break;
	case KEY_LEFT:
		player.set_x_coordinate(player.$x_coordinate() - 1, dungeon);
		break;
	case KEY_RIGHT:
		player.set_x_coordinate(player.$x_coordinate() + 1, dungeon);
		break;
	default:
		break;
	}
	dungeon.place_player_dungeon(player);
	dungeon.display_level();
}

void Dungeon::move_player(Player& player, Dungeon& dungeon)
{
	bool run{ true };
	while (run)
	{
		char direction = get_input();
		switch (direction)
		{
		case 'q':
			std::cout << "Thanks for playing" << std::endl;
			run = false;
		case KEY_UP:
			position_player(player, dungeon, direction);
			break;
		case KEY_DOWN:
			position_player(player, dungeon, direction);
			break;
		case KEY_LEFT:
			position_player(player, dungeon, direction);
			break;
		case KEY_RIGHT:
			position_player(player, dungeon, direction);
			break;
		default:
			break;
		}
	}
}

void Dungeon::place_player_dungeon(Player player)
{
	int x_coordinate{ player.$x_coordinate() };
	int y_coordinate{ player.$y_coordinate() };

	level.at(y_coordinate).at(x_coordinate) = player.$symbol();
	// need to bounds protection for initial placement
}

void Dungeon::set_tile_blank(Player player)
{
	int x_coordinate{ player.$x_coordinate() };
	int y_coordinate{ player.$y_coordinate() };

	level.at(y_coordinate).at(x_coordinate) = '*';
}

// Creates level from scratch
void Dungeon::draw_initial_level()
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

////////////////////////////////////////////////////////////////////////////
int Dungeon::$x_axis_size()
{
	return x_axis_size;
}

int Dungeon::$y_axis_size()
{
	return y_axis_size;
}
