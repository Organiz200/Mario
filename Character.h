#pragma once
#include <vector>
#include "platforms.h"
class Character
{
public:

	Character();
	int isOnPlatform(std::vector<platform>& vector, int screenWidth, int &characterX, int &characterY, int & isGoingDown, int &characterOnBar, float& positionY, int & platformX, int & platformY);


};

