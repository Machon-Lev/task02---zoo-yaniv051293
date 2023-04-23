#include "../include/Lion.h"
#include "../include/Animal.h"
// Yaniv

Lion::Lion(const Location& locat, std::string& str)
{
	name = str;
	loc = locat;
	dir = static_cast<direction>(rand()%2);
}

char Lion:: getInitial() const
{
	 return 'L';
}

void Lion::step()
{
	if (canMove)
	{
		if (dir==right)
		{
			loc += Location(0, 2);
			if (loc.col > 39) // if there is exeption in the right side 
			{
				loc.col = 39 - (loc.col - 39);
				dir = left;
			}
		}
		else //going left
		{
			loc += Location(0, -2);
			if (loc.col < 0)  // if there is exeption in the left side
			{
				loc.col = loc.col * -1;
				dir =right;
			}
		}
	}
}

void Lion::printDetails () const
{
	std::cout << "Animal: lion\n";
	Animal::printDetails();
}

void Lion::move()
{
	if (!canMove)
	{
		dir = static_cast<direction> (rand() % 2);
	}
	Animal::move();
}
