#include "point.h"
#include "iostream"
#include "canvas.h"
#include "iterationResult.h"
#include <string.h>
#include <math.h>

double distance(Point a, Point b){
    return sqrt( pow(a.x()-b.x(), 2) + pow(a.y()-b.y(), 2));
}

IterationResult iterate(Point z, Point c, double threshold, int maxIt){
    IterationResult result;
    Point newPoint(c);
    int iterCount = 0;
    double x=0,y=0;
    while (distance(z,newPoint) < threshold && iterCount < maxIt){
        x=newPoint.x();
        y=newPoint.y();
        newPoint = Point(pow(x,2)-pow(y,2)+c.x(), 2*x*y+c.y());    
        iterCount++;
    }
    result.setPoint(newPoint);
    result.setIterCount(iterCount);
    return result;
}

IterationResult iterate_julia(Point z, Point c, double threshold, int maxIt){
    IterationResult result;
    Point newPoint(z);
    int iterCount = 0;
    double x=0,y=0;
    while (distance(z,newPoint) < threshold && iterCount < maxIt){
        x=newPoint.x();
        y=newPoint.y();
        newPoint = Point(pow(x,2)-pow(y,2)+c.x(), 2*x*y+c.y());    
        iterCount++;
    }
    result.setPoint(newPoint);
    result.setIterCount(iterCount);
    return result;
}

void mandelbrot(Canvas& canvas, double threshold, int maxIt, const std::string fileName){
    IterationResult ir;
    for (int x=0; x<canvas.horPixels(); x++){
        for (int y=0; y<canvas.vertPixels(); y++){
            auto p = canvas.coord(x, y);
            ir = iterate(Point(-1,0), Point(p.x(),p.y()), threshold, maxIt);
            double b = ir.getIterCount()==maxIt ? 0 : log(ir.getIterCount())*100;
            canvas(x, y) = b;
        }
    }
    canvas.write(fileName);
}

void julia(const Point c, Canvas& canvas, double threshold, int maxIt, std::string fileName){
    IterationResult ir;
    for (int x=0; x<canvas.horPixels(); x++){
        for (int y=0; y<canvas.vertPixels(); y++){
            auto p = canvas.coord(x, y);
            ir = iterate_julia(Point(p.x(),p.y()), c, threshold, maxIt);
            double b = ir.getIterCount()==maxIt ? 0 : log(ir.getIterCount())*100;
            canvas(x, y) = b;
        }
    }
    canvas.write(fileName);
}

int main(){
    auto c1 = Canvas(Point(0,0), 4,3, 4000, 3000);
    auto juliaPoint = Point(-0.8, 0.156);
    auto c2 = Canvas(Point(0, 0), 4,3, 4000, 3000);
    mandelbrot(c1, 10, 50, "mdb.pgm");
    julia(juliaPoint, c2, 10, 50, "julia.pgm");
}