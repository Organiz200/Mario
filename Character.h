#pragma once
#include <vector>
#include "platforms.h"
#include <SFML/Window.hpp>
#include "class1.h"

class Character
{
public:

	Character();
	int isOnPlatform(std::vector<platform>& vector, int screenWidth, int &characterX, int &characterY, int & isGoingDown, int &characterOnBar, float& positionY, int & platformX, int & platformY);

	int movesLeft(class1 classA ,sf::RenderWindow &window ,int& goingDown, int& characterLeft, int& characterRight, int SCREENWIDTH, std::vector<platform> vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, int& characterOnBar, float positionY);
	
};

