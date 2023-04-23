#pragma once
#include "Animal.h"


class Dog : public Animal
{

	bool goHead = true;
public:

	Dog(const Location& loc, std::string& name);
	char getInitial() const override;
	void step() override;
	void printDetails() const;
	void move();
};
