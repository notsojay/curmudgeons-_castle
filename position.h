#ifndef POSITION_H
#define POSITION_H

#include <stddef.h>

enum validPosition : size_t
{
    MIN_POSITION = 0,
    MAX_POSITION = 7
};
const size_t STEP = 1;

struct Position
{
    size_t y;
    size_t x;

    Position(const size_t &y, const size_t &x);
    Position(const Position &other);
};

#endif