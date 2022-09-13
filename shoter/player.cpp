#include"player.h"
#include"variables.h"

player::player()
{
	int x = mapSizeX/2, y = mapSizeX / 2;
	location = coordinates(x, y);
	body.setFillColor(sf::Color(240, 128, 128));
	body.setRadius(bodySize);
	view.setCharacteristics(location.x + bodySize/2, location.y + bodySize / 2, vision, 1);
	view.body.rotate(angle + viewAngle / 2);
}
player::player(const coordinates& coor)
{
	location = coor;
	body.setFillColor(sf::Color(240, 128, 128));
	body.setRadius(bodySize);
	view.setCharacteristics(location.x + bodySize / 2, location.y + bodySize / 2, vision, 1);
	view.body.rotate(angle + viewAngle/2);
}
weapon::weapon()
{
	double weaponSizeX = 490, weaponSizeY = 240;
	weaponPosition = sf::Vector2f(worldSizeX - weaponSizeX, worldSizeY - weaponSizeY);


	sf::Image weaponImg;
	weaponImg.loadFromFile("images/ak47.png");

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
