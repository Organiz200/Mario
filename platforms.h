#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>

class platform
{
public:
	sf::Sprite * platformSprite;
	platform(sf::Sprite * sprite, float x, float y);
	sf::Sprite * getSprite();
	int x;
	int y;
	//void SearchVectorForPlatforms(std::vector<platform> vectorPlatforms, sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1);

protected:
	
};

