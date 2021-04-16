#include "player.h"


void Player::set_name(std::string name)
{
	this->name = name;
}



void Player::set_stats(int health, int exp, int offence, int defence)
{
	this->health = health;
	this->exp = exp;
	this->offence = offence;
	this->defence = defence;
}

void Player::move()
{

}

void Player::enter_level()
{

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