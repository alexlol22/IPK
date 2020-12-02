#include "iostream"
#include "pow.h"

using namespace std;

double root_iterative(double q, int n, int steps){
    double a = 1;
    for (int i = 0; i<steps; i++){
        a = (a + (1.0/n) * (q / power::iterative(a,n-1) - a));        
    }
    return a;
}

void test_root(double q, int n, int steps){
    double result = root_iterative(q, n, steps);
    cout << q << " to the power of 1/" << n << " is: " << result  << " after " << steps << " steps." << endl;
    double variance = abs(q - power::iterative(result, n));
    cout << "Variance: " << variance << endl;
}

int main(){
    double q;
    int n;
    int s;
    cout << "Number to take to the power of 1/n: (d) ";
    cin >> q;
    cout << "n: (i) ";
    cin >> n;
    cout << "Iterations: (i) ";
    cin >> s;
    if(q < 0 || n < 0 || s < 0) cout << "Erroneous input. Only use positive numbers";
    test_root(q, n, s);
    return 0;
}