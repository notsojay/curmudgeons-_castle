#include "innocent.h"

Innocent::Innocent(const Position &pos, const char &type):Person(pos, type)
{
	
}

void Innocent::move(const char move)
{
	switch(move)
	{
		case 'N':
			if(isValidPosition('N'))
			{
				this->pos->y -= STEP;
				break;
			}
			throw std::out_of_range("That position is out of range!");
			
		case 'S':
			if(isValidPosition('S'))
			{
				this->pos->y += STEP;
				break;
			}
			throw std::out_of_range("That position is out of range!");
			
		case 'W':
			if(isValidPosition('W'))
			{
				this->pos->x -= STEP;
				break;
			}
			throw std::out_of_range("That position is out of range!");
			
		case 'E':
			if(isValidPosition('E'))
			{
				this->pos->x += STEP;
				break;
			}
			throw std::out_of_range("That position is out of range!");
			
		case 'P':
			break;
		
		case 'C':
			break;
		
		default:
			throw std::invalid_argument("The value you entered is invalid!");
	}
}

Innocent::~Innocent()
{
	
}