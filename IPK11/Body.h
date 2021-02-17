#pragma once

#include "Point.h"
#include "array"

using std::array;

class Body{
    public:
    Point centerPos;
    Point velocity;
    double mass;
    array<int, 3> color;
};