#include "../include/Dog.h"
#include "../include/Animal.h"
// Yaniv

Dog::Dog(const Location& locat, std::string& str)
{
	name = str;
	loc = locat;
	dir = static_cast<direction>(rand() % 4);
}

char Dog::getInitial() const
{
	return 'D';
}

void Dog::step()
{
	if (canMove)
	{
		switch (dir)
		{
		case up:
			if (goHead)
				loc += Location(-3, 0);
			else
				loc += Location(1, 0);
			break;
		case down:
			if (goHead)
				loc += Location(3, 0);
			else
				loc += Location(-1, 0);
			break;
		case right:
			if (goHead)
				loc += Location(0, 3);
			else
				loc += Location(0, -1);
			break;
		case left:
			if (goHead)
				loc += Location(0, -3);
			else
				loc += Location(0, 1);
			break;
		default:
			break;
		}
		handleExepectionLocation();	
	}
}

void Dog::printDetails() const
{
	std::cout << "Animal: Dog\n";
	Animal::printDetails();
}

void Dog::move()
{
	if (!canMove)
	{
		dir = static_cast<direction>(rand() % 4);;
	}
	Animal::move();
}