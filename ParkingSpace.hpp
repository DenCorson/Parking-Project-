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

    ParkingSpace( int number, bool spaceEmpty = true ) // 
    {
       spaceNumber = number;
       isSpaceEmpty = spaceEmpty;
    
    }

    int getSpaceNumber() // returns spaceNumber
    {
       return spaceNumber;
    }   

    bool getIsSpaceEmpty()  // Returns status of space if empty
    {
        return isSpaceEmpty;
    }

    void setSpaceNumber(int number) // sets space number
    {
       spaceNumber = number;
    }

    void setSpacetoEmpty() // sets space status to empty
    {
       isSpaceEmpty = true;
    }
 
    void setSpacetoFull() // sets space to full
    {
      isSpaceEmpty = false;
    }

    void display() override // displays Parking space number and it its status, also helps Composite uniformity with ParkingLot.hpp
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

    //string getName() const override 
    //{
   //     return "Parking Space #" + (spaceNumber);
   // }
     

};

#endif
