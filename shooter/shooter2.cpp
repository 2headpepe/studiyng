#include <SFML/Graphics.hpp>
#include<vector>
#include"objects.h"
#include<iostream>
#include"player.h"
#include"variables.h"

#include<SFML/Network.hpp>
#include<string>
#include<Windows.h>

int mapSizeX = 200;
int mapSizeY = mapSizeX;
int worldSizeX = mapSizeX * 5;
int worldSizeY = mapSizeX * 3;
int boardSize = mapSizeX / 50;
double pi = 4 * atan(1);
int countRays = 100;





double findNeighbour(const coordinates& A,const double& angle, const std::vector<rect>& rects)
{
    double dist=mapSizeX;

    double len = mapSizeX;

    coordinates AB;
    AB.x = len * cos(angle * pi / 180);
    AB.y = -len * sin(angle * pi / 180);

    coordinates CD;

    coordinates AC;
    coordinates AD;

    coordinates CA;
    coordinates CB;

    coordinates P;
    double Z1,Z2;

    for (rect rectangle : rects)
    {
        for (int i = 0; i < 4; ++i)
        {
            int j = (i + 1) % 4;

            bool flag = 0;

            AC.x = rectangle.xy[i].x - A.x;
            AC.y = rectangle.xy[i].y - A.y;

            AD.x = rectangle.xy[j].x - A.x;
            AD.y = rectangle.xy[j].y - A.y;

            Z1 = AB.x * AC.y - AB.y * AC.x;
            Z2 = AB.x * AD.y - AB.y * AD.x;

            flag = ((Z1 * Z2) < 0);

            if (flag)
            {

                CA.x = -AC.x;
                CA.y = -AC.y;

                CB.x = A.x + len * cos(angle * pi / 180) - rectangle.xy[i].x;
                CB.y = A.y - len * sin(angle * pi / 180) - rectangle.xy[i].y;

                CD.x = rectangle.xy[j].x - rectangle.xy[i].x;
                CD.y = rectangle.xy[j].y - rectangle.xy[i].y;

                flag = (((CD.x * CA.y - CD.y * CA.x) * (CD.x * CB.y - CD.y * CB.x)) < 0);
                if (flag)
                {
                    double Z = ((Z1 / (Z2 - Z1)) > 0) ? Z1 / (Z2 - Z1) : -Z1 / (Z2 - Z1);

                    P.x = rectangle.xy[i].x + (rectangle.xy[j].x - rectangle.xy[i].x) * Z;
                    P.y = rectangle.xy[i].y + (rectangle.xy[j].y - rectangle.xy[i].y) * Z;

                    double dist1 = sqrt(pow(P.x - A.x, 2) + pow(P.y - A.y, 2));

                    dist = ((dist1 < dist)) ? dist1 : dist;
                }
            }
        }
    }
    return dist;
}
void map(const sf::RenderWindow& window, std::vector<rect>& boards)
{
    // ГРАНИЦА КАРТЫ

    boards[0].setCharacteristics(boardSize, boardSize, mapSizeX - boardSize * 2, boardSize);
    boards[1].setCharacteristics(mapSizeX - boardSize * 2, boardSize, boardSize, mapSizeX - boardSize * 2);
    boards[2].setCharacteristics(boardSize, mapSizeX - boardSize * 2, mapSizeX - boardSize * 2, boardSize);
    boards[3].setCharacteristics(boardSize, boardSize, boardSize, mapSizeX - boardSize * 2);


    // СТЕНЫ ВНУТРИ КАРТЫ

    boards[4].setCharacteristics(mapSizeX / 7, mapSizeY / 6, mapSizeX / 7, mapSizeY * 3 / 5);
    boards[5].setCharacteristics(mapSizeX / 2, mapSizeY / 2, mapSizeX / 7, mapSizeY / 6);
    boards[6].setCharacteristics(mapSizeX / 1.7, mapSizeY / 2.5, mapSizeX / 6, mapSizeY / 6);

}



//Player player(true);

