#include "Nullstellen.h"

void ZeroPointCalculator::GetInputValidated(float& inputField, const string dialogue){
    string usrstr;
    while (true){
        cout << dialogue;
        cin >> usrstr;
        try
        {
            //you can cheese stof by using semi-parsable input like '0.B', which then gets converted to 0...
            //a better solution would be welcome - as long as its fast and lightweight
            inputField = stof(usrstr);
            return;
        }
        catch(const exception& e)
        {
            cout << "Cannot convert input to float.\n";
        }
    }
}  

void ZeroPointCalculator::ObtainValues(){
    GetInputValidated(a, "Enter value of a: ");
    GetInputValidated(b, "Enter value of b: ");
    GetInputValidated(c, "Enter value of c: ");
}

bool ZeroPointCalculator::CalculateZeroPoints(vector<float>& results){
    float underRoot = b*b - 4*a*c;
    if (a == 0 || underRoot < 0) return false;
    float x1 = (-b - sqrt(underRoot))/(2*a);
    float x2 = (-b + sqrt(underRoot))/(2*a);
    results.push_back(x1);
    results.push_back(x2);
    return true;
}

void ZeroPointCalculator::PrintResultsToConsole(){
    string outstr;
    vector<float> values;
    bool bIsComputable = CalculateZeroPoints(values);
    if (bIsComputable)
    {
        outstr = "Results for x1 & x2 are: ";
        for (long unsigned int i=0; i<values.size(); i++){
            outstr += (to_string(values[i]) + " ");
        }
    }
    else{
        outstr = "Cannot compute results - either a is zero or the result would be complex.";
    }
    cout << outstr << std::endl;
}
