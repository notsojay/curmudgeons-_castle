#ifndef ROVING_GUARD_H
#define ROVING_GUARD_H

#include "person.h"
#include "position.h"
#include "guard.h"

// should inherit from Guard
class RovingGuard : public Guard
{
public:

    /** RovingGuard constructor. Calls Guard constructor with type 'R'
     * @parameter pos is the initial position.*/
    RovingGuard(const Position& pos);

    /** Moves the guard. This function overrides in the Guard's pure virtual function
     *  moves this guard in a random direction.
     * @parameter move determines the  position to move to. Should be a pure virtual function, 
     *            Defaults to 'A' for auto */
    virtual void move(const char move = 'A');

    /** Destructor */
    ~RovingGuard();
    
protected:

private:
};

#endif