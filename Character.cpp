#include "Character.h"
#include "class1.h"

Character::Character()
{

}
//falling
int Character::isOnPlatform(std::vector<platform>& vector, int screenWidth, int& characterX, int& characterY, int& goingDown, int& characterOnBar, float& positionY, int& platformX, int &platformY)
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
			//characterX = it->x;
			characterY = it->y - 76;
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

int Character::movesLeft(class1 classA, sf::RenderWindow &window, int& goingDown, int & characterLeft, int & characterRight, int SCREENWIDTH, std::vector<platform> vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, int& characterOnBar, float positionY)
{
	sf::Vector2f  position = marioSpriteL.getPosition();
	int temp1 = position.x;
	int temp2 = position.y;

	//isLeft = 0;
	int notNeeded1, notNeeded2 = 0;
	int answer = character.isOnPlatform(vector, SCREENWIDTH,characterLeft,characterRight,goingDown, characterOnBar,positionY,notNeeded1, notNeeded2);
	//on platform
	if (answer == 1)
	{
		temp1 = temp1 + 4;
		//move platforms
		classA.SearchVectorForPlatforms(vector,window, 4.0f, 0.0f, 0);
		
		//moved off
		if (answer != character.isOnPlatform(vector, SCREENWIDTH, characterLeft, characterRight, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2))
		{
			//drop
			while (1)
			{
				temp2 = temp2 + 4.0f;
				//drops
				marioSpriteR.setPosition(temp1, temp2);
				marioSpriteL.setPosition(temp1, temp2);
				int answer3 = character.isOnPlatform(vector, SCREENWIDTH, characterLeft, characterRight, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
				//is on platform
				if (answer3)
				{
					characterOnBar = 1;
					break;
				}
			}
				


			
		}

		else
		{
			//on platform	
			if (isLeft)
			{
				classA.SearchVectorForPlatforms(vector, window, 4.0f, 0.0f, 0);
			}
			else
			{
				classA.SearchVectorForPlatforms(vector, window, -4.0f, 0.0f, 0);
			}

		}


	}
	//characetr not on plat form
	else
	{
		if (isLeft == 1)
		{
			classA.SearchVectorForPlatforms(vector,window, 4.0f, 0.0f, 0);
		}
		else
		{
			classA.SearchVectorForPlatforms(vector, window, -4.0f, 0.0f, 0);
		}


	}

		int answer2 = character.isOnPlatform(vector, SCREENWIDTH, characterLeft, characterRight, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);
		//not on platform anymore
		if (answer2 == 0)
		{
			//drop
			while (1)
			{
				temp2 = temp2 - 4.0f;
				//drops
				marioSpriteR.setPosition(temp1, temp2);
				marioSpriteL.setPosition(temp1, temp2);
				int answer = character.isOnPlatform(vector, SCREENWIDTH, characterLeft, characterRight, goingDown, characterOnBar, positionY, notNeeded1, notNeeded2);

				if (answer == 1)
				{
					break;
				}
			}
		}
		return(1);

}
	