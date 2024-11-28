#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "ParkingAbstract.hpp"
#include "ParkingSpace.hpp"
#include <vector>
#include <iostream>
using namespace std;

class ParkingLot : public Parking{

std:: vector<ParkingSpace> space;
string lotName;

public:

ParkingLot(const string& name)
{
    lotName = name;
}

void addSpace(ParkingSpace& xspace)
{
    space.push_back(xspace);
}

vector<ParkingSpace>& getSpaces()
{
    return space;
}

vector<ParkingSpace>& getOccupiedSpaces()
{
    vector<ParkingSpace> occupied;
    for (int i = 0; i < space.size(); i++)
    {
        if (!space[i].getIsSpaceEmpty())
        {
            occupied.push_back(space[i]);
        }
    }
    return occupied;
}
  
    void display() override 
    {
        cout << "Displaying parking lot: " << lotName << endl;
        for (int i = 0; i < space.size(); i++) 
        {
            space[i].display();
        }
    }

    int countEmptySpaces()
    {
        int emptySpots = 0;
        for (int i = 0; i < space.size(); i++)
            {
                if(space[i].getIsSpaceEmpty())
                {
                    emptySpots++;
                }
            }
            return emptySpots;
    }

    int countFullSpaces()
    {
        int occupiedSpots = 0;
        for(int i = 0; i <space.size(); i++)
        {
            if(space[i].getIsSpaceEmpty())
            {
                occupiedSpots++;
            }
        }
        return occupiedSpots;
    }

    bool reserveSpace(int spaceNumber) 
    {
        for (int i =0; i < space.size(); i++)
        {
            if (space[i].getSpaceNumber() == spaceNumber && space[i].getIsSpaceEmpty())
            {
                space[i].setSpacetoFull();
                cout << "Space #" << spaceNumber << " has been reserved." << endl;
                return true;
            }
        }
    }

    bool clearSpace(int spaceNumber)
    {
         for (int i =0; i < space.size(); i++)
        {
            if (space[i].getSpaceNumber() == spaceNumber && !space[i].getIsSpaceEmpty())
            {
                space[i].setSpacetoEmpty();
                cout << "Space #" << spaceNumber << " is now free." << endl;
                return false;
            }
        }
    }

    string getName() const override 
    {
        return lotName;
    }


};

#endif