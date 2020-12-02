#pragma once

#include <inttypes.h>
#include <string>
#include <iostream>

using namespace std;

enum EChassis{
    Sporty,
    Ugly,
    Spacious
};

enum ECarType{
    Orsche,
    Puma,
    Basta,
    Ferrero
};

class Car{
    
    public:
        Car(uint8_t wheelCount=2, string manufacturerName="Wonda", EChassis chassisType=EChassis::Ugly);
        //~Car();

        void Drive(float distanceMeters);

        uint8_t wheelCount;
        string manufacturerName;
        EChassis chassisType;
};