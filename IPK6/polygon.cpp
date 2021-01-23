#include "polygon.h"

Polygon::Polygon(const std::vector<double>& x, const std::vector<double>& y){
    for (size_t i=0; i<x.size(); i++){
        Points.push_back(Point(x[i], y[i]));
    }
}

size_t Polygon::corners(){
    return Points.size();
}

const Point& Polygon::corner(std::size_t i) const{
    return Points[i];
}

double Polygon::volume(){
    if (Points.size() < 3)
        return 0;
    double sum = 0;
    size_t c = corners();
    for (size_t i=0; i<c; i++){
        sum += Points[i].x()*Points[(i+1)%c].y()-Points[(i+1)%c].x()*Points[i].y();
    }
    return sum/2;
}