#include "statistics.h"

double mean(const std::vector<double>& v){
    if (v.size()==0)
        throw new exception();
    double x;
    for (size_t i=0; i<v.size(); i++)
        x+=v[i];
    return x/v.size();
}

double median(const std::vector<double>& v){
    vector<double> A=v; //memcpy, not just a ref for vectors
    size_t size = A.size();

    if (size == 0)
    {
        return 0;
    }
    else
    {
        sort(A.begin(), A.end());
        if (size % 2 == 0)
        {
        return (A[size / 2 - 1] + A[size / 2]) / 2;
        }
        else 
        {
        return A[size / 2];
        }
    }
}

double moment(const std::vector<double>& v, int k){
    if (v.size()==0)
        throw new exception();
    double x;
    for (size_t i=0; i<v.size(); i++)
        x+=pow(v[i], k);
    return x/v.size();
}

double standard_deviation(const std::vector<double>& v){
    double meanval = mean(v);
    double sum;
    for (size_t i=0; i<v.size(); i++){
        sum+=pow(v[i]-meanval, 2);
    }
    return sqrt((1/v.size()-1)*sum);
}