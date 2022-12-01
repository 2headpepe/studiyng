#include "iostream"
#include"player.h"
#include"variables.h"

double findNeighbour(const coordinates& A, const double& angle, const std::vector<rect>& rects);

player::player()
{
	int x = mapSizeX/2, y = mapSizeX / 2;
	location = coordinates(x, y);
	body.rectangle.setFillColor(sf::Color(240, 128, 128));
	body.rectangle.setSize(sf::Vector2f(bodySize,bodySize));
	view.setCharacteristics(location.x + bodySize/2, location.y + bodySize / 2, vision, 1);
	view.rectangle.rotate(angle + viewAngle / 2);
	weapons.push_back(weapon());
}
player::player(const coordinates& coor)
{
	location = coor;
	body.rectangle.setFillColor(sf::Color(240, 128, 128));
	body.rectangle.setSize(sf::Vector2f(bodySize, bodySize));
	view.setCharacteristics(location.x + bodySize / 2, location.y + bodySize / 2, vision, 1);
	view.rectangle.rotate(angle + viewAngle/2);
	weapons.push_back(weapon());
}
weapon::weapon()
{
	double weaponSizeX = 490, weaponSizeY = 240;
	weaponPosition = sf::Vector2f(worldSizeX - weaponSizeX, worldSizeY - weaponSizeY);


	sf::Image weaponImg;
	bool flag =weaponImg.loadFromFile("images/ak47.png");
	std::cout << flag;
	sf::Texture weaponTexture;//создаем объект Texture (текстура)
	weaponTexture.loadFromImage(weaponImg);//передаем в него объект Image (изображения)
	sf::Sprite weaponSprite;//создаем объект Sprite(спрайт)
	weaponSprite.setTexture(weaponTexture);//передаём в него объект Texture (текстуры)
	weaponSprite.setPosition(weaponPosition);//задаем начальные координаты появления спрайта
	weaponSprite.setScale(weaponSizeX / weaponSprite.getLocalBounds().width, weaponSizeY / weaponSprite.getLocalBounds().height);

	img = weaponSprite;
	sizeX = weaponSizeX;
	sizeY = weaponSizeY;
}


void player::setPosition(sf::Vector2f newPos)
{
	body.rectangle.setPosition(newPos);
	//t.setPosition(newPos.x + body.getGlobalBounds().width / 2 - t.getGlobalBounds().width / 2, body.getPosition().y - t.getGlobalBounds().height);
};
void  player::draw(sf::RenderWindow& wind)
{

}