#include "player.h"


void Player::set_name(std::string name)
{
	this->name = name;
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
////////////////////////////////////////
Player::Player(int health, int exp, int offence, int defence)
{
	this->health = health;
	this->exp = exp;
	this->offence = offence;
	this->defence = defence;
}