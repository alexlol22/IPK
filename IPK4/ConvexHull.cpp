#include "ConvexHull.h"

ConvexHull::ConvexHull(string filename){
    points = read_points_from_file(filename);
    convex_hull();
}

double ConvexHull::getDistance(array<double, 2> a, array<double, 2> b){
    return sqrt(pow(a[0]-b[0], 2) + pow(a[1]-b[1], 2));
}

array<double, 2> ConvexHull::getLowestPoint(){
    auto closestToZero = points[0];
    for (long unsigned int i=0; i<points.size(); i++){
        if (points[i][1] < closestToZero[1]){
            closestToZero = points[i];
        }
    }
    return closestToZero;
}

void ConvexHull::writePointsToFile(vector<array<double, 2>>points, string filename){
    ofstream fo;
    fo.open(filename);
    if (!fo.is_open()){
        cout << "Couln't open file for reading.";
    }
    for (unsigned long int i=0; i<points.size(); i++)
    {
        fo << points[i][0] << " " << points[i][1] << "\n";
    }
}

array<double, 2> ConvexHull::normalize(array<double, 2> a){
    auto len = sqrt(pow(a[0], 2) + pow(a[1], 2));
    return {a[0]/len, a[1]/len};
}

double ConvexHull::getCounterClockwiseAngle(array<double, 2> a, array<double, 2> b){
    auto v1 = normalize(a);
    auto v2 = normalize(b);
    float dotProd = v1[0]*v2[0]+v1[1]*v2[1];
    float det = v1[0]*v2[1]-v1[1]*v2[0];
    float result = atan2(det, dotProd) * 180 / M_PI;
    return result < 0 ? 360-result*-1 : result;
}

array<double, 2> ConvexHull::getNextCounterClockwisePoint(array<double, 2> start, array<double, 2> direction){
    double ang = 361;
    double tmpAng;
    array<double, 2> testPoint;
    array<double, 2> bestPoint;
    array<double, 2> testVector;
    for (long unsigned int i=0; i<points.size(); i++){
        testPoint = points[i];
        testVector =  {testPoint[0]-start[0], testPoint[1]-start[1]};
        if (testVector[0] == 0 && testVector[1] == 0) continue;
        tmpAng = getCounterClockwiseAngle(direction, testVector);
        if (tmpAng < ang){
            ang = tmpAng;
            bestPoint = points[i];
        }
    }
    return bestPoint;
}

vector<array<double, 2>> ConvexHull::convex_hull(){
    vector<array<double, 2>> convexPoints={};
    auto startCoord = getLowestPoint();
    array<double, 2> previous = {0,0};
    auto current = startCoord;
    array<double, 2> rotation = {previous[0]-current[0], previous[1]-current[1]}; 

    for (unsigned long int i=0; i<points.size(); i++){
        auto tmp = getNextCounterClockwisePoint(current, rotation);
        if (tmp == startCoord) break;
        convexPoints.push_back({tmp[0], tmp[1]});
        previous = current;
        current = tmp;
        rotation = {current[0]-previous[0],current[1]-previous[1]};
    }
    return convexPoints;
}

vector<array<double, 2>> ConvexHull::read_points_from_file(string filename){
    auto parsedPoints = vector<array<double,2>>();
    ifstream fin;
    double a, b;
    fin.open(filename);
    if (!fin.is_open()){
        cout << "Couln't open file for reading.";
    }
    while (fin >> a >> b)
    {
        parsedPoints.push_back({a, b});
    }
    return parsedPoints;
}

