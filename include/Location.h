#pragma once
#include <iostream>

struct Location
{
	int row;
	int col;
	friend std::ostream& operator<<(std::ostream& os, const Location& loc);
	bool operator==(const Location& loc);
	bool operator!=(const Location& loc);
	Location operator+(Location loc);
	Location operator+=(Location loc);

};
