#pragma once
#include "Animal.h"

enum direction { up, down, right, left };
class Monkey : public Animal
{
	int stepSize=1;
	int numOfSteps;
	bool goHead = true;
public:

	Monkey(const Location& loc, std::string& name);
	char getInitial() const override;
	void step() override;
	void printDetails() const;
	void move();
};
