#pragma once
#include "Animal.h"


class Lion : public Animal
{
public:
	Lion(const Location& loc, std::string& name);
	char getInitial() const override;
	void move();
	void step() override;
	void printDetails() const ;
 };
