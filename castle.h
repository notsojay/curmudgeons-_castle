#ifndef CASTLE_H
#define CASTLE_H
// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

#include "position.h"
#include "innocent.h"
#include "guard.h"
#include "indentured_guard.h"
#include "roving_guard.h"
#include "hunter_guard.h"

const size_t totalOfIndenturedGuards = 5;
const size_t totalOfRovingGuards = 4;
const size_t totalOfHunterGuards = 2;
const size_t totalOfGuards = totalOfIndenturedGuards + totalOfHunterGuards + totalOfRovingGuards;
enum MoveDirection{NORTH = 0, SOUTH, WEST, EAST};
enum Status{SURVIVE = 0, DEATH, CARRYING, VICTORY};

// this class does not provide UI no does it contain main. 
class Castle
{
public:

    /** castle constructor. Initializes the castle */ 
    Castle();

    /** move the position of the hero
     @ parameter move the direction in which the hero must move: must be a valid move
     @ throws invalid_argument exception if move is invalid */ 
    void move(const char&);

    /** stream insertion operator overload */
    friend std::ostream & operator<<(std::ostream & out, const Castle &castleObj);

    /* Used to return the current hero's status */
    Status judgeHeroStatus();
    
    /** Castle destructor. Deletes all heap based objects (including guards) */
    ~Castle();

private:
    std::vector<Guard*> guards;
    Innocent *hero;
    Innocent *wife;
    bool isTogether; // Used to judge that the hero has found and carried his wife
    
private:
    void initializeIndenturedGuards();
    void initializeRovingGuards();
    void initializeHunterGuards();
    void initializeHero();
    void initializeWife();
    void moveIndenturedGuards();
    void moveRovingGuards();
    void moveHunterGuards();
    size_t randRange(const unsigned int &start, const unsigned int &end);
};

#endif