#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <vector>
#include "platforms.h"
#include "Character.h"


//these defines are in main.cpp and character.cpp
#define VELOCITYX 2
#define VELOCITYY -30
#define POSXCENTER 362
#define GRAVITY 2

//	if changing jump there are searchable values needing change, and also isOnPlatform
//
//

int const SCREENWIDTH = 800;
int const SCREENHEIGHT = 600;

Character character;

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
std::vector<platform> vectorPlatforms;
void SearchVectorForPlatforms(sf::RenderWindow & inWindow, float deltaX, float deltaY, int isLeft);


int virtualJump(Character & character, std::vector<platform>& vector, float& platPositionX, float& platPositionY, float& platVelocityY, float& platVelocityX,
	float& platGravity, int& isLeft, sf::RenderWindow& window, sf::Sprite & marioSpriteR, sf::Sprite &marioSpriteL, int& GoingDown, int& characterOnBar
	);

int movesLeft(sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterRight, int SCREENWIDTH, std::vector<platform> vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, int& characterOnBar, float positionY);
//void resetJumpingVariables(/*float &velocityX,*/ float& velocityY, float gravity = 0.5f, float& positionX = SCREENWIDTH / 2 - 76 / 2, float& positionY = 600 - 76, int isLeft = 1);



sf::Sprite* gottenSprite;
int characterOnBar = 0;
int answer = 0;
int answer1 = 0;
int goingDown = 0;
int gPlatformX = 0;
int gPlatformY = 0;
//int currentCharacterPlacement = SCREENWIDTH/2 -( 76 / 2);
int line = 400 - (76 / 2);
int main()
{
	sf::Sprite marioSpriteL;
	sf::Sprite marioSpriteR;
	sf::Sprite structure1Sprite;
	sf::Sprite structure2Sprite;
	sf::Sprite structure3Sprite;

	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;

	float positionX = POSXCENTER;
	float positionY = (SCREENHEIGHT - 76);
	float x = positionX;
	float y = positionY;
	float velocityY = VELOCITYY;
	float velocityX = VELOCITYX;
	float gravity = GRAVITY;

	
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
	structure1Sprite.setPosition(400,200);
	structure2Sprite.setTexture(texture3);
	structure2Sprite.setPosition(600, 200);

	structure3Sprite.setTexture(texture3);
	structure3Sprite.setPosition(1050, 500);

	platform platformObject(&structure1Sprite, 400, 200);
	platform platformObject1(&structure2Sprite, 600, 200);
	platform platformObject2(&structure3Sprite, 1050, 500);
	//platform platformObject2(&structure1Sprite, 600, 400);
	//platform platformObject3(&structure1Sprite, 800, 200);
	//platform platformObject4(&structure1Sprite, 800, 400);
	//platform platformObject5(&structure1Sprite, 1000, 200);
	//platform platformObject6(&structure1Sprite, 1000, 400);
	//platform platformObject7(&structure1Sprite, 1200, 200);

	vectorPlatforms.push_back(platformObject);
	vectorPlatforms.push_back(platformObject1);
	vectorPlatforms.push_back(platformObject2);
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
			//virtualJump(character, vectorPlatforms, positionX, positionY, velocityY, velocityX,
			//	gravity, isLeft, window, marioSpriteR, marioSpriteL, goingDown, characterOnBar);

			//int JumpInEndZone(int& line, int& currentCharacterPlacement, int SCREENWIDTH, int SCREENHEIGHT, Character & character, std::vector<platform> & vector, float& positionX, float& positionY, float& velocityY, float& velocityX,
			//	float& gravity, int& isLeft, sf::RenderWindow & window, sf::Sprite & marioSpriteR, sf::Sprite & marioSpriteL, int& goingDown, int& characterOnBar)

			//josh, for now!!!!!!!!!- -change, maybe isLeft

			//isLeft = 1;
			character.JumpInEndZone(line, SCREENWIDTH, SCREENHEIGHT, character, vectorPlatforms, positionX, positionY, velocityY, velocityX,
				gravity, isLeft, window,   marioSpriteR,  marioSpriteL,goingDown, characterOnBar);


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
					velocityX = -VELOCITYX;
				}
				else
				{
					velocityX = VELOCITYX;
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
						velocityY = VELOCITYY;
						velocityX = VELOCITYX;
						x = positionX;
						break;
					}
					window.clear();
					marioSpriteL.setPosition(positionX, positionY);
					marioSpriteR.setPosition(positionX, positionY);
					SearchVectorForPlatforms(window, 0, 0,1);
					window.draw(marioSpriteR);
					window.display();
					Sleep(10);

				}
				else
				{
					if (positionY > (SCREENHEIGHT - 76))
					{
						positionY = (SCREENHEIGHT - 76);
						y = positionY;
						velocityY = VELOCITYY;
						velocityX = VELOCITYX;
						x = positionX;
						break;
					}
					window.clear();
					marioSpriteL.setPosition(positionX, positionY);
					marioSpriteR.setPosition(positionX, positionY);
					window.draw(marioSpriteL);
					SearchVectorForPlatforms(window, 0, 0,0);
					window.display();
					Sleep(10);

				}
			} while (1);
		}
		//left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{	//josh, ?
			isLeft = 1;
			sf::Vector2f  position = marioSpriteL.getPosition();
			int temp1 = position.x ;
			int temp2 = position.y;
			character.movesLeftInEndZoneToo(SCREENHEIGHT, SCREENWIDTH,window,goingDown,  temp1,  temp2, vectorPlatforms,  marioSpriteL, marioSpriteR, character, isLeft, positionY, positionX);
			//character.movesLeft(SCREENHEIGHT, SCREENWIDTH, window, goingDown, temp1, temp2, vectorPlatforms, marioSpriteL, marioSpriteR,  character, isLeft, positionY, positionX);
			//marioSpriteL.setPosition(temp1, temp2);
			//marioSpriteR.setPosition(temp1, temp2);


		}
		//righta
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			isLeft = 0;
			sf::Vector2f  position = marioSpriteL.getPosition();
			int temp1 = position.x;
			int temp2 = position.y;
			//character.movesRight(SCREENHEIGHT, SCREENWIDTH, window, goingDown, temp1, temp2, vectorPlatforms, marioSpriteL, marioSpriteR, character, isLeft, positionY);
			character.movesRightInEndZoneToo( SCREENHEIGHT,  SCREENWIDTH, window, goingDown, temp1, temp2,  vectorPlatforms, marioSpriteL, marioSpriteR, character, isLeft, positionY, positionX);
			
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

