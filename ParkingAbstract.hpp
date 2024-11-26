#ifndef PARKINGABSTRACT_H
#define PARKINGABSTRACT_H
#include <iostream>
using namespace std;


class ParkingLot
{

 protected:
    string lotName;
    bool  lotEmpty;

 public: 

    ParkingLot(string name = "Blank Lot", bool emptyStatus = true)
     {
        lotName = name;
        lotEmpty = emptyStatus;

     }

    virtual ~ParkingLot(){}
    virtual void createLot() = 0;
    virtual void reserveLot(const string& uniqueID) = 0;
    virtual void notify() = 0; 

    void searchLot() 
     {
      cout << "Searching availibility of parking lot.." << endl; 
     }
          
    void slot(const string& uniqueID)
     {
        if (lotName == "Blank Lot")
        {
            cout << "Parking lot does not exist. Creating lot." << endl; 
            createLot();
        }
        else
        {
            cout << "Checking parking lot availability.. " << endl; 
        }
        
        if (lotEmpty)
        {
            reserveLot(uniqueID);
        }
        else
        {
            cout << "Parking lot: " << getLotName() << " not available. Please try another time." << endl;
        }
    }

    void clearLot()
        {
            if (lotEmpty)
            {
                cout << "Parking lot: " << getLotName() << " is already empty." << endl;
            }
            else
            {
                setEmptyStatusToEmpty();
                cout << "Parking lot: " << getLotName() << " is now empty." << endl;
            }
        }

    string getLotName()
    {
        return lotName;
    }

    bool getLotEmpty()
    {
        return lotEmpty;
    }

    void setLotName(string& name)
    {
        lotName = name;
    }

    void setEmptyStatusToFull()
    {
        lotEmpty = false;
    }

    void setEmptyStatusToEmpty()
    {
        lotEmpty = true;
    }
};



#endif
