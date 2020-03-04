//#include "class1.h"
#include <vector>
#include "platforms.h"
#include <SFML/Window.hpp>
#include "class1.h"
//class1::SearchVectorForPlatforms(std::vector<platform> vectorPlatforms, sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1)

//void classA::SearchVectorForPlatforms(std::vector<platform> & vectorPlatforms, sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1);

class1::class1()
{

}
//void class1::SearchVectorForPlatforms(std::vector<platform> vectorPlatforms, sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1);
//void class1::SearchVectorForPlatforms(int a, std::vector<platform> vectorPlatforms, sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1)
//{

//}
void class1::SearchVectorForPlatforms(std::vector<platform> vectorPlatforms, sf::RenderWindow& inWindow, float changeX, float changeY, int isLeft1)
{

	sf::Sprite* gottenSprite;
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
