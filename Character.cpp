#include "Character.h"



Character::Character()
{
	rightEndzoneLine = (600);
	leftEndzoneLine = 400 - (76/2);
	currentCharacterPlacement = 400 - (76/2);
}
//falling
int Character::isOnPlatform(sf::RenderWindow& window, sf::Sprite& marioSpriteR, sf::Sprite& marioSpriteL, int SCEENHEIGHT, int  goingDown, std::vector<platform>& vector, int screenWidth, int& characterX, int& characterY, int& isGoingDown, float& positionY, float & positionX)
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
			marioSpriteL.setPosition(positionX, it->y - 76 );
			marioSpriteR.setPosition(positionX, it->y - 76);
			
			positionY = (it->y - 76);
			
			return(1);
		}
	}
	//not on bar
	//positionY = (holder - 72);
	return(0);
}

////////////

int Character::movesLeftInEndZoneToo(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& temp1, int& temp2, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY, float & positionX)
{
	//sf::Vector2f  position = marioSpriteL.getPosition();
	//int temp1 = position.x;
	//int temp2 = position.y;

	//isLeft = 0;
	int notNeeded1, notNeeded2 = 0;
	int answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);
	//on platform
	if (answer == 1)
	{

		//move platforms
		platform::SearchVectorForPlatforms(vector, window, 2.0f, 0.0f, 0);
		currentCharacterPlacement = currentCharacterPlacement - 2.0;
		//is still on platform?
		answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);
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
				//window.draw(marioSpriteL);
				//window.display();
				int answer3 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);
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
					positionY = 600 - 76;
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
		if (currentCharacterPlacement < (SCREENWIDTH / 2 - (76/2)))
		{
			//platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
			
			if (positionX - 2.0f < (0))
			{

				marioSpriteL.setPosition(0, positionY);
				marioSpriteR.setPosition(0, positionY);
				positionX = 0;
				currentCharacterPlacement = 0;
				
				
			}
			else
			{
				currentCharacterPlacement = currentCharacterPlacement -2;
				positionX = positionX - 2;
				marioSpriteL.setPosition(positionX, (SCREENHEIGHT)-(76));
				marioSpriteR.setPosition(positionX, (SCREENHEIGHT)-(76));
				platform::SearchVectorForPlatforms(vector, window, 0.0f, 0.0f, 0);

				window.draw(marioSpriteR);
			}
			
		}
		//left line - moving left on right hans side of line
		else
		{


			currentCharacterPlacement = currentCharacterPlacement - 2;
			//positionX = positionX - 2;
			marioSpriteL.setPosition(SCREENWIDTH/2 - 76/2, (SCREENHEIGHT)-(76));
			marioSpriteR.setPosition(SCREENWIDTH / 2 - 76 / 2, (SCREENHEIGHT)-(76));
			platform::SearchVectorForPlatforms(vector, window, 2.0f, 0.0f, 0);
			window.draw(marioSpriteR);
		}


		//left of borderline moving left



	}

	return(1);
}

//////////
////////////

int Character::movesRightInEndZoneToo(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY, float & positionX)
{
	sf::Vector2f  position = marioSpriteR.getPosition();
	int temp1 = position.x;
	int temp2 = position.y;

	//isLeft = 0;
	int notNeeded1, notNeeded2 = 0;
	int answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, positionY, positionX);
	//on platform
	if (answer == 1)
	{

		//move platforms
		platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
		currentCharacterPlacement = currentCharacterPlacement + 2.0;

		//is still on platform?
		answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, positionY, positionX);
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

				int answer3 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, positionY, positionX);
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
					positionY = 600 - 76;
					break;
				}
				/*else if (currentCharacterPlacement > rightEndzoneLine + SCREENWIDTH/2)
				{
					currentCharacterPlacement = rightEndzoneLine + SCREENWIDTH/2;
					positionX = rightEndzoneLine + SCREENWIDTH / 2;
					break;
				}*/
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
		//right
		// was never on platform
		/*
		if (currentCharacterPlacement >= (rightEndzoneLine + SCREENWIDTH / 2))
		{
			currentCharacterPlacement = rightEndzoneLine + SCREENWIDTH / 2;
			positionX = rightEndzoneLine + SCREENWIDTH / 2;
			return(1);

		}*/

		

		if (currentCharacterPlacement <= SCREENWIDTH / 2 - (76/2))
		{
			//platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
			currentCharacterPlacement = currentCharacterPlacement + 2;
			positionX = positionX + 2;
			isLeft = 0;
			
			
			marioSpriteL.setPosition(positionX, (SCREENHEIGHT)-(76));
			marioSpriteR.setPosition(positionX, (SCREENHEIGHT)-(76));
			window.clear();
			platform::SearchVectorForPlatforms(vector, window, 0, 0, 1);
			window.draw(marioSpriteR);
			//window.display();
		}
		else
		{
			// was never on platform - right of line -  right
		platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
		currentCharacterPlacement = currentCharacterPlacement + 2.0;
		//positionX = positionX + 2;
		window.clear();
		
		window.draw(marioSpriteR);
		}
		
		

	}

	return(1);
}
////////////

