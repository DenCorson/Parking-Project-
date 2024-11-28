#ifndef PARKINGABSTRACT_H
#define PARKINGABSTRACT_H
#include <iostream>
#include <string>
using namespace std;

class Parking
{
 public: 
    virtual ~Parking(){}
    virtual void display() = 0;
    virtual string getName() const = 0;  

};

#endif