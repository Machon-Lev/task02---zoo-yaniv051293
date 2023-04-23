#pragma once
#include "Location.h"


class Animal {
	
protected:
	enum direction { right, left, up, down };
	Location loc;
	std::string name;
	bool canMove = true;
	direction dir;
	void handleExepectionLocation();
public:
	Animal();
	Animal(Location l, std::string n) :loc(l), name(n), dir(right){}
	 Location getLocation() const;
	 virtual void printDetails() const;
	 virtual char getInitial() const=0;
	 virtual void step() = 0;
	 void stop();
	 virtual void move();
	 void turnVertically();
	 void turnHorizontally();

};