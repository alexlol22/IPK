#pragma once

#include <vector>
#include "point.h"
#include "iostream"

using namespace std;

class Polygon{
    public:
        Polygon(const std::vector<Point>& corners): Points(corners){};
        Polygon(const std::vector<double>& x, const std::vector<double>& y);

    private:
        vector<Point> Points;

    public: 
        size_t corners();
        const Point& corner(std::size_t i) const;
        double volume();
};