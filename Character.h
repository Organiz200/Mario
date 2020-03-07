#pragma once
#include <vector>
#include "platforms.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Character
{
public:

	Character();
	int isOnPlatform(sf::RenderWindow& window, sf::Sprite& marioSpriteR, sf::Sprite& marioSpriteL, int SCEENHEIGHT, int  goingDown, std::vector<platform>& vector, int screenWidth, int& characterX, int& characterY, int& isGoingDown, float& positionY);
	
	int movesLeft(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY,std::vector<platform> &vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float &positionY);
	int movesRight(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY);
	
};

