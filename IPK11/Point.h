#pragma once

#include <iostream>
#include <math.h>

using std::ostream;

class Point{
    public:
    double x;
    double y;
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
    Point(){
        x = 0;
        y = 0;
    }
    Point operator+(const Point& p){
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point& p){
        return Point(x - p.x, y - p.y);
    }
    Point operator*(const double& d){
        return Point(x * d, y * d);
    }
    void operator+=(const Point& p){
        x += p.x;
        y += p.y;
    }
    void operator-=(const Point& p){
        x -= p.x;
        y -= p.y;
    }
    void operator*=(const double& d){
        x *= d;
        y *= d;
    }
    double distance(const Point& p){
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }
    friend ostream& operator<< (ostream &os, const Point &p)
    {
        os << "X:" << p.x << ", Y:" << p.y;
        return os;
    }
    friend Point operator* (double d, const Point& p)
    {
        return Point(d * p.x, d * p.y);
    }
};