#pragma once
#include <SFML/Graphics.hpp>
#include"coordinates.h"
#include<cmath>
#include"objects.h"
#include"variables.h"
#include<string>


class weapon
{
public:
	sf::Sprite img;
	int id=0;
	weapon();
	int sizeX = 0, sizeY = 0;
	sf::Vector2f weaponPosition;
};

class player
{
public:
	player();
	player(const coordinates& coor);

	double angle = 0;
	double speedY = mapSizeX/50 * sin(angle*pi/180);
	double speedX = mapSizeX/50 * cos(angle*pi/180);

	coordinates location;

	sf::CircleShape body;
	double bodySize=mapSizeX/100;


	double viewAngle = 90;
	double vision = mapSizeX/8;
	rect view;
	int playerNum = 0;
	std::string name;

private:
	

};



