#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <vector>
#include "platforms.h"



int const SCREENWIDTH = 800;
int const SCREENHEIGHT = 600; 

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
std::vector<platform> vectorPlatforms;
void SearchVectorForPlatforms(sf::RenderWindow & inWindow, float deltaX, float deltaY);

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			isLeft = 1;
			


			x = x - 1;
			positionX--;
			marioSpriteL.setPosition(x, y);
			marioSpriteR.setPosition(x, y);
			window.clear();
			SearchVectorForPlatforms(window,0,0);
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
			SearchVectorForPlatforms(window,0,0);
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
					window.display();
					Sleep(20);
					
				}
			} while (1);
		}

		window.clear();
		if (isLeft == 0)
		{
			SearchVectorForPlatforms(window,0,0);
			window.draw(marioSpriteL);
		}
		else
		{
			SearchVectorForPlatforms(window,0,0);
			window.draw(marioSpriteR);
		}
		window.display();


	}
	
}


void SearchVectorForPlatforms(sf::RenderWindow & inWindow, float changeX, float changeY)
{
	
	sf::Sprite * gottenSprite;
	for (std::vector<platform>::iterator it = vectorPlatforms.begin(); it != vectorPlatforms.end(); ++it)
	{
		//sprite is platform
		gottenSprite = it->getSprite();
		gottenSprite->setPosition(it->x + changeX, it->y + changeY);
		if (it->x > 0 && it->x < 600 - 76)
		{
			 
			inWindow.draw(*it->platformSprite);
		}
	}
}