#include "player.h"

// Default values
Player::Player()
	:health{ 100 }, exp{}, offence{ 10 }, defence{ 11 }
{}

////////////////////////////////////////////////////////////////////////////
// set the attributes
void Player::set_name(std::string name)
{
	this->name = name;
}

void Player::set_x_coordinate(int coordinate, Dungeon dungeon)
{
	if ((coordinate > 0) && (coordinate < dungeon.get_x_axis_size() - 1))
	{
		this->x_coordinate = coordinate;
	}
}

void Player::set_y_coordinate(int coordinate, Dungeon dungeon)
{
	if ((coordinate > 0) && (coordinate < dungeon.get_y_axis_size() - 1))
	{
		this->y_coordinate = coordinate;
	}
}
////////////////////////////////////////////////////////////////////////////
// access the attributes
std::string Player::get_name()
{
	return name;
}

int Player::get_xcoord()
{
	return x_coordinate;
}

int Player::get_ycoord()
{
	return y_coordinate;
}

char Player::get_player_symbol()
{
	return player_symbol;
}