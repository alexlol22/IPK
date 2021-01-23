#include "point.h"
#include <iostream>

using namespace std;

int main(){
    Point<double, 2> p;
    p[0] = 1;
    p[1] = 1;
    /*
    p.x(2) = 4.6;
    */
    cout << p[0] << endl;
    cout << p.norm() << endl;
}