#include "point.h"

class IterationResult{
    private:
        Point lastIterPoint;
        int iterCount;
    
    public:
        Point getPoint(){return lastIterPoint;}
        void setPoint(const Point p){lastIterPoint = p;}
        int getIterCount(){return iterCount;}
        void setIterCount(int i){iterCount = i;}
};