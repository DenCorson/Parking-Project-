#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "ParkingAbstract.hpp"
#include "ParkingSpace.hpp"
#include <vector>
#include <iostream>
using namespace std;

class ParkingLot : public Parking{ 

std:: vector<ParkingSpace> space; // vector of lots will contain objects of spaces from ParkingSpace class
string lotName; // name of the lot(section)

public:

ParkingLot(const string& name)
{
    lotName = name; // name assigned to lotname variable
}

void addSpace(ParkingSpace& xspace)
{
    space.push_back(xspace);  // add space takes in space object into parameter and pushes onto space vector
}

vector<ParkingSpace>& getSpaces() // retrieves spaces in vector
{
    return space;
}

vector<ParkingSpace>& getOccupiedSpaces()  // returns spaces which are occupied in vector
{
    vector<ParkingSpace> occupied; // local vector "occupied" created to hold tracked occupied spaces
    for (int i = 0; i < space.size(); i++) // iterators for space vector
    {
        if (!space[i].getIsSpaceEmpty()) // if condition uses getIsSpaceEmpty function to verify that its NOT empty
        {
            occupied.push_back(space[i]); // if grabs occupied spaes and pushes it onto the occupied vector to later be displayed back to user
        }
    }
    return occupied; // returns the object of occupied spaces in the space vector
}
  
    void display() override  // diplay information regarding the parking lot
    {
        cout << "Displaying parking lot: " << lotName << endl; //       
        for (int i = 0; i < space.size(); i++)  // iterates through "lot" vector and displays information on each lot 
        {
            space[i].display();
        }
    }

    int countEmptySpaces() // counts  the number emptypaces in the lot
    {
        int emptySpace = 0;
        for (int i = 0; i < space.size(); i++)
            {
                if(space[i].getIsSpaceEmpty())
                {
                    emptySpace++;
                }
            }
            return emptySpace;
    }

    int countFullSpaces() // counts  the number of full spaces in the lot
    {
        int occupiedSpaces = 0;
        for(int i = 0; i <space.size(); i++)
        {
            if(space[i].getIsSpaceEmpty())
            {
                occupiedSpaces++;
            }
        }
        return occupiedSpaces;
    }

    bool reserveSpace(int spaceNumber)  // reserves space, with the space number
    {
        for (int i =0; i < space.size(); i++)  // iterates through lot vector of spaces
        {
            if (space[i].getSpaceNumber() == spaceNumber && space[i].getIsSpaceEmpty()) //condition checks if the entered space number is empty if so, reserve by setting space to occupied
             {
                space[i].setSpacetoFull();
                cout << "Space #" << spaceNumber << " has been reserved." << endl;
                return true;
            }
        }
    }

    bool clearSpace(int spaceNumber) //clears the reserve spot with number in spot
    {
         for (int i =0; i < space.size(); i++) //iterates through lot vector of spaces
        {
            if (space[i].getSpaceNumber() == spaceNumber && !space[i].getIsSpaceEmpty()) // condition checks if the entered space number is not empty, if true set space to empty
            {
                space[i].setSpacetoEmpty();
                cout << "Space #" << spaceNumber << " is now free." << endl;
                return false;
            }
        }
    }

    //string getName() const override 
   // {
     //   return lotName;
    //}


};

#endif
