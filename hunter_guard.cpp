#include "hunter_guard.h"

HunterGuard::HunterGuard(const Position &pos, const Innocent *const hero):Guard(pos, 'H'), hero(hero)
{
	
}

void HunterGuard::move(const char move)
{
	/* Use the hero's x, y value to subtract the hunter guard's x, y value to get the distance between two people. */
	size_t xDistance = abs(static_cast<int>(this->pos->x) - static_cast<int>(hero->getPosition().x));
	size_t yDistance = abs(static_cast<int>(this->pos->y) - static_cast<int>(hero->getPosition().y));
	
	/* If the distance x is smaller than the distance y, 
	** then it is proved that the distance between the hunter guard and the hero in the horizontal direction is shorter than the vertical distance, 
	** and then hunter guard will move horizontally. */
	if(xDistance > yDistance)
	{
		moveHorizontally();
	}
	else if(yDistance > xDistance)
	{
		moveVertically();
	}
	else 
	{
		/* If the distance between the x-axis and the y-axis are equal, 
		** the hunter guard will randomly choose to move horizontally or vertically */
		switch (randRange(0, 1)) 
		{
			case 0:
				moveHorizontally();
				break;
			case 1:
				moveVertically();
				break;
		}
	}
}

void HunterGuard::moveHorizontally()
{
	if(this->pos->x > hero->getPosition().x)
	{
		if(isValidPosition('W'))
		{
			this->pos->x -= STEP;
		}
	}
	else if(this->pos->x < hero->getPosition().x)
	{
		if(isValidPosition('E'))
		{
			this->pos->x += STEP;
		}
	}
}

void HunterGuard::moveVertically()
{
	if(this->pos->y > hero->getPosition().y)
	{
		if(isValidPosition('N'))
		{
			this->pos->y -= STEP;
		}
	}
	else if(this->pos->y < hero->getPosition().y)
	{
		if(isValidPosition('S'))
		{
			this->pos->y += STEP;
		}
	}
}

int HunterGuard::randRange(const unsigned int &start, const unsigned int &end)
{
	int scalingFactor = end - start + 1;
	return rand() % scalingFactor + start;
}

HunterGuard::~HunterGuard()
{
	if(hero != nullptr)
	{
		hero = nullptr;
	}
}