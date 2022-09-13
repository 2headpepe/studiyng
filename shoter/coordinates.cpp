#include"coordinates.h"

coordinates::coordinates()
{
	x = 0;
	y = 0;
}
coordinates::coordinates(const double& x, const double& y)
{
	this->x = x;
	this->y = y;
}
coordinates coordinates::operator=(const coordinates& coor)
{
	this->x = coor.x;
	this->y = coor.y;
	return *this;
}
coordinates coordinates::operator+=(const coordinates& coor)
{
	this->x += coor.x;
	this->y += coor.y;
	return *this;
}
