#include "platforms.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>"
platform::platform(sf::Sprite * sprite, float x, float y)
{
	platformSprite = sprite;
	this->x = x;
	this->y = y;
}
sf::Sprite * platform::getSprite()
{
	return(platformSprite);
}

//loop through platforms and move them horizontally
int platform::SearchVectorForPlatforms(std::vector<platform>& vector,sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1)
{

	sf::Sprite * gottenSprite;// = NULL;


	for (std::vector<platform>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		//sprite is platform
		gottenSprite = it->getSprite();

		//character faces left
		if (isLeft1 == 1)
		{
			it->x = it->x + changeX;

			gottenSprite->setPosition((it->x), it->y);
		}

		if (isLeft1 == 0)
		{
			it->x = it->x - changeX;
			gottenSprite->setPosition((it->x), it->y);
		}

		if (it->x > -150 && it->x < (800))
		{

			inWindow.draw(*it->platformSprite);
		}
	}
	Sleep(10);
	
	return(1);
}