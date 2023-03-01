#ifndef GUARD_H
#define GUARD_H

#include "person.h"
#include "position.h"


// should inherit from Person but be an abstract class
class Guard : public Person
{
public:
    
    /** Guard constructor. Calls person constructor  
     * @parameter pos is the initial position. 
     * @parameter type is the type of person. */
    Guard(const Position&, const char&);

    /** Moves the guard. This is a pure virtual function which is overrriden in the derived guards
     * @parameter move determines the  position to move to. Should be a pure virtual function, 
     *            Defaults to 'A' for auto */
    virtual void move(char move = 'A') = 0;
    
    /** Virtual Destructor */
    virtual ~Guard();

protected:

private:
};

#endif