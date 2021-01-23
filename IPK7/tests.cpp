#include "point.h"
#include <cassert>

int main(){
    Point<double, 1> p1d;
    static_assert(p1d.dimension == 1);
    assert(p1d.norm() == 0);
    p1d[0] = .2;
    assert(p1d.norm() == .2);

    Point<float, 3> p3f;
    static_assert(p3f.dimension == 3);
    assert(p3f.norm() == 0);
    p3f[0] = 2;
    p3f[1] = 3;
    p3f[2] = 6;
    assert(p3f.norm() == 7);
}
