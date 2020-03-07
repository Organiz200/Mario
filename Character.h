#pragma once
#include <vector>
#include "platforms.h"
class Character
{
public:

	Character();
	int isOnPlatform(int SCREENHEIGHT, int goingDown, std::vector<platform>& vector, int screenWidth, int &characterX, int &characterY, int & isGoingDown, int &characterOnBar, float& positionY, int & platformX, int & platformY);
	int movesLeft(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY,std::vector<platform> &vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, int& characterOnBar, float &positionY);
	int movesRight(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, int& characterOnBar, float& positionY);
	
};

