#include "indentured_guard.h"

IndenturedGuard::IndenturedGuard(const Position &pos):Guard(pos, 'I')
{
	
}

void IndenturedGuard::move(const char move)
{
	if(shouldIndenturedGuardMove())
	{
		switch(move)
		{
			case 'N':
				if(isValidPosition('N'))
				{
					this->pos->y -= STEP;
					break;
				}
			case 'S':
				if(isValidPosition('S'))
				{
					this->pos->y += STEP;
					break;
				}
			case 'W':
				if(isValidPosition('W'))
				{
					this->pos->x -= STEP;
					break;
				}
			case 'E':
				if(isValidPosition('E'))
				{
					this->pos->x += STEP;
					break;
				}
			default:
				break;
		}
	}
}

/* Indentured guard has a 15% chance of moving */
bool IndenturedGuard::shouldIndenturedGuardMove()
{
	bool shouldMove = ((randRange(1, 100)) <= 15);
	return shouldMove;
}

int IndenturedGuard::randRange(const unsigned int &start, const unsigned int &end)
{
	int scalingFactor = end - start + 1;
	return rand() % scalingFactor + start;
}

IndenturedGuard::~IndenturedGuard()
{
	
}