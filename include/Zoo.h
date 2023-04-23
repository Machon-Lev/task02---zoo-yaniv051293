#pragma once
//Yaniv
#include "Animal.h"
#include<vector>
#include <iostream>
#include <string> // for string class

using namespace std;

class Zoo {
	vector <Animal*> animals;

	void move(int animalNum);
	void stop(int animalNum);
	void create(std::string animalType, std::string animalName);
	void del(int animalNum);
	void delAll(std::string animalType);
	void help();
	void step();
	void drawZoo();
public:
	Zoo();
	void run();
};