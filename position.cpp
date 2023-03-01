#include "position.h"

Position::Position(const size_t &y, const size_t &x) : y(y), x(x) {}

Position::Position(const Position &other) : y(other.y), x(other.x) {}