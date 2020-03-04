#include "platforms.h"


platform::platform(sf::Sprite * sprite, float x, float y)
{
	platformSprite = sprite;
	this->x = x;
	this->y = y;
}
sf::Sprite * platform::getSprite()
{
	return(platformSprite);
}

