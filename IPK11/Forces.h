#include "Body.h"
#include <vector>
#include <iostream>
#include <math.h>

using std::vector;

//why template this??
struct Force{
    public:
    virtual Point operator()(const vector<Body>& bodies, int i, double dt) const{
        return {0,0};
    }
};

struct ForceGravity : public Force{
    public:
    const double G = 0.01;
    Point operator()(const vector<Body>& bodies, int i, double dt) const override{
        Point force;
        Body x = bodies[i];
        Body y;
        for (int j=0; j<bodies.size(); j++){
            if (j == i){
                continue;
            }
            y = bodies[j];
            force += G*y.mass*pow(y.centerPos.distance(x.centerPos), -3)*(y.centerPos-x.centerPos);
        }
        return force;
    }
};
