#ifndef PERSON_H 
#define PERSON_H

#include "position.h"

// The base class of Guards and Innocents and is abstract
class Person
{
public:
    
    /** Person object. the base class for guards and Innocents
     * @parameter pos. the initial position
     * @parameter type. the type of person
     */
    Person(const Position&, const char&);
    
    /** Gets the current position of the Person
     * @return position. */
    Position getPosition() const;

    /** Gets the type of the person [I, R, H, Y, W]
     * @return the type of the Person
     */
    char getType() const; 

    /** Equality operator
     * @parameter other the other person object
     * @return true if this object has the same position as the other and false otherwise */
    bool operator==(const Person&) const;

    /** Inequality operator
     * @parameter other the other person object
     * @return false if this object has the same position as the other and true otherwise */
    bool operator!=(const Person&) const;

    /** Moves the Person from the current position to pos. This is a pure virtual function
     * @parameter move determines the direction to move. The default value is 'A' for auto  */
    virtual void move(char move = 'A') = 0; 

    /** Virtual Destructor */
    virtual ~Person();
    
protected:
    Position *pos;
    char type;

protected:
    /* The moving position cannot be less than 0 or greater than 7 */
    bool isValidPosition(const char&) const;

private:
    
};

#endif