#include "Car.h"

class CarFactory{
    public:
        static CarFactory& GetInstance(){
            static CarFactory Instance;
            return Instance;
        }
    private:
        CarFactory(){}
    
    public:
        CarFactory(CarFactory const&) = delete;
        void operator=(CarFactory const&)  = delete;

        Car ConstructCar(ECarType carType);
};