int main()
{
    
   
    
    sf::RenderWindow window(sf::VideoMode(worldSizeX, worldSizeY), "Source 2");

    player player1;    //Игрок

  
    std::vector<rect> boards(7);
    map(window, boards);
   
    std::vector<rect> playersView;

    rect* walls = new rect[countRays];
    //weapon playerWeapon;



    int flag = 1;

    while (window.isOpen())
    {
       


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                player1.angle += 10;
                player1.view.rectangle.rotate(-10);
                player1.speedX = mapSizeX/100 * cos(player1.angle * pi/ 180);
                player1.speedY = mapSizeX / 100 * sin(player1.angle * pi / 180);
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                player1.angle-=10;
                player1.view.rectangle.rotate(10);
                player1.speedX = mapSizeX / 100 * cos(player1.angle * pi / 180);
                player1.speedY = mapSizeX / 100 * sin(player1.angle * pi / 180);

                //if (player1.weapons[player1.weaponNum].img.getPosition().y <= worldSizeY - player1.weapons[player1.weaponNum].sizeY) flag = 1;
                //if (player1.weapons[player1.weaponNum].img.getPosition().y >= worldSizeY - player1.weapons[player1.weaponNum].sizeY + 50) flag = 0;

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                player1.location.y -= player1.speedY;
                player1.location.x += player1.speedX;
                player1.view.rectangle.setPosition(player1.location.x+player1.bodySize/2, player1.location.y+ player1.bodySize / 2);

                //if (player1.weapons[player1.weaponNum].img.getPosition().y <= worldSizeY - player1.weapons[player1.weaponNum].sizeY) flag = 1;
                //if (player1.weapons[player1.weaponNum].img.getPosition().y >= worldSizeY - player1.weapons[player1.weaponNum].sizeY + 30) flag = 0;

                //if (flag)
                //{
                //    //weaponPosition.x += weapon;
                //    player1.weapons[player1.weaponNum].weaponPosition.y += player1.weapons[player1.weaponNum].weaponSpeed;
                //}
                //else
                //{
                //    //weaponPosition.x -= 0.3;
                //    player1.weapons[player1.weaponNum].weaponPosition.y -= player1.weapons[player1.weaponNum].weaponSpeed;
                //}
                //player1.weapons[player1.weaponNum].img.setPosition(player1.weapons[player1.weaponNum].weaponPosition);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                player1.location.y += player1.speedY;
                player1.location.x -= player1.speedX;
                player1.view.rectangle.setPosition(player1.location.x+ player1.bodySize / 2, player1.location.y+player1.bodySize / 2);

                //if (player1.weapons[player1.weaponNum].img.getPosition().y <= worldSizeY - player1.weapons[player1.weaponNum].sizeY) flag = 1;
                //if (player1.weapons[player1.weaponNum].img.getPosition().y >= worldSizeY - player1.weapons[player1.weaponNum].sizeY + 30) flag = 0;

                //if (flag)
                //{
                //    //weaponPosition.x += weapon;
                //    player1.weapons[player1.weaponNum].weaponPosition.y += player1.weapons[player1.weaponNum].weaponSpeed;
                //}
                //else
                //{
                //    //weaponPosition.x -= 0.3;
                //    player1.weapons[player1.weaponNum].weaponPosition.y -= player1.weapons[player1.weaponNum].weaponSpeed;
                //}
                //player1.weapons[player1.weaponNum].img.setPosition(player1.weapons[player1.weaponNum].weaponPosition);
            }
            player1.body.rectangle.setPosition(player1.location.x, player1.location.y);

            
            
        }
        window.clear();
    
        
        for (int i = 0; i < countRays; i ++)
        {

            int len = findNeighbour(player1.location, player1.angle - player1.viewAngle / 2 + player1.viewAngle/countRays * i, boards);
            player1.view.rectangle.setSize(sf::Vector2f(len, 1));
            window.draw(player1.view.rectangle);
            player1.view.rectangle.rotate(-player1.viewAngle/countRays);
        }

        window.draw(player1.view.rectangle);
        player1.view.rectangle.rotate(player1.viewAngle);




        //Отрисовка мира

        sf::RectangleShape backGround(sf::Vector2f(0, 0));
        backGround.setSize(sf::Vector2f(worldSizeX, worldSizeY/2));
        backGround.setFillColor(sf::Color(149, 200, 216));
        window.draw(backGround);

        sf::RectangleShape floor;
        floor.setPosition(sf::Vector2f(0, worldSizeY / 2));
        floor.setSize(sf::Vector2f(worldSizeX, worldSizeY / 2));

        floor.setFillColor(sf::Color(227, 203, 165));
        window.draw(floor);
        
        double* distance = new double[countRays];
        bool* flag = new bool[countRays];
        for (int i = 0; i < countRays;++i)
        {
            distance[i] = findNeighbour(player1.location, player1.angle - player1.viewAngle / 2 + player1.viewAngle * i / countRays, boards);
            /*double newDist = findNeighbour(player1.location, player1.angle - player1.viewAngle / 2 + player1.viewAngle * i / countRays, playersView);
            if (distance[i] > newDist)
            {
                distance[i] = newDist;
                flag[i] = 1;
            }
            else flag[i] = 0;*/
        }

        double coef = 5;
        coordinates wallsSize(10, worldSizeY / distance[0] * coef);
        coordinates wallsLocation(worldSizeX - 10, worldSizeY/2 * (1 - coef/distance[0]));


        sf::Color wallsColor(255, 151, 187);
        for (int i = 0; i < countRays; ++i)
        {
            wallsLocation.y = worldSizeY / 2 - worldSizeY / 2 *coef/distance[i];
            wallsSize.y = worldSizeY * coef / distance[i];
        
            double distCoef = pow(1.01, distance[i]);
            if (distance[i] >= 100) distCoef = pow(1.01, 100);

            //if(!flag[i])
                walls[i].rectangle.setFillColor(sf::Color(wallsColor.r/distCoef, wallsColor.g / distCoef,wallsColor.b /distCoef));
            //else 
            //    walls[i].rectangle.setFillColor(sf::Color(0,0,0));

            walls[i].setCharacteristics(wallsLocation.x, wallsLocation.y, wallsSize.x, wallsSize.y);
            window.draw(walls[i].rectangle);
            
            wallsLocation.x -= wallsSize.x;
            
            

        }
        

        //Отрисовка мини-карты
        /*sf::RectangleShape mapBackGround;
        mapBackGround.setSize(sf::Vector2f(mapSizeX, mapSizeY));
        mapBackGround.setFillColor(sf::Color(252, 221, 118));
        window.draw(mapBackGround);*/

        //weapon



        window.draw(player1.weapons[0].img);



        for (int i = 0; i < 6; ++i)
        {

            window.draw(boards[i].rectangle);
        }
        window.draw(player1.body.rectangle);

        

        window.display();
    }


    delete[] walls;
    boards.clear();
    return 0;    
}




