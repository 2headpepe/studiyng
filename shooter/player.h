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
	weapon();

	sf::Sprite img;
	int id=0;
	int sizeX = 0, sizeY = 0;
	sf::Vector2f weaponPosition;
	int weaponSpeed=1;
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

	rect body;
	double bodySize=mapSizeX/100;


	double viewAngle = 90;
	double vision = mapSizeX/8;
	rect view;
	int playerNum = 0;
	std::string name;

	std::vector<weapon> weapons;
	int weaponNum = 0;

	void setPosition(sf::Vector2f newPos);
	void  draw(sf::RenderWindow& wind);
private:
	

};



