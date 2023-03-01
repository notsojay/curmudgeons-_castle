#include "castle.h"

Castle::Castle():guards(totalOfGuards), isTogether(false)
{
	initializeHero();
	initializeWife();
	initializeIndenturedGuards();
	initializeRovingGuards();
	initializeHunterGuards();
}

void Castle::move(const char &move)
{
	switch(move)
	{
		case 'N':
			hero->move('N');
			if(isTogether) wife->move('N');
			break;
		
		case 'S':
			hero->move('S');
			if(isTogether) wife->move('S');
			break;
		
		case 'W':
			hero->move('W');
			if(isTogether) wife->move('W');
			break;
		
		case 'E':
			hero->move('E');
			if(isTogether) wife->move('E');
			break;
		
		case 'P':
			hero->move('P');
			if(isTogether) wife->move('P');
			break;
		
		case 'C':
			if(!isTogether && *this->hero == *this->wife)
				isTogether = true;
			hero->move('C');
			break;
	}
	moveIndenturedGuards();
	moveRovingGuards();
	moveHunterGuards();
}

std::ostream& operator<<(std::ostream &out, const Castle &castleObj)
{
	std::string str; // This is used to store the symbols of the guards and then fill it in the out object.
	
	out << std::setfill('-') << std::setw(33) << '-' << std::setfill(' ') << std::endl;
	
	/* Fill the out object with the symbols of the guards. */
	for(size_t i = 0; i < MAX_POSITION+1; i++)
	{
		for(size_t j = 0; j < MAX_POSITION+1; j++)
		{
			out << "|";
			for(size_t g = 0; g < totalOfGuards; g++)
			{
				if(castleObj.guards.at(g)->getPosition().y == i && castleObj.guards.at(g)->getPosition().x == j)
				{
					// Avoid overlapping symbols of two guards of the same type in the same room.
					if(str.rfind(castleObj.guards.at(g)->getType()) == str.npos)
					{
						str += castleObj.guards.at(g)->getType();
					}
				}
			}
			if(str.length() < 3)
			{
				for(size_t i = str.length(); i < 3; i++)
				{
					str += " ";
				}
			}
			out << str;
			str.clear();
		}
		out << "|" << std::endl;
		
		/* Fill the out object with the symbols of hero and wife. */
		for(size_t k = 0; k < MAX_POSITION+1; k++)
		{
			out << "|";
			if(castleObj.hero->getPosition().y == i && castleObj.hero->getPosition().x == k)
			{
				out << castleObj.hero->getType();
			}
			else 
			{
				out << " ";
			}
			if(castleObj.wife->getPosition().y == i && castleObj.wife->getPosition().x == k)
			{
				out << castleObj.wife->getType();
			}
			else
			{ 
				out << " ";
			}
			out << " ";
		}
		out << "|" << std::endl;
		out << std::setfill('-') << std::setw(33) << '-' << std::setfill(' ') << std::endl;
	}
	return out;
}


Status Castle::judgeHeroStatus()
{
	for(size_t i = 0; i < totalOfIndenturedGuards; i++)
	{
		if(*hero == *(guards.at(i))) 
			return DEATH;
	}
	for(size_t i = 0; i < totalOfRovingGuards; i++)
	{
		if(*hero == *(guards.at(i + totalOfIndenturedGuards))) 
			return DEATH;
	}
	for(size_t i = 0; i < totalOfHunterGuards; i++)
	{
		if((hero->getPosition().y == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().y-1 
			&& hero->getPosition().x == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().x)
			|| (hero->getPosition().y == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().y+1 
				&& hero->getPosition().x == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().x))
			return DEATH;
		
		else if((hero->getPosition().x == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().x-1 
			&& hero->getPosition().y == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().y)
			|| (hero->getPosition().x == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().x+1 
				&& hero->getPosition().y == guards.at(i + totalOfRovingGuards + totalOfIndenturedGuards)->getPosition().y))
				return DEATH;
			
		else if(*hero == *(guards.at(i + totalOfIndenturedGuards + totalOfRovingGuards)))
			return DEATH;
	}
	if(wife->getPosition().y == 0 && wife->getPosition().x == 0)
		return VICTORY;
	
	if(isTogether)
		return CARRYING;
	
	return SURVIVE;
}

void Castle::moveIndenturedGuards()
{
	for(size_t i = 0; i < totalOfIndenturedGuards; i++)
	{
		switch(randRange(NORTH, EAST)) 
		{
			case NORTH: 
				(guards.at(i))->move('N');
				break;
			case SOUTH:
				(guards.at(i))->move('S');
				break;
			case WEST:
				(guards.at(i))->move('W');
				break;
			case EAST:
				(guards.at(i))->move('E');
				break;
		}
	}
}

