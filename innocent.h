#ifndef INNOCENT_H
#define INNOCENT_H

#include <stdexcept>

#include "person.h"
#include "position.h"

// should inherit from Person
class Innocent : public Person
{
public:
    /** Innocent constructor. Calls person constructor  
     * @parameter pos is the initial position. 
     * @parameter type is the type of person. */
    Innocent(const Position&, const char&);

    /** Moves the Innocent based on the pos argument. 
     *  This function overrrides in the Guard's pure virtual function
     * @parameter move determines the updated position to move to. Moves: [N, S, E, W, P, C]
     * throws invalid_argument exception if pos is an invalid move */
    virtual void move(const char move); 

    /** Destructor */
    ~Innocent();
    //using Person::pos;
    
protected:

private:
};

#endif