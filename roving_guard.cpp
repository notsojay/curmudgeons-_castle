#include "roving_guard.h"

RovingGuard::RovingGuard(const Position &pos):Guard(pos, 'R')
{
	
}

void RovingGuard::move(const char move)
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

RovingGuard::~RovingGuard()
{

}