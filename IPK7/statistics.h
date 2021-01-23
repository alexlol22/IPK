#pragma once
#include "algorithm"
#include "math.h"
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
double mean(const T& v){
    typedef typename T::value_type value_type;
    if (v.size()==0)
        throw new exception();
    value_type x;
    for (size_t i=0; i<v.size(); i++)
        x+=v[i];
    return (float)x/v.size();
};

template <typename T>
double median(const T& v){
    typedef typename T::value_type value_type;
    vector<value_type> A(std::begin(v), std::end(v));
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
            return (float)(A[size / 2 - 1] + A[size / 2]) / 2;
        }
        else
        {
            return A[size / 2];
        }
    }
}

template <typename T>
double robust_median(const T& v){
    return median<T>(v); // eesy cheesy
}

template <typename T>
double moment(const T& v, int k){
    if (v.size()==0)
        throw new exception();
    double x;
    for (size_t i=0; i<v.size(); i++)
        x+=pow(v[i], k);
    return (float)x/v.size();
}
