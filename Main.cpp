#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <vector>
#include "platforms.h"


int const SCREENWIDTH = 800;
int const SCREENHEIGHT = 600; 

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
std::vector<platform> vectorPlatforms;
void SearchVectorForPlatforms(sf::RenderWindow & inWindow, float deltaX, float deltaY, int isLeft);
void virtualJump(float& platPositionX, float& platPositionY, float& platVelocityY, float& platVelocityX,
	float& platGravity, int& isLeft, sf::RenderWindow& window, sf::Sprite  marioSpriteR, sf::Sprite marioSpriteL,
	float& x, float& y, float& charX, float &charY);
sf::Sprite* gottenSprite;

int main()
{
	sf::Sprite marioSpriteL;
	sf::Sprite marioSpriteR;
	sf::Sprite structure1Sprite;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;

	float positionX = ((SCREENWIDTH / 2) - (76 / 2));
	float positionY = (SCREENHEIGHT - 76);
	float x = positionX;
	float y = positionY;
	float velocityY = -10.0f;
	float velocityX = 4.0f;
	float gravity = 0.5f;

	float platPositionY = 400;
	float platVelocityY = -10.0f;
	float platPositionX = positionY;
	float platVelocityX = 4.0f; 
	float platGravity = 0.5f;
	float platX = 0;
	float platY = 0;

	if (!texture1.loadFromFile("mario_L.png"))
	{
		// error...
	}
	if (!texture2.loadFromFile("mario_R.png"))
	{
		// error...
	}
	if (!texture3.loadFromFile("structure1.png"))
	{
		// error...
	}
	marioSpriteL.setTexture(texture2);
	marioSpriteR.setTexture(texture1);
	structure1Sprite.setTexture(texture3);

	platform platformObject(&structure1Sprite, 400, 400);
	platX = 400;
	platY = 400;
	vectorPlatforms.push_back(platformObject);
	

	

	marioSpriteR.setPosition((SCREENWIDTH/2) - (76/2), (SCREENHEIGHT- 76));
	marioSpriteL.setPosition((SCREENWIDTH / 2) - (76 / 2), (SCREENHEIGHT - 76));
	int isLeft = 0;

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////jump/scroll//////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
		{


			virtualJump(platPositionX, platPositionY, platVelocityY, platVelocityX,
				platGravity, isLeft, window, marioSpriteR, marioSpriteL,
				x, y, platX, platY);
		}
		///////////////////////////////
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			isLeft = 1;



			x = x - 1;
			positionX--;
			marioSpriteL.setPosition(x, y);
			marioSpriteR.setPosition(x, y);
			window.clear();
			SearchVectorForPlatforms(window, 0, 0, 1);
			window.draw(marioSpriteR);
			window.display();


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

			isLeft = 0;
			//marioSpriteR.setTexture(texture2);
			// left key is pressed: move our character
			x = x + 1;
			positionX++;
			marioSpriteR.setPosition(x, y);
			marioSpriteL.setPosition(x, y);
			window.clear();
			SearchVectorForPlatforms(window, 0, 0, 0);
			window.draw(marioSpriteL);
			window.display();

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			do {
				if (isLeft == 1)
				{
					velocityX = -4;
				}
				else
				{
					velocityX = 4;
				}
				positionY += velocityY;
				positionX += velocityX;
				velocityY += gravity;

				if (isLeft == 1)
				{
					if (positionY > (SCREENHEIGHT - 76))
					{
						positionY = (SCREENHEIGHT - 76);
						y = positionY;
						velocityY = -10;
						velocityX = 4.0;
						x = positionX;
						break;
					}
					window.clear();
					marioSpriteL.setPosition(positionX, positionY);
					marioSpriteR.setPosition(positionX, positionY);
					SearchVectorForPlatforms(window, 0, 0,1);
					window.draw(marioSpriteR);
					window.display();
					Sleep(20);

				}
				else
				{
					if (positionY > (SCREENHEIGHT - 76))
					{
						positionY = (SCREENHEIGHT - 76);
						y = positionY;
						velocityY = -10;
						velocityX = 4.0;
						x = positionX;
						break;
					}
					window.clear();
					marioSpriteL.setPosition(positionX, positionY);
					marioSpriteR.setPosition(positionX, positionY);
					window.draw(marioSpriteL);
					SearchVectorForPlatforms(window, 0, 0,0);
					window.display();
					Sleep(20);

				}
			} while (1);
		}
		//left
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			SearchVectorForPlatforms(window, -1.0f, 0.0f, 1);
			//window.display();
		}
		//right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			SearchVectorForPlatforms(window, 1.0f, 0.0f, 0);
			//window.display();
		}
	
		window.clear();
		if (isLeft == 0)
		{
			SearchVectorForPlatforms(window,0,0,1);
			window.draw(marioSpriteL);
		}
		else
		{
			SearchVectorForPlatforms(window,0,0,0);
			window.draw(marioSpriteR);
		}
		window.display();


	}
	
}