//
//int Character::movesRight( const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& characterLeft, int& characterY, std::vector<platform>& vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float& positionY, float & positionX)
//{
//	sf::Vector2f  position = marioSpriteR.getPosition();
//	int temp1 = position.x;
//	int temp2 = position.y;
//
//	//isLeft = 0;
//	int notNeeded1, notNeeded2 = 0;
//	int answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown,  positionY, positionX);
//	//on platform
//	if (answer == 1)
//	{
//
//		//move platforms
//		platform::SearchVectorForPlatforms(vector, window, 2.0f, 0.0f, 0);
//		currentCharacterPlacement = currentCharacterPlacement - 2.0;
//		//is still on platform?
//		answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, positionY, positionX);
//		//was on, moved off
//		if (answer == 0)
//		{
//			//drop - off platform
//			while (1)
//			{
//				temp2 = temp2 + 4.0f;
//				positionY = positionY + 4;
//				//drops
//				marioSpriteR.setPosition(temp1, temp2);
//				marioSpriteL.setPosition(temp1, temp2);
//				window.draw(marioSpriteR);
//
//				int answer3 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, characterLeft, characterY, goingDown, positionY, positionX);
//				//lands on platform
//				if (answer3)
//				{ //, josh what if not totally  on platform right, here?
//					break;
//				}//is on ground here, yes?
//				else if (temp2 >= (SCREENHEIGHT - 76))
//				{
//					int yValue = (temp2);
//					marioSpriteL.setPosition(temp1, yValue);
//					marioSpriteR.setPosition(temp1, yValue);
//					positionY = 600- 76;
//					break;
//				}
//			}
//
//
//
//
//		}
//		//still on platform after move
//		else
//		{
//			window.draw(marioSpriteL);
//		}
//
//	}
//	else
//	{
//		// was never on platform
//		platform::SearchVectorForPlatforms(vector, window, 2.0f, 0.0f, 0);
//		currentCharacterPlacement = currentCharacterPlacement - 2.0;
//	}
//
//	return(1);
//}




//
//
//int Character::movesLeft(const int SCREENHEIGHT, const int SCREENWIDTH, sf::RenderWindow& window, int& goingDown, int& temp1, int& temp2, std::vector<platform> &vector, sf::Sprite& marioSpriteL, sf::Sprite& marioSpriteR, Character& character, int& isLeft, float & positionY, float & positionX)
//{
//	//sf::Vector2f  position = marioSpriteL.getPosition();
//	//int temp1 = position.x;
//	//int temp2 = position.y;
//
//	//isLeft = 0;
//	int notNeeded1, notNeeded2 = 0;
//	int answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL,SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);
//	//on platform
//	if (answer == 1)
//	{
//		
//		//move platforms
//		platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
//		currentCharacterPlacement = currentCharacterPlacement + 2.0;
//		//is still on platform?
//		answer = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);
//		//was on, moved off
//		if(answer == 0)
//		{
//			//drop - off platform
//			while (1)
//			{
//				temp2 = temp2 + 4.0f;
//				positionY = positionY + 4;
//				//drops
//				marioSpriteR.setPosition(temp1, temp2);
//				marioSpriteL.setPosition(temp1, temp2);
//				//window.draw(marioSpriteL);
//				//window.display();
//				int answer3 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);
//				//lands on platform
//				if (answer3)
//				{ //, josh what if not totally  on platform right, here?
//					break;
//				}//is on ground here, yes?
//				else if (temp2 >= (SCREENHEIGHT - 76))
//				{
//					int yValue = (temp2 );
//					marioSpriteL.setPosition(temp1, yValue );
//					marioSpriteR.setPosition(temp1, yValue );
//					positionY = 600 - 76 ;
//					break;
//				}
//			}
//
//			window.draw(marioSpriteL);
//
//
//		}
//		//still on platform after move
//		else
//		{
//			window.draw(marioSpriteL);
//		}
//
//	} 
//	else
//	{
//		// was never on platform
//		platform::SearchVectorForPlatforms(vector, window, -2.0f, 0.0f, 0);
//		currentCharacterPlacement = currentCharacterPlacement + 2.0;
//
//	}
//		
//	return(1);
//}

