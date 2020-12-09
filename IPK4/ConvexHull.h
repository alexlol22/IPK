#include "vector"
#include "array"
#include "string"
#include "fstream"
#include "iostream"
#include "math.h"


using namespace std;

class ConvexHull{
    private:
    double getCounterClockwiseAngle(array<double, 2> a, array<double, 2> b);
    double getDistance(array<double, 2> a, array<double, 2> b);
    array<double, 2> normalize(array<double, 2> a);
    array<double, 2> getNextCounterClockwisePoint(array<double, 2> start, array<double, 2> direction);

    public:
    ConvexHull(string filename);
    void writePointsToFile(vector<array<double, 2>>points, string filename);
    array<double, 2> getLowestPoint();
    vector<array<double, 2>> points;
    vector<array<double, 2>> convex_hull();
    vector<array<double, 2>> read_points_from_file(string filename);
};