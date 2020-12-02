#include "iostream"
#include "pow.h"

using namespace std;

int power::iterative(int p, int n){
    unsigned long long result = 1;
    for(int i=0; i<n; i++){
        result*=p;
    }
    return result;
}

double power::iterative(double p, int n){
    double result = 1;
    for(int i=0; i<n; i++){
        result*=p;
    }
    return result;
}

int power::recursive(int p, int n){
    if(n==0) return 1;
    return p * recursive(p, n-1);
}

int power::recursiveOptimized(int p, int n){
    if(n==0) return 1;
    if(n%2==0){
        int tmp = recursive(p, n/2);
        return tmp*tmp;

    } else{
        return p * recursive(p, n-1);
    }
}

int main(){
    int p, n;
    cout << "p= ";
    cin >> p;
    cout << "n= ";
    cin >> n;
    if(p < 0 || n < 0) cout << "Erroneous input. Only use positive numbers";
    cout << "Iterative : " << power::iterative(p,n) << endl;
    cout << "Recursive : " << power::recursive(p,n) << endl;
    cout << "RecursiveOptimized: " << power::recursiveOptimized(p,n) << endl;
    return 0;
}