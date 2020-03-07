#include "Character.h"


Character::Character()
{

}
//falling
int Character::isOnPlatform(int SCEENHEIGHT,int  goingDown, std::vector<platform>& vector, int screenWidth, int& characterX, int& characterY, int& isGoingDown, int& characterOnBar, float& positionY, int& platformX, int& platformY)
{
	

	//int holder = 0;
	//finds a platform to land on
	for (std::vector<platform>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		//assumption x and y change by an amount of one
		//could check y for platforms moving up down
		if (((it->x > -76) && (it->x < screenWidth )) &&
			((characterX + 76 >= it->x) && (characterX  <= (it->x+ 150 ))) &&
			//(characterY >= (it->y - 76)) && (characterY <= (it->y - 76 + 11))
			((characterY + 76 <= (it->y+20)) && (characterY + 76>= (it->y   )))
			&& (goingDown == 1)  )
		{
			//josh, check this
			//characterY = it->y - 76;
			characterOnBar = 1;

			//positionY = (it->y - 72);
			
			platformX = it->x;
			platformY = it->y;
			//is on a bar
			return(1);
		}
	}
	//not on bar
	//positionY = (holder - 72);
	return(0);
}


////////////

int Character::movesRight(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, int& characterOnBar, float& positionY)
{
	sf::Vector2f  position = marioSpriteR.getPosition();
	int temp1 = position.x;
	int temp2 = position.y;

	//isLeft = 0;
	int notNeeded1, notNeeded2 = 0;
	int answer = character.isOnPlatform(SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
	//on platform
	if (answer == 1)
	{

		//move platforms
		platform::SearchVectorForPlatforms(vector, window, 2.0f, 0.0f, 0);
		//is still on platform?
		answer = character.isOnPlatform(SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
		//was on, moved off
		if (answer == 0)
		{
			//drop - off platform
			while (1)
			{
				temp2 = temp2 + 4.0f;
				positionY = positionY + 4;
				//drops
				marioSpriteR.setPosition(temp1, temp2);
				marioSpriteL.setPosition(temp1, temp2);
				window.draw(marioSpriteR);

				int answer3 = character.isOnPlatform(SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
				//lands on platform
				if (answer3)
				{ //, josh what if not totally  on platform right, here?
					break;
				}//is on ground here, yes?
				else if (temp2 >= (SCREENHEIGHT - 76))
				{
					int yValue = (temp2);
					marioSpriteL.setPosition(temp1, yValue);
					marioSpriteR.setPosition(temp1, yValue);
					positionY = 600- 76;
					break;
				}
			}




		}
		//still on platform after move
		else
		{
			window.draw(marioSpriteL);
		}

	}
	else
	{
		// was never on platform
		platform::SearchVectorForPlatforms(vector, window, 2.0f, 0.0f, 0);

	}

	return(1);
}
int Character::movesLeft(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& temp1, int& temp2, std::vector<platform> &vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, int& characterOnBar, float & positionY)
{
	//sf::Vector2f  position = marioSpriteL.getPosition();
	//int temp1 = position.x;
	//int temp2 = position.y;

	//isLeft = 0;
	int notNeeded1, notNeeded2 = 0;
	int answer = character.isOnPlatform(SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
	//on platform
	if (answer == 1)
	{
		
		//move platforms
		platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
		//is still on platform?
		answer = character.isOnPlatform(SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
		//was on, moved off
		if(answer == 0)
		{
			//drop - off platform
			while (1)
			{
				temp2 = temp2 + 4.0f;
				positionY = positionY + 4;
				//drops
				marioSpriteR.setPosition(temp1, temp2);
				marioSpriteL.setPosition(temp1, temp2);
				//window.draw(marioSpriteL);
				//window.display();
				int answer3 = character.isOnPlatform(SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
				//lands on platform
				if (answer3)
				{ //, josh what if not totally  on platform right, here?
					break;
				}//is on ground here, yes?
				else if (temp2 >= (SCREENHEIGHT - 76))
				{
					int yValue = (temp2 );
					marioSpriteL.setPosition(temp1, yValue );
					marioSpriteR.setPosition(temp1, yValue );
					positionY = 600 - 76 ;
					break;
				}
			}

			window.draw(marioSpriteL);


		}
		//still on platform after move
		else
		{
			window.draw(marioSpriteL);
		}

	} 
	else
	{
		// was never on platform
		platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);

	}
		
	return(1);
}

	//int answer2 = isOnPlatform(goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
	//not on platform anymore
	//if (answer2 == 0)
	//{
	//	//drop
	//	while (1)
	//	{
	//		temp2 = temp2 - 4.0f;
	//		//drops
	//		marioSpriteR.setPosition(temp1, temp2);
	//		marioSpriteL.setPosition(temp1, temp2);
	//		int answer = isOnPlatform(goingDown , vector, SCREENWIDTH, characterLeft, characterY, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);

	//		if (answer == 1)
	//		{
	//			break;
	//		}
	//	}
	//}//is not on platfom
	//return(1);

//}
