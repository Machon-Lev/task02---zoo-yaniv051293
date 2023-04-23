#include "Animal.h"
#include <iostream>
#include <string>

void Animal::printDetails() const
{
	std::string str;
	switch (dir) {
	case right:
		str= "right";
		break;
	case left:
		str = "left";
		break;
	case up:
		str = "up";
		break;
	case down:
		str = "down";
		break;
	default:
		str = "Unknown ";
	}
	std::cout<<"name: "<< name << ". location: " << loc<<" ditection: "<<str;
	if (canMove == true)
		std::cout << " mode: can move.\n";
	else
		std::cout << " mode: cann't move.\n";
	
}
void Animal::handleExepectionLocation()
{
	switch (dir)  // handle exeptions of location
	{
	case up:
		if (loc.row < 0)
		{
			loc.row = loc.row * -1;
			dir = down;
		}
		break;
	case down:
		if (loc.row < 19)
		{
			loc.row = 19 - (loc.row - 19);
			dir = up;
		}
		break;
	case right:
		if (loc.col > 39) // if there is exeption in the right side 
		{
			loc.col = 39 - (loc.col - 39);
			dir = left;
		}
		break;
	case left:
		if (loc.col < 0)  // if there is exeption in the left side
		{
			loc.col = loc.col * -1;
			dir = right;
		}
		break;
	default:
		break;
	}
}
Animal::Animal()
{
	loc =Location(rand()%20,rand()%40) ;
	name = "";
}
void Animal::turnVertically()
{
	if (dir == up)
		dir = down;
	else
		if (dir == down)
			dir = up;
}

void Animal::turnHorizontally()
{
	if (dir == left)
		dir = right;
	else
		if (dir == right)
			dir = left;
}


Location Animal::getLocation() const
{
	return loc;
}

void Animal::stop()
{
	canMove = false;
}

void Animal::move()
{
	canMove = true;
}

