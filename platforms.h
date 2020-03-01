#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class platform
{
public:
	sf::Sprite * platformSprite;
	platform(sf::Sprite * sprite, float x, float y);
	sf::Sprite * getSprite();
	float x;
	float y;

protected:
	
};