void SearchVectorForPlatforms(sf::RenderWindow & inWindow, float changeX, float changeY, int isLeft)
{
	
	
	for (std::vector<platform>::iterator it = vectorPlatforms.begin(); it != vectorPlatforms.end(); ++it)
	{
		//sprite is platform
		gottenSprite = it->getSprite();
		
		//character faces left
		if (isLeft == 1)
		{
			it->x = it->x + changeX;
			gottenSprite->setPosition((it->x), it->y);
		}

		if (isLeft == 0)
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
}
void virtualJump(float &platPositionX, float &platPositionY, float& platVelocityY, float & platVelocityX,
	float & platGravity, int & isLeft, sf::RenderWindow & window, sf::Sprite  marioSpriteR, sf::Sprite marioSpriteL,
	float &x, float &y,float & platX, float & platY)
{
	
	int tempPlatX = platPositionX;
do {
	//jump landed
	if (platPositionY >= 600 - (76 / 2))
	{
		platPositionY = 600 - (76 / 2);
		break;
	}
	if (isLeft == 1)
	{
		platVelocityX = -4;
	}
	else
	{
		platVelocityX = 4;
	}
	platPositionY += platVelocityY;
	platPositionX += platVelocityX;
	platVelocityY += platGravity;

	if (isLeft == 1)
	{
		/*if (platPositionY >= 600 - (76 / 2))
		{
			platPositionY = 600 - (76 / 2);
			platVelocityY = -10;
			platVelocityX = -4;
			platX = platPositionX;
			platY = platPositionY;
			break;
		}*/
		//if there was a vertical movement it would reset here
		if (platPositionY > (400))
		{	
			platPositionY = 400;
			platY = platPositionY;
			platVelocityY = -10;
			platVelocityX = -4.0;
			platX = SCREENWIDTH - (76/2);
			break;
		}
		window.clear();
		marioSpriteL.setPosition((SCREENWIDTH/2) - (76 / 2), platPositionY);
		marioSpriteR.setPosition((SCREENWIDTH/2) - (76 / 2), platPositionY);
		SearchVectorForPlatforms(window, 1, 0, 1);
		window.draw(marioSpriteR);
		window.display();
		Sleep(40);

	}
	else
	{
		if (platPositionY > 400)
		{
			platPositionY = 400;
			platY = 400;
			platVelocityY = -10;
			platVelocityX = 4.0;
			platX = SCREENWIDTH - (76/2);
			break;
		}
		window.clear();
		marioSpriteL.setPosition((SCREENWIDTH/2) - (76/2), platPositionY);
		marioSpriteR.setPosition((SCREENWIDTH/2) - (76 / 2), platPositionY);
		window.draw(marioSpriteL);
		SearchVectorForPlatforms(window, 1, 0,0);
		window.display();
		Sleep(20);
		
	}
	//platVelocityX = platVelocityX - tempPlatX;

} while (1);
}