///////





//moves character up and down  and moves platforms too (left and right)
int Character::JumpInEndZone(int & line, int SCREENWIDTH, int SCREENHEIGHT, Character & character, std::vector<platform> & vector, float& positionX, float& positionY, float& velocityY, float& velocityX,
		float& gravity, int& facingLeft, sf::RenderWindow & window, sf::Sprite & marioSpriteR, sf::Sprite & marioSpriteL, int& goingDown, int& characterOnBar)
{
		goingDown = 0;


		do {


			if (facingLeft == 1)
			{
				velocityX = -2.0f;
			}
			else
			{
				velocityX = 2.0f;
			}
			int firstPositionX = positionX;
			int firstPositionY = positionY;
			positionY += velocityY;
			positionX += velocityX;;
			velocityY += gravity;
			int secondPositionY = positionY;
			int secondPositionX = positionX;
			//if positive going down
			int horizontalChange = secondPositionX - firstPositionX;
			if (facingLeft == 1)
			{
				
				//currentCharacterPlacement = currentCharacterPlacement - 2;// horizontalChange;
				//already subtracted right above
				//positionX = positionX + horizontalChange;
			}
			else
			{
				//currentCharacterPlacement = currentCharacterPlacement + 2;// horizontalChange;
			}

			////////////////



			


			//change all platforms horizontal amount difference
			for (std::vector<platform>::iterator it = vector.begin(); it != vector.end(); ++it)
			{
				if (facingLeft == 1)
				{
					//jump is both sides
					if (currentCharacterPlacement + 2  > line && currentCharacterPlacement  <= line)
					{
						////move charactwer left
						//currentCharacterPlacement = currentCharacterPlacement - 1;
						//positionX = positionX - 1;
						//platform::SearchVectorForPlatforms(vector, window, -1, 0, 1);
						//currentCharacterPlacement = currentCharacterPlacement - 1;
						//positionX = positionX - 1;
						//marioSpriteL.setPosition(positionX, positionY);
						//marioSpriteR.setPosition(positionX, positionY);
						//window.draw(marioSpriteL);


					}//jump is entirely on rigth side of line and is facing left



					else if (currentCharacterPlacement  > line  )
					{
						/*marioSpriteL.setPosition(SCREENWIDTH / 2 - (76 / 2), positionY);
						marioSpriteR.setPosition(SCREENWIDTH / 2 - (76 / 2), positionY);
						window.clear();
						window.draw(marioSpriteR);

						platform::SearchVectorForPlatforms(vector, window, 2, 0, 1);
						currentCharacterPlacement = currentCharacterPlacement - 2;*/


					}
					else  //jump is entirely on left, facing left
					{
						

					}

				}
				//move platform when jumping right
				else
				{
					//mario on right side of line, jumping right
					//if (currentCharacterPlacement > leftEndzoneLine )
					//{
					//	marioSpriteL.setPosition(SCREENWIDTH/2 - (76/2), positionY);
					//	marioSpriteR.setPosition(SCREENWIDTH/2 - (76/2), positionY);
					//	window.clear();
					//	window.draw(marioSpriteR);
					//	
					//	platform::SearchVectorForPlatforms(vector, window, -2, 0, 1);
					//	//positionX = positionX + 2;
					//	currentCharacterPlacement = currentCharacterPlacement + 2;

					//}
					//else
					//{
					//	//no platform action
					//}
					
				}
			}
			///////////////////////////////

		

			if (firstPositionY <= secondPositionY)
			{
				goingDown = 1;
			}

			//josh****going right on right of line, seems to be working 
			if (positionY > (600 - 76))
			{

				positionY = (600 - 76);
				//josh, other end zone
				
				//right of line, 
				if (positionX >= line)
				{
					marioSpriteL.setPosition(SCREENWIDTH / 2 - 76 / 2, 600 - 76);
					marioSpriteR.setPosition(SCREENWIDTH / 2 - 76 / 2, 600 - 76);
					positionX = SCREENWIDTH / 2 - (76 / 2);
					platform::SearchVectorForPlatforms(vector, window, -2, 0, 1);
				}
				else
				{
					marioSpriteL.setPosition(positionX, 600 - 76);
					marioSpriteR.setPosition(positionX, 600 - 76);
					//positionX = SCREENWIDTH / 2 - (76 / 2);

				}

				velocityY = -30.0f;
				if (facingLeft == 1)
				{
					velocityX = -2.0f;
				}
				else
				{
					velocityX = 2.0f;
				}
				
				//positionX = (800 - 76 / 2);
				break;
			}


			if (facingLeft == 1)
			{

				

				



				sf::Vector2f  position = marioSpriteL.getPosition();
				int temp1 = position.x;
				//josh -5
				int temp2 = position.y;
				
				//gets mario position from last set
				int answer1 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, SCREENWIDTH, temp1, temp2, goingDown, positionY, positionX);

				//not on platform  - jump is left
				if (answer1 == 0)
				{

					

					//on right side of line - jumpimng left
					if(currentCharacterPlacement > SCREENWIDTH/2 - (76/2))
					{
						//right
						//moves mario up and down
						marioSpriteL.setPosition(SCREENWIDTH / 2 - (76 / 2), positionY);
						marioSpriteR.setPosition(SCREENWIDTH / 2 - (76 / 2), positionY);
						window.clear();
						window.draw(marioSpriteR);
						//josh
						positionX = SCREENWIDTH / 2 - (76 / 2);
						platform::SearchVectorForPlatforms(vector, window, 2, 0, 1);
						currentCharacterPlacement = currentCharacterPlacement - 2;
						
					}

					//on left side of line, jumping left
					else
					{
						if (facingLeft)
						{
							currentCharacterPlacement = currentCharacterPlacement - 2;
							positionX = positionX - 2;



							marioSpriteL.setPosition(positionX, positionY);
							marioSpriteR.setPosition(positionX, positionY);

							window.clear();
							platform::SearchVectorForPlatforms(vector, window, 0, 0, 1);
							window.draw(marioSpriteR);
						} 

					}


					//////////////////////////////////////////	
				}
				else////////////////////////////////// -  not yet - here:
				{	//standing on platform on right of line, on left of line
					window.clear();
					marioSpriteL.setPosition(temp1, temp2);
					marioSpriteL.setPosition(temp1, temp2);
					window.draw(marioSpriteR);
					positionY = (temp2);
					velocityY = -30.0f;
					velocityX = -2.0f;
					//positionX = 600 - 76 / 2;
					break;

				}

				////////////////////////////////////

			
				window.display();
				Sleep(40);
			}

			////////////////////////////jump in right hand direction
			else
			{


				if (positionY > (600 - 76))
				{
					positionY = (600 - 76);
					marioSpriteL.setPosition(positionX, 600 - 76);
					marioSpriteR.setPosition(positionX, 600 - 76);

					velocityY = -30.0f;
					velocityX = 2.0f;
					positionX = SCREENWIDTH / 2 - (76 / 2);
					break;
				}

				/////////////
				sf::Vector2f  position = marioSpriteL.getPosition();
				int temp1 = position.x;
				int temp2 = position.y;


				int answer1 = character.isOnPlatform(window, marioSpriteR, marioSpriteL, SCREENHEIGHT, goingDown, vector, 800, temp1, temp2, goingDown, positionY, positionX);
				
				//not on platform - jumping right
				if (answer1 == 0)
				{
					//jumping right, left of line
					if (currentCharacterPlacement < SCREENWIDTH / 2 - (76 / 2) )
					{
						currentCharacterPlacement = currentCharacterPlacement + 2;
						positionX = positionX + 2;
						

						marioSpriteL.setPosition(positionX, positionY);
						marioSpriteR.setPosition(positionX, positionY);
						window.clear();
						window.draw(marioSpriteL);
						platform::SearchVectorForPlatforms(vector, window, 0, 0, 1);
					}
					//facing right, right of (or on) line
					else
					{
						currentCharacterPlacement = currentCharacterPlacement + 2;
						

						marioSpriteL.setPosition(SCREENWIDTH/2 - (76/2), positionY);
						marioSpriteR.setPosition(SCREENWIDTH / 2 - (76 / 2), positionY);
						//positionX = SCREENWIDTH / 2 - (76 / 2);
						window.clear();
						window.draw(marioSpriteL);
						platform::SearchVectorForPlatforms(vector, window, -2, 0, 1);

					}

					
				}
				//changes jump landing
				else
				{	//character stands
					window.clear();
					marioSpriteL.setPosition(temp1, positionY);
					marioSpriteR.setPosition(temp1, positionY);
					window.draw(marioSpriteL);
					positionY = (temp2);
					velocityY = -30.0f;
					velocityX = 2.0f;
					positionX = (temp1);
					break;

				}
				//platform::SearchVectorForPlatforms(vector, window, 4, 0, 0);
				window.display();
				Sleep(30);

			}

		} while (1);
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
