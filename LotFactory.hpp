#ifndef LOTFACTORY_H
#define LOTFACTORY_H
#include <iostream>
#include "ParkingAbstract.hpp"

using namespace std;

class LotFactory
{
public:
 virtual ParkingLot* createLot(const string& name, bool emptyStatus) = 0;
 virtual ~LotFactory() {};
};

#endif
