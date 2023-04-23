#include "../include/Location.h"
std::ostream& operator<<(std::ostream& os, const Location& loc)
{
	os << "(" << loc.row << " , " << loc.col << " ) ";
	return os;
}

bool Location::operator==(const Location& loc)
{
	return loc.row==row && loc.col==col;
}

bool Location::operator!=(const Location& loc)
{
	return loc.row != row || loc.col != col;
}

Location Location::operator+(Location loc)
{
	return Location(loc.row+row,loc.col+col);
}

Location Location::operator+=(Location loc)
{
	row += loc.row;
	col += loc.col;
	return *this;
}