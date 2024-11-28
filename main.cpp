#include "ParkingLotFactory.hpp"

int main() {
    // Create a parking lot "LotB" with 2 spaces
    ParkingLot lot2 = ParkingLotFactory::createParkingLot("Lot B ", 2);
    cout << "There are " <<lot2.countEmptySpaces() << " empty spaces in this lot." << endl; 
    lot2.getSpaces();
    lot2.reserveSpace(1);
    cout << "There are now " <<lot2.countEmptySpaces() << " empty spaces in this lot." << endl; 

    //creates a parking lot "lotA" with 3 spaces in 
    ParkingLot lotA = ParkingLotFactory::createParkingLot("Lot A", 3);
    lotA.display();    
    lotA.reserveSpace(1);
    lotA.reserveSpace(2);
    lotA.display();
    
    ParkingSpace space4(4, true);  // example of a parking space object being created to be added to lotA  (space4, empty)
    lotA.addSpace(space4);
    lotA.display();

    return 0;
}
