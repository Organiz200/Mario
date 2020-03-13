#pragma once
#include <vector>
#include "platforms.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "platforms.h"
#include <windows.h>

class Character
{
public:
	platform  platform1;
	// full scroll is zero to 800 * 5
	int rightEndzoneLine;
	int leftEndzoneLine;
	int currentCharacterPlacement;
	Character( );
	int isOnPlatform(sf::RenderWindow& window, sf::Sprite& marioSpriteR, sf::Sprite& marioSpriteL, int SCEENHEIGHT, int  goingDown, std::vector<platform>& vector, int screenWidth, int& characterX, int& characterY, int& isGoingDown, float& positionY, float & positionX);
	
	int movesLeft(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY,std::vector<platform> &vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float &positionY, float &positionX);
	int movesRight(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY, float & positionX);
	
	int movesRightInEndZoneToo(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY, float &positionX);
	
	int movesLeftInEndZoneToo(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& temp1, int& temp2, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY, float& positonX);
	
	
	int JumpInEndZone(int& line, int SCREENWIDTH, int SCREENHEIGHT, Character& character, std::vector<platform>& vector, float& positionX, float& positionY, float& velocityY, float& velocityX,
		float& gravity, int& isLeft, sf::RenderWindow& window, sf::Sprite& marioSpriteR, sf::Sprite& marioSpriteL, int& goingDown, int& characterOnBar);
	

	


};

