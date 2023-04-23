#include "../include/Monkey.h"
#include "../include/Animal.h"
// Yaniv

Monkey::Monkey(const Location& locat, std::string& str)
{
	name = str;
	loc = locat;
	numOfSteps = 0;
	dir = static_cast<direction>(rand() % 4);
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::step()
{
	if (canMove)
	{
		switch (dir)
		{
		case up:
			loc += Location(-1 * stepSize, 0);
			break;
		case down:
			loc += Location(stepSize, 0);
			break;
		case right:
			loc += Location(0, stepSize);
			break;
		case left:
			loc += Location(0, -1 * stepSize);
			break;
		default:
			break;
		}
		handleExepectionLocation();
		numOfSteps++;
		if (numOfSteps % 5 == 0)
		{
			stepSize = 1 + (rand() % 2);
			dir = static_cast<direction>(rand() % 4);;
		}
	}
}

void Monkey::printDetails() const
{
	std::cout << "Animal: Monkey\n";
	Animal::printDetails();
}

void Monkey::move()
{
	Animal::move();
}
