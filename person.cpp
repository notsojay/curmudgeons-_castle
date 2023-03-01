#include "person.h"

Person::Person(const Position& pos, const char &type):pos(new Position(pos)), type(type)
{
	
}

Position Person::getPosition() const
{
	return *pos;
}

char Person::getType() const
{
	return type;
}

/** Equality operator
* @parameter other the other person object
* @return true if this object has the same position as the other and false otherwise */
bool Person::operator==(const Person& other) const
{
	if(this->pos->y == other.pos->y && this->pos->x == other.pos->x)
		return true;
	return false;
}

/** Inequality operator
* @parameter other the other person object
* @return false if this object has the same position as the other and true otherwise */
bool Person::operator!=(const Person& other) const
{
	if(this->pos->y != other.pos->y && this->pos->x != other.pos->x)
		return true;
	return false;
}

/* The moving position cannot be less than 0 or greater than 7 */
bool Person::isValidPosition(const char &move) const
{
	int tempY = static_cast<int>(this->pos->y);
	int tempX = static_cast<int>(this->pos->x);
	switch (move) 
	{
		case 'N':
			if((tempY - static_cast<int>(STEP)) < static_cast<int>(MIN_POSITION))
				return false;
			break;
		case 'S':
			if((tempY + static_cast<int>(STEP)) > static_cast<int>(MAX_POSITION))
				return false;
			break;
		case 'W':
			if((tempX - static_cast<int>(STEP)) < static_cast<int>(MIN_POSITION))
				return false;
			break;
		case 'E':
			if((tempX + static_cast<int>(STEP)) > static_cast<int>(MAX_POSITION))
				return false;
			break;
	}
	return true;
}

/** Virtual Destructor */
Person::~Person()
{
	if(pos != nullptr)
	{
		delete pos;
		pos = nullptr;
	}
}