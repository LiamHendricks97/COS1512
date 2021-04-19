#include "player.h"


void Player::set_name(std::string name)
{
	this->name = name;
}

void Player::set_x_coordinate(int coordinate)
{
	this->x_coordinate = coordinate;
}

void Player::set_y_coordinate(int coordinate, Dungeon dungeon)
{
	if ((coordinate > 0) && (coordinate < dungeon.$y_axis_size()))
	{
		y_coordinate = coordinate;
	}
}
/////////////////////////////////////////////
std::string Player::$name()
{
	return name;
}

int Player::$x_coordinate()
{
	return x_coordinate;
}

int Player::$y_coordinate()
{
	return y_coordinate;
}

char Player::$symbol()
{
	return player_symbol;
}
////////////////////////////////////////
Player::Player()
	:health{100}, exp{}, offence{10}, defence{11}
{}