#pragma once
#include <vector>
#include "platforms.h"
#include "class1.h"

class class1
{
public:
	class1();
	void SearchVectorForPlatforms(std::vector<platform> vectorPlatforms, sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1);

};
