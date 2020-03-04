#include "Character.h"


Character::Character()
{

}
//falling
int Character::isOnPlatform(std::vector<platform>& vector, int screenWidth, int& characterX, int& characterY, int& goingDown, int& characterOnBar, float& positionY, int& platformX, int &platformY)
{
	if (characterOnBar == 1)
	{
		//full jump that falls down
		//return(0);
	}

	int holder = 0;
	//finds a platform to land on
	for (std::vector<platform>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		//assumption x and y change by an amount of one
		//could check y for platforms moving up down
		if ((it->x > 76) && (it->x < screenWidth) &&
			((characterX + 76 >= it->x) && (characterX  <= (it->x+ 150-76 )) &&
			(characterY >= (it->y - 76 )) && (characterY <= (it->y - 76 + 11 ))
			&& (goingDown == 1)  ))
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