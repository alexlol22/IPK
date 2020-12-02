#pragma once

#include "iostream"
#include "stdlib.h"
#include "vector"
#include "math.h"

using namespace std;

class ZeroPointCalculator{
public:
    void ObtainValues();
    bool CalculateZeroPoints(vector<float>& results);
    void PrintResultsToConsole();

private:
    float a;
    float b;
    float c;

    void GetInputValidated(float& inputField, const string dialogue);
};