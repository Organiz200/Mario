#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <vector>
#include "platforms.h"
#include "Character.h"
#include "class1.h"

int const SCREENWIDTH = 800;
int const SCREENHEIGHT = 600;

Character character;
class1 classA;
sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
std::vector<platform> vectorPlatforms;
//void SearchVectorForPlatforms(sf::RenderWindow & inWindow, float deltaX, float deltaY, int isLeft);
int virtualJump(Character & character, std::vector<platform> vector, float& platPositionX, float& platPositionY, float& platVelocityY, float& platVelocityX,
	float& platGravity, int& isLeft, sf::RenderWindow& window, sf::Sprite & marioSpriteR, sf::Sprite &marioSpriteL, int& GoingDown, int& characterOnBar
	);
sf::Sprite* gottenSprite;
int characterOnBar = 0;
int answer = 0;
int answer1 = 0;
int goingDown = 0;
int gPlatformX = 0;
int gPlatformY = 0;
int main()
{
	sf::Sprite marioSpriteL;
	sf::Sprite marioSpriteR;
	sf::Sprite structure1Sprite;
	sf::Sprite structure2Sprite;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;

	float positionX = ((SCREENWIDTH / 2) - (76 / 2));
	float positionY = (SCREENHEIGHT - 76);
	float x = positionX;
	float y = positionY;
	float velocityY = -15.0f;
	float velocityX = 4.0f;
	float gravity = 0.5f;

	
	//float platGravity = 0.5f;
	

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
	structure1Sprite.setPosition(400,400);
	structure2Sprite.setTexture(texture3);
	structure2Sprite.setPosition(500, 500);
	platform platformObject(&structure1Sprite, 400, 400);
	platform platformObject1(&structure2Sprite, 500, 200);

	//platform platformObject1(&structure1Sprite, 600, 200);
	//platform platformObject2(&structure1Sprite, 600, 400);
	//platform platformObject3(&structure1Sprite, 800, 200);
	//platform platformObject4(&structure1Sprite, 800, 400);
	//platform platformObject5(&structure1Sprite, 1000, 200);
	//platform platformObject6(&structure1Sprite, 1000, 400);
	//platform platformObject7(&structure1Sprite, 1200, 200);

	vectorPlatforms.push_back(platformObject);
	vectorPlatforms.push_back(platformObject1);
	//vectorPlatforms.push_back(platformObject3);
	//vectorPlatforms.push_back(platformObject4);
	//vectorPlatforms.push_back(platformObject5);
	//vectorPlatforms.push_back(platformObject6);
	//vectorPlatforms.push_back(platformObject7);

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
			virtualJump(character, vectorPlatforms, positionX, positionY, velocityY, velocityX,
				gravity, isLeft, window, marioSpriteR, marioSpriteL, goingDown, characterOnBar);
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
			classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
			window.draw(marioSpriteR);
			window.display();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

			isLeft = 0;
			
			x = x + 1;
			positionX++;
			marioSpriteR.setPosition(x, y);
			marioSpriteL.setPosition(x, y);
			window.clear();
			classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
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
						velocityY = -15;
						velocityX = 4.0;
						x = positionX;
						break;
					}
					window.clear();
					marioSpriteL.setPosition(positionX, positionY);
					marioSpriteR.setPosition(positionX, positionY);
					classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
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
						velocityY = -15;
						velocityX = 4.0;
						x = positionX;
						break;
					}
					window.clear();
					marioSpriteL.setPosition(positionX, positionY);
					marioSpriteR.setPosition(positionX, positionY);
					window.draw(marioSpriteL);
					classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
					window.display();
					Sleep(20);

				}
			} while (1);
		}
		//left
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{	//josh, ?
			isLeft = 1;
			//displays platforms and moves them

			classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
			//structure1Sprite.setPosition(400+, 400);

			//if (characterOnBar)
			//{
			//	
			//}
			//
			//sf::Vector2f  position = marioSpriteL.getPosition();
			//int temp1 = position.x;
			//int temp2 = position.y;

			//int onPlat = character.isOnPlatform(vector, SCREENWIDTH,temp1,temp2,);
			////if not on a platform, and on ground walk
			////if not on a platform, walk left, checking for end of platform
			////isonplatform = 1 ; on platform
		}
		//right
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			sf::Vector2f  position = marioSpriteL.getPosition();
			int temp1 = 362;
			//josh -5
			int temp2 = position.y;

			character.movesLeft(classA, window, goingDown, temp1, temp2, SCREENWIDTH, vectorPlatforms, marioSpriteL, marioSpriteR, character, isLeft, characterOnBar, positionY);
		}
	
		window.clear();
		if (isLeft == 0)
		{
			classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
			window.draw(marioSpriteL);
		}
		else
		{
			classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
			window.draw(marioSpriteR);
		}
		window.display();


	}
	
}

//loop through platforms and move them horizontally

//moves character up and down  and moves platforms too (left and right)
int virtualJump(Character & character, std::vector<platform> vector, float &positionX, float &positionY, float& velocityY, float & velocityX,
	float & gravity, int & isLeft, sf::RenderWindow & window, sf::Sprite & marioSpriteR, sf::Sprite& marioSpriteL, int & goingDown, int& characterOnBar)
{
	goingDown = 0;
	int temp1 = 0;
	int temp2 = 0;
	int platformX = 0;
	int platformY = 0;
	//Character character;
	
	do {

	
	if (isLeft == 1)
	{
		velocityX = -4;
	}
	else
	{
		velocityX = 4;
	}
	int firstPositionX = positionX;
	int firstPositionY = positionY;
	positionY += velocityY;
	positionX += 0;
	velocityY += gravity;
	int secondPositionY = positionY;
	int secondPositionX = positionX;
	//if positive going down
	int horizontalChange = secondPositionX - firstPositionX;
	
	//change all platforms horizontal amount difference
	for (std::vector<platform>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		if (isLeft == 1)
		{
			it->x = it->x + 4;// -horizontalChange;
		}
		else
		{
			it->x = it->x - 4;
			//it->x = it->x - 1;// horizontalChange;
		}
	}

	
	if (firstPositionY <= secondPositionY)
	{
		goingDown = 1;
	}
	

	if (isLeft == 1)
	{
		
		
		
		if (positionY > (600 - 76))
		{	
			
			positionY = (600 - 76);
			marioSpriteL.setPosition((800 / 2) - (76 / 2), 600 - 76);
			marioSpriteR.setPosition((800 / 2) - (76 / 2), 600 - 76);

			velocityY = -15;
			velocityX = 4.0;
			positionX = (800-76/2); 
			break;
		}
		

		
		sf::Vector2f  position = marioSpriteL.getPosition();
		int temp1 = 362;
		//josh -5
		int temp2 = position.y;
		//marioSpriteL.setPosition(, temp2);
		//marioSpriteR.setPosition(temp1, temp2);



		
		//two last parameters return a value, they don't do anything fof the function called
		int answer1 = character.isOnPlatform(vector, 800, temp1, temp2, goingDown, characterOnBar, positionY, gPlatformX, gPlatformY);


		if (answer1 == 0)
		{
			//moves mario up and down
			marioSpriteL.setPosition((SCREENWIDTH / 2) - (76 / 2), positionY);
			marioSpriteR.setPosition((SCREENWIDTH / 2) - (76 / 2), positionY);
			window.clear();
			window.draw(marioSpriteR);
		}
		else
		{	//standing on platform
			window.clear();
			marioSpriteL.setPosition(temp1, temp2);
			marioSpriteL.setPosition(temp1, temp2);
			window.draw(marioSpriteR);
			positionY = (temp2);
			velocityY = -15;
			velocityX = 4.0;
			positionX = 600 - 76 / 2;
			break;
			
		}



		classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
		window.display();
		Sleep(40);
	}
	
	////////////////////////////right
	else
	{

		
		if (positionY > (600 - 76 ))
		{
			positionY = (600 - 76);
			marioSpriteL.setPosition((800 / 2) - (76 / 2), 600 - 76);
			marioSpriteR.setPosition((800 / 2) - (76 / 2), 600 - 76);

			velocityY = -15;
			velocityX = 4.0;
			positionX = 800 - 76/2;
			break;
		}
		


		/////////////
		

		//returns platform x and platform y
		int answer1 = character.isOnPlatform(vector, 800, temp1, temp2, goingDown, characterOnBar, positionY, platformX, platformY);
		if (answer1 == 0)
		{
			
			marioSpriteL.setPosition((SCREENWIDTH / 2) - (76 / 2), positionY);
			marioSpriteR.setPosition((SCREENWIDTH / 2) - (76 / 2), positionY);
			window.clear();
			window.draw(marioSpriteL);
		}
		else
		{	//character stands
			window.clear();
			marioSpriteL.setPosition(temp1, temp2);
			marioSpriteL.setPosition(temp1, temp2);
			window.draw(marioSpriteL);
			positionY = (temp2);
			velocityY = -15;
			velocityX = 4.0;
			positionX = (temp1);
			break;
			//characterY = characterY - 30;

			//window.display();
		}
		classA.SearchVectorForPlatforms(vectorPlatforms, window, 0, 0, 1);
		window.display();
		Sleep(20);
		
	}
	
} while (1);
return(1);

}