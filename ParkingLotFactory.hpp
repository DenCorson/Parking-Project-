#ifndef PARKINGLOTFACTORY
#define PARKINGLOTFACTORY
#include <iostream>
#include "LotFactory.hpp"

using namespace std;

class ParkingLotFactory{
    public: 
    ParkingLot* createLot(const string& name, bool emptyStatus)  
    {
        return new GenericParkingLot();
    }
};
#endif
