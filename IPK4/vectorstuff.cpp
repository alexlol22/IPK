#include "vecs.h"
using namespace vecstuff;

void BasicVectorOps::printContents(){
    cout << "Printing empty vector: " << endl;
    this->printContentsSingle(this->emptyBoi);
    cout << "Printing short vector: " << endl;
    this->printContentsSingle(this->smolBoi);
    cout << "Printing reversible vector: " << endl;
    this->printContentsSingle(this->reverseBoi);
    cout << "Printing fraction vector: " << endl;
    this->printContentsSingle(this->fractionBoi);
}

void BasicVectorOps::printContentsSingle(vector<double> &vec){
    cout << "Contents of vector situated at " << &vec << "\n\t";
    for (uint i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}

pair<double, double> BasicVectorOps::findMinMax(vector<double> vec){
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

vector<double> * BasicVectorOps::reversed(const vector<double>& vec){
    auto * reverseVec = new vector<double>();
    for (int i = vec.size()-1; i>=0; i--)
    {
        reverseVec->push_back(vec[i]);
    }
    return reverseVec;
}

void BasicVectorOps::reverseInPlace(vector<double>& vec){
    int swapcount = vec.size()/2;
    for (int i = 0; i<swapcount; i++)
    {
        swap(vec[i], vec[vec.size() -1 -i]);
    }
}

void BasicVectorOps::roundInPlace(vector<double>& vec){
    for (uint i = 0; i < vec.size(); i++)
    {
        vec[i]=round(vec[i]);
    }
}
