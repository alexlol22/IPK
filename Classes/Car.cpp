#include "Car.h"

Car::Car(uint8_t wheelCount, string manufacturerName, EChassis chassisType){
    this->wheelCount = wheelCount;
    this->manufacturerName = manufacturerName;
    this->chassisType = chassisType;
}

void Car::Drive(float distanceMeters){
    cout << "Vroom (" << chassisType << " " << manufacturerName << " travelled " << (int)distanceMeters 
    << "m on " << unsigned(this->wheelCount) << " wheels)" << endl;
}