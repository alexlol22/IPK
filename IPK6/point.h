#pragma once

class Point{
    public:
        Point();
        Point(double x, double y);
    private:
        double X;
        double Y;
    
    public:
        double x() const {return X;}
        double y() const {return Y;}
};