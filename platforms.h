#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class platform
{
public:
	platform();
	static int SearchVectorForPlatforms(std::vector<platform> &vector,sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1);
	sf::Sprite * platformSprite;
	platform(sf::Sprite * sprite, float x, float y);
	sf::Sprite * getSprite();
	int x;
	int y;




protected:
	
};

