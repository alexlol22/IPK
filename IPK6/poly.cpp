#include "polygon.h"
#include "point.h"
#include <iostream>
#include <math.h>

int main(){
    auto pi = M_PI;
    double x, y, expected;
    vector<Point> Points = {};
    for (int n=1;n<11; n++){
        for (int i=0; i<=n; i++){
            x = cos((double(i)/n)*2*pi);
            y = sin((double(i)/n)*2*pi);
            Points.push_back(Point(x, y));
        }
        expected = n*sin(2*pi/n)/2;
        auto p = Polygon(Points);
        Points.clear();
        cout << "n=" <<n << " " << p.volume() << " Expected: " << expected << endl;
    }
    Points={{0,1}, {1,0}, {1,10}, {10,1}};
    auto p2 = Polygon(Points);
    cout << "Self-Intersecting:" << p2.volume() << endl;
}
