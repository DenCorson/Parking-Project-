#ifndef PARKINGSPACE_H
#define PARKINGSPACE_H
#include <iostream>
#include "ParkingAbstract.hpp"
#include <vector>
using namespace std;

class ParkingSpace : public Parking{
 int spaceNumber;
 bool isSpaceEmpty;

public:

    ParkingSpace( int number, bool spaceEmpty = true )
    {
       spaceNumber = number;
       isSpaceEmpty = spaceEmpty;
    
    }

    int getSpaceNumber()
    {
       return spaceNumber;
    }   

    bool getIsSpaceEmpty() 
    {
        return isSpaceEmpty;
    }

    void setSpaceNumber(int number)
    {
       spaceNumber = number;
    }

    void setSpacetoEmpty()
    {
       isSpaceEmpty = true;
    }

    void setSpacetoFull()
    {
      isSpaceEmpty = false;
    }

    void display() override
    {
     cout << "Displaying Parking Space " << spaceNumber << endl;
        if (isSpaceEmpty)
            {
                cout << "This space is currently empty."  << endl;
            }
        else 
            {
            cout << "This space is currently occupied." << endl;
            }

     }

    string getName() const override 
    {
        return "Parking Space #" + (spaceNumber);
    }
     

};

#endif