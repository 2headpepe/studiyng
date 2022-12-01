#include"objects.h"

rect::rect(coordinates& xy, coordinates& size)
{
	rectangle.setPosition(xy.x, xy.y);
	rectangle.setSize(sf::Vector2f(size.x, size.y));

	this->xy[0] = xy;
	xy.x += size.x;
	this->xy[1] = xy;
	xy.y += size.y;
	this->xy[2] = xy;
	xy.x -= size.x;
	this->xy[3] = xy;
}

rect::rect()
{

}

void rect::setCharacteristics(const double& x, const double& y, const double& sizeX, const double& sizeY)
{
	rectangle.setPosition(x, y);
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));

	coordinates xy(x, y);
	this->xy[0] = xy;
	xy.x += sizeX;
	this->xy[1] = xy;
	xy.y += sizeY;
	this->xy[2] = xy;
	xy.x -= sizeX;
	this->xy[3] = xy;
}