void Castle::moveRovingGuards()
{
	for(size_t i = 0; i < totalOfRovingGuards; i++)
	{
		switch(randRange(NORTH, EAST)) 
		{
			case NORTH: 
				(guards.at(i + totalOfIndenturedGuards))->move('N');
				break;
			case SOUTH:
				(guards.at(i + totalOfIndenturedGuards))->move('S');
				break;
			case WEST:
				(guards.at(i + totalOfIndenturedGuards))->move('W');
				break;
			case EAST:
				(guards.at(i + totalOfIndenturedGuards))->move('E');
				break;
		}
	}
}

void Castle::moveHunterGuards()
{
	for(size_t i = 0; i < totalOfHunterGuards; i++)
	{
		(guards.at(i + totalOfIndenturedGuards + totalOfRovingGuards))->move();
	}
}


void Castle::initializeIndenturedGuards()
{
	for(size_t i = 0; i < totalOfIndenturedGuards; i++)
	{
		Position pos(randRange(MIN_POSITION, MAX_POSITION),randRange(MIN_POSITION, MAX_POSITION));
		
		// This prevents the guard from being initialized at the starting position of the hero (0,0).
		if(pos.y == 0 && pos.x == 0)
		{
			i--;
			continue;
		}
		/* This is to avoid the guards being initialized around the hero (0, 1). */
		else if(pos.y == 0 && pos.x == 1)
		{
			i--;
			continue;
		}
		/* This is to avoid the guards being initialized around the hero (1, 0). */
		else if(pos.y == 1 && pos.x == 0)
		{
			i--;
			continue;
		}
		/* The index position of the vector starts from 0. */
		guards.at(i) = new IndenturedGuard(pos);
	}
}

void Castle::initializeRovingGuards()
{
	for(size_t i = 0; i < totalOfRovingGuards; i++)
	{
		Position pos(randRange(MIN_POSITION, MAX_POSITION),randRange(MIN_POSITION, MAX_POSITION));
		
		/* This prevents the guard from being initialized at the starting position of the hero (0,0). */
		if(pos.y == 0 && pos.x == 0)
		{
			i--;
			continue;
		}
		/* This is to avoid the guards being initialized around the hero (0, 1). */
		else if(pos.y == 0 && pos.x == 1)
		{
			i--;
			continue;
		}
		/* This is to avoid the guards being initialized around the hero (1, 0). */
		else if(pos.y == 1 && pos.x == 0)
		{
			i--;
			continue;
		}
		/* The index position of the vector starts from 5.
		** The first five elements are indentured guards. */
		guards.at(i + totalOfIndenturedGuards) = new RovingGuard(pos);
	}
}

void Castle::initializeHunterGuards()
{
	for(size_t i = 0; i < totalOfHunterGuards; i++)
	{
		Position pos(randRange(MIN_POSITION+4, MAX_POSITION),randRange(MIN_POSITION+4, MAX_POSITION));
		
		// This prevents the guard from being initialized at the starting position of the hero (0,0).
		if(pos.y == 0 && pos.x == 0)
		{
			i--;
			continue;
		}
		/* This is to avoid the guards being initialized around the hero (0, 1). */
		else if(pos.y == 0 && pos.x == 1)
		{
			i--;
			continue;
		}
		/* This is to avoid the guards being initialized around the hero (1, 0). */
		else if(pos.y == 1 && pos.x == 0)
		{
			i--;
			continue;
		}
		/* The index position of the vector starts from 9.
		** The first nine elements are indentured guards and roving guards. */
		guards.at(i + totalOfIndenturedGuards + totalOfRovingGuards) = new HunterGuard(pos, hero);
	}
}

void Castle::initializeHero()
{
	Position pos(0, 0);
	hero = new Innocent(pos, 'Y');
}

void Castle::initializeWife()
{
	Position pos(randRange(3, 4),randRange(3, 4));
	wife = new Innocent(pos, 'W');
}

size_t Castle::randRange(const unsigned int &start, const unsigned int &end)
{
	size_t scalingFactor = end - start + 1;
	return rand() % scalingFactor + start;
}

Castle::~Castle()
{
	if(hero != nullptr)
	{
		delete hero; 
		hero = nullptr;
	}
	if(wife != nullptr)
	{
		delete wife;
		wife = nullptr;
	}
	if(guards.capacity() != 0)
	{
		for(size_t i = 0; i < totalOfGuards; i++)
		{
			delete guards.at(i);
			guards.at(i) = nullptr;
		}
		guards.clear();
		std::vector<Guard*>().swap(guards);
	}
}