#include "Character.h"

Character::Character()
{

}
//falling
int Character::isOnPlatform(sf::RenderWindow &window, sf::Sprite & marioSpriteR, sf::Sprite & marioSpriteL, int SCEENHEIGHT,int  goingDown, std::vector<platform>& vector, int screenWidth, int& characterX, int& characterY, int& isGoingDown, float &positionY)
{
	

	//int holder = 0;
	//finds a platform to land on
	for (std::vector<platform>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		//((characterY + 76 <= (it->y + 20)) && (characterY + 76 >= (it->y)))

		//assumption x and y change by an amount of one
		//could check y for platforms moving up down
		if (((it->x > -76) && (it->x < screenWidth )) &&
			((characterX + 76 >= it->x) && (characterX  <= (it->x+ 150 ))) &&
			//(characterY >= (it->y - 96)) && (characterY <= (it->y - 76 + 11))
			//josh,this isn't exactly right!
			((characterY + 76 <= (it->y+35)) && (characterY + 76>= (it->y-15   )))
			&& (goingDown == 1)  )
		{
			
			//characterOnBar = 1;
			
			//positiony
			//this causes changes when a or s pressed
			marioSpriteL.setPosition((800 / 2) - (76 / 2), it->y - 76 );
			marioSpriteR.setPosition((800 / 2) - (76 / 2), it->y - 76);
			
			positionY = (it->y - 76);
			
			return(1);
		}
	}
	//not on bar
	//positionY = (holder - 72);
	return(0);
}


////////////

int Character::movesRight( const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY)
{
	sf::Vector2f  position = marioSpriteR.getPosition();
	int temp1 = position.x;
	int temp2 = position.y;

	//isLeft = 0;
	int notNeeded1, notNeeded2 = 0;
	int answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown,  positionY);
	//on platform
	if (answer == 1)
	{

		//move platforms
		platform::SearchVectorForPlatforms(vector, window, 2.0f, 0.0f, 0);
		//is still on platform?
		answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, positionY);
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

				int answer3 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, positionY);
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
int Character::movesLeft(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& temp1, int& temp2, std::vector<platform> &vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float & positionY)
{
	//sf::Vector2f  position = marioSpriteL.getPosition();
	//int temp1 = position.x;
	//int temp2 = position.y;

	//isLeft = 0;
	int notNeeded1, notNeeded2 = 0;
	int answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL,SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY);
	//on platform
	if (answer == 1)
	{
		
		//move platforms
		platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
		//is still on platform?
		answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY);
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
				int answer3 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY);
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