//loop through platforms and move them horizontally
void SearchVectorForPlatforms(sf::RenderWindow & inWindow, float changeX, float changeY, int isLeft1)
{
	
	
	for (std::vector<platform>::iterator it = vectorPlatforms.begin(); it != vectorPlatforms.end(); ++it)
	{
		//sprite is platform
		gottenSprite = it->getSprite();
		
		//character faces left
		if (isLeft1 == 1)
		{
			it->x = it->x + changeX;

			gottenSprite->setPosition((it->x), it->y);
		}

		if (isLeft1 == 0)
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
//moves character up and down  and moves platforms too (left and right)
//int virtualJump(Character & character, std::vector<platform> &vector, float &positionX, float &positionY, float& velocityY, float & velocityX,
//	float & gravity, int & isLeft, sf::RenderWindow & window, sf::Sprite & marioSpriteR, sf::Sprite& marioSpriteL, int & goingDown, int& characterOnBar)
//{
//	goingDown = 0;
//
//	
//	do {
//
//	
//	if (isLeft == 1)
//	{
//		velocityX = -2.0f;
//	}
//	else
//	{
//		velocityX = 2.0f;
//	}
//	int firstPositionX = positionX;
//	int firstPositionY = positionY;
//	positionY += velocityY;
//	positionX += velocityX;
//	velocityY += gravity;
//	int secondPositionY = positionY;
//	int secondPositionX = positionX;
//	//if positive going down
//	int horizontalChange = secondPositionX - firstPositionX;
//	
//	//change all platforms horizontal amount difference
//	for (std::vector<platform>::iterator it = vector.begin(); it != vector.end(); ++it)
//	{
//		if (isLeft == 1)
//		{
//			it->x = it->x + 4;// -horizontalChange;
//		}
//		else
//		{
//			it->x = it->x - 4;
//			//it->x = it->x - 1;// horizontalChange;
//		}
//	}
//
//	
//	if (firstPositionY <= secondPositionY)
//	{
//		goingDown = 1;
//	}
//	
//
//	if (isLeft == 1)
//	{
//		
//		
//		
//		if (positionY > (600 - 76))
//		{	
//			
//			positionY = (600 - 76);
//			marioSpriteL.setPosition(positionX, 600 - 76);
//			marioSpriteR.setPosition(positionX, 600 - 76);
//
//			velocityY = -30.0f;
//			velocityX = 2.0f;
//			//positionX = (800-76/2); 
//			break;
//		}
//		
//
//		
//		sf::Vector2f  position = marioSpriteL.getPosition();
//		int temp1 = position.x;
//		//josh -5
//		int temp2 = position.y;
//		//marioSpriteL.setPosition(, temp2);
//		//marioSpriteR.setPosition(temp1, temp2);
//
//
//
//		
//		int answer1 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);
//
//		//not on platform
//		if (answer1 == 0)
//		{
//			//moves mario up and down
//			marioSpriteL.setPosition(positionX, positionY);
//			marioSpriteR.setPosition(positionX, positionY);
//			window.clear();
//			window.draw(marioSpriteR);
//
//		}
//		else
//		{	//standing on platform
//			window.clear();
//			marioSpriteL.setPosition(temp1, temp2);
//			marioSpriteL.setPosition(temp1, temp2);
//			window.draw(marioSpriteR);
//			positionY = (temp2 );
//			velocityY = -30.0f;
//			velocityX = 2.0f;
//			positionX = 800 - 76 / 2;
//			break;
//			
//		}
//
//
//
//		SearchVectorForPlatforms(window, 4, 0, 1);
//		window.display();
//		Sleep(40);
//	}
//	
//	////////////////////////////right
//	else
//	{
//
//		
//		if (positionY > (600 - 76 ))
//		{
//			positionY = (600 - 76);
//			marioSpriteL.setPosition((800 / 2) - (76 / 2), 600 - 76);
//			marioSpriteR.setPosition((800 / 2) - (76 / 2), 600 - 76);
//
//			velocityY = -30.0f;
//			velocityX = 2.0f;
//			positionX = 800 - 76/2;
//			break;
//		}
//		
//
//
//		/////////////
//		sf::Vector2f  position = marioSpriteL.getPosition();
//		int temp1 = position.x;
//		int temp2 = position.y ;
//
//
//		//returns platform x and platform y
//		int answer1 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, 800, temp1, temp2, goingDown, positionY, positionX);
//		if (answer1 == 0)
//		{
//			//character jumps
//			marioSpriteL.setPosition((SCREENWIDTH / 2) - (76 / 2), positionY);
//			marioSpriteR.setPosition((SCREENWIDTH / 2) - (76 / 2), positionY);
//			window.clear();
//			window.draw(marioSpriteL);
//		}
//		//changes jump landing
//		else
//		{	//character stands
//			window.clear();
//			marioSpriteL.setPosition(temp1, positionY);
//			marioSpriteR.setPosition(temp1, positionY);
//			window.draw(marioSpriteL);
//			positionY = (temp2);
//			velocityY = -30.0f;
//			velocityX = 2.0f;
//			positionX = (temp1);
//			break;
//			
//		}
//		SearchVectorForPlatforms(window, 4, 0, 0);
//		window.display();
//		Sleep(20);
//		
//	}
//	
//} while (1);
//return(1);
//
//}

//void resetJumpingVariables(/*float &velocityX,*/ float &velocityY, float gravity = 0.5f, float & positionX = SCREENWIDTH/2 - 76/2, float & positionY = 600 - 76, int isLeft = 1)
//{
//	positionX = ((SCREENWIDTH / 2) - (76 / 2));
//	positionY = (SCREENHEIGHT - 76);
//	float velocityY = -15.0f;
//	
//	if (isLeft == 1)
//	{
//		//josh, check these
//		velocityX = 4.0f;
//	}
//	else
//	{
//		velocityY = -2.0f;
//	}
//	gravity = 0.5f;
//	
//}

////////////