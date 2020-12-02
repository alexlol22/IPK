#include "CarFactory.h"

Car CarFactory::ConstructCar(ECarType carType){
    switch (carType)
    {
        case ECarType::Basta:
            return Car(3, "Basta", EChassis::Spacious);
            
        case ECarType::Ferrero:
            return Car(4, "Ferrero", EChassis::Ugly);

        case ECarType::Orsche:
            return Car(1, "Orsche", EChassis::Sporty);

        case ECarType::Puma:
            return Car(6, "Puma", EChassis::Sporty);

        default:
            return Car(0, "Default", EChassis::Ugly);
    }
}