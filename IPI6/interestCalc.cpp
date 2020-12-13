#include "fcpp.hh"
#include "math.h"
#include "sstream"
#include "iomanip"
#include "limits"

using namespace std;

float zins(float z, int n){
    return pow(1+z/n, n)-1;
}

double zins(double z, int n){
    return pow(1+z/n, n)-1;
}

int main(){
    int nvalues[]={1,12,365, 365*24, 
                    365*24*60,
                    365*24*60*60};
    int nv;
    float f;
    double d;
    double p = exp(0.06)-1;
    ostringstream sst;
    sst << setprecision(std::numeric_limits<long double>::digits10 + 1);
    for(int i=0; i<6; i++){
        nv=nvalues[i];
        f=zins(.06f, nv);
        d=zins(.06, nv);
        sst << "n=" << nv << "\n\tf=" << f << " deviation=" << abs(p-f) << "\n\td=" << d << " deviation=" << abs(p-d) << endl;
    }
    print(sst.str());
}