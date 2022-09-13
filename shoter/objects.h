#pragma once
#include"coordinates.h"
#include <SFML/Graphics.hpp>

class rect
{
public:
	rect(coordinates& xy, coordinates& size);
	rect();
	void setCharacteristics(const double& x, const double& y, const double& sizeX, const double& sizeY);

	coordinates xy[4];
	sf::RectangleShape body;
};
