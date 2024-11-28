#ifndef PARKINGLOTFACTORY
#define PARKINGLOTFACTORY

#include <iostream>
#include "ParkingLot.hpp"

class ParkingLotFactory { 
public:

     static ParkingLot createParkingLot(const string& name, int numSpaces)
        {
        ParkingLot lot(name);
        for (int i = 1; i <= numSpaces; i++) {
            ParkingSpace space(i, true); 
            lot.addSpace(space);
        }
        return lot;
    }
};

#endif
