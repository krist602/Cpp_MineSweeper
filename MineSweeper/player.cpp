#include "player.h"

void player::setName(string name)
{
	this->name = name;
	return;
}

void player::inputTime(float second)
{
	this->timer = second;
	return;
}
