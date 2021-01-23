#include <iostream>
#include <vector>

using namespace std;

int fib_forschleife ( unsigned int n ){ // n ist eine nichtnegative ganze Zahl
    int a = 0; int b = 1; unsigned int i = 0;
    for ( i = 0; i < n ; i = i+1 ){
        int t = a+b ; a = b ; b = t ;
    }
    return a ;
}

bool B(vector<int> v){
    return (v[2] < v[3]);
}

vector<int> H(vector<int> v){
    int t=v[0] + v[1];
    return vector<int>({v[1], t, ++v[2], v[3], t});  
}

int fib_whileschleife ( unsigned int n ){ // n ist eine nichtnegative ganze Zahl
    vector<int>v = vector<int>({0,1,0,(int)n,0});
    while (B(v)){ v=H(v);}
    return v[0];
}

int main(){
    cout << fib_forschleife(1) << endl;
    cout << fib_whileschleife(1) << endl;
}
