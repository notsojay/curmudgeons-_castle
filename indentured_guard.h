#ifndef INDENTURED_GUARD_H
#define INDENTURED_GUARD_H

#include <cstdlib>

#include "person.h"
#include "position.h"
#include "guard.h"

// should inherit from guard 
class IndenturedGuard : public Guard
{
public:
    /** IndenturedGuard constructor. Calls Guard constructor with type 'I'
     * @parameter pos is the initial position.*/
    IndenturedGuard(const Position&);

    /** Moves the guard. This function overrrides in the Guard's pure virtual function
     *  has a 15% chance of moving this guard in a random direction.
     * @parameter move determines the  position to move to. Should be a pure virtual function, 
     *            Defaults to 'A' for auto
     */
    virtual void move(const char move = 'A'); 
    
    /** Destructor */
    ~IndenturedGuard();
    
protected:

private:
    /* Indentured guard has a 15% chance of moving */
    bool shouldIndenturedGuardMove();
    int randRange(const unsigned int &start, const unsigned int &end);
};

#endif