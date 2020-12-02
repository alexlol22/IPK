#include <vector>
#include <iostream>
#include "cmath"

using namespace std;
vector<double> v1;
vector<double> v2(10);
vector<double> v3 = {{ 3, 8, 7, 5, 9, 2 }};
vector<double> v4 = {{ 0.3, 0.8, -0.7, 0 }};
/*Hi Ivan! Ich fände es sehr sinnvoll, wichtige Schlagworte (z.B. initializer lists) bereits
in den Übungensblättern zu benennen. Dann können Leute viel einfacher danach googlen und wissen direkt, wie
das Konstrukt heißt.
*/

void printContents(vector<double> &vec){
    cout << "Contents of vector situated at " << &vec << "\n\t";
    for (uint i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}

pair<double, double> findMinMax(vector<double> vec){
    double minVal;
    double maxVal;
    if(vec.size()>0){
        minVal = vec[0];
        maxVal = vec[0];
    }

    for (uint i = 0; i < vec.size(); i++)
    {
        minVal=min(vec[i], minVal);
        maxVal=max(vec[i], maxVal);
    }
    return pair<double, double>(minVal, maxVal);
}

vector<double> * reversed(const vector<double>& vec){
    auto * reverseVec = new vector<double>();
    for (int i = vec.size()-1; i>=0; i--)
    {
        reverseVec->push_back(vec[i]);
    }
    return reverseVec;
}

void reverseInPlace(vector<double>& vec){
    int swapcount = vec.size()/2;
    for (int i = 0; i<swapcount; i++)
    {
        swap(vec[i], vec[vec.size() -1 -i]);
    }
}

void roundInPlace(vector<double>& vec){
    for (uint i = 0; i < vec.size(); i++)
    {
        vec[i]=round(vec[i]);
    }
}

int main(){
    printContents(v1);
    printContents(v2);
    printContents(v3);
    auto x = findMinMax(v1);
    cout << "min: " << x.first << " max: " << x.second << endl;
    auto rv1 = reversed(v1);
    printContents(*rv1);
    auto rv2 = reversed(v2);
    printContents(*rv2);
    auto rv3 = reversed(v3);
    printContents(*rv3);
    reverseInPlace(v3);
    printContents(v3);
    roundInPlace(v4);
    printContents(v4);
}