#include "vecs.h"
#include "ConvexHull.h"
using namespace vecstuff;

int main(){
    
    auto * vecobj = new vecstuff::BasicVectorOps();
    vecobj->printContents();
    
    auto x = vecobj->findMinMax(vecobj->reverseBoi);
    cout << "min, max of reversible vector: " << x.first << ", " << x.second << endl;
    cout << "reversing out-of-place" << endl;
    auto rv3 = vecobj->reversed(vecobj->reverseBoi);
    vecobj->printContents();
    cout << "newly created vector:" << endl;
    vecobj->printContentsSingle(*rv3);
    cout << "reversing in place" << endl;
    vecobj->reverseInPlace(vecobj->reverseBoi);
    vecobj->printContents();
    cout << "round in place" << endl;
    vecobj->roundInPlace(vecobj->fractionBoi);
    vecobj->printContents();
    
    /*
    auto CH = ConvexHull("../inputPoints.txt");
    auto points = CH.convex_hull();
    CH.writePointsToFile(points, "../outputHull.txt");
    */
}