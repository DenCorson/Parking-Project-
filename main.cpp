#include "ParkingLotFactory.hpp"
#include "ParkingLotDecorator.hpp"
#include "Observer.hpp"

#include "User.hpp"
#include "AdminParkingStrategy.hpp"
#include "StudentParkingStrategy.hpp"
#include "FacultyParkingStrategy.hpp"

int main() {
    //creates a parking lot "lotA" with 3 spaces in 
    //ParkingLot lotA = ParkingLotFactory::createParkingLot("Lot A", 3);
    //lotA.display();    
    //lotA.reserveSpace(1, 7, 9);
    //lotA.display();
    
    //ParkingSpace space4(4, true);  // example of a parking space object being created to be added to lotA  (space4, empty)
    //lotA.addSpace(space4);
    //lotA.display();

    ///   Below is test for decortors for student and faculty parking lots

            // ParkingLot* decoratedFacultyLot = new ParkingLot (ParkingLotFactory::createParkingLot("Faculty Lot", 3));
            // FacultyLotDecorator* falcultyLot1 = new FacultyLotDecorator(decoratedFacultyLot);

            // falcultyLot1->display();
            //falcultyLot1->reserveFacultySpot("rag", 1, 2,5);


             //ParkingLot* decoratedStudentLot = new ParkingLot (ParkingLotFactory::createParkingLot("Student Lot", 3));
            //StudentLotDecorator* studentLot1 = new StudentLotDecorator(decoratedStudentLot);
    
            //studentLot1->display();
            //studentLot1->reserveStudentSpot("blip", 1, 2, 5);
            //studentLot1->reserveStudentSpot("dip", 1, 2, 6);

            //studentLot1->clearSpace(1);
            //studentLot1->reserveStudentSpot("ted", 1, 2, 6);

    // Below is test for Observers with decorators student and faculty lot,

// Create Faculty Lots with Faculty Decorators and Observers
    ParkingLot* decoratedFacultyLot1 = new ParkingLot(ParkingLotFactory::createParkingLot("Faculty Lot", 3));
    FacultyLotDecorator* facultyLot2 = new FacultyLotDecorator(decoratedFacultyLot1);

    facultyLot2->display(); // displays the facultylots information 3 empty spaces 
    facultyLot2->reserveFacultySpot("Faculty1", 1, 8, 10); // Reserves space 1 for faculty
    facultyLot2->reserveFacultySpot("Faculty2", 1, 9, 11); // Should show space is already occupied

    // Create Student Lot with Student Decorator and Observers
    ParkingLot* decoratedStudentLot1 = new ParkingLot(ParkingLotFactory::createParkingLot("Student Lot", 3));
    StudentLotDecorator* studentLot2 = new StudentLotDecorator(decoratedStudentLot1);

    studentLot2->display();
    studentLot2->reserveStudentSpot("Student1", 2, 10, 12); // Reserves space 2 for student
    studentLot2->clearSpace(2);                             // Clears space 2
    studentLot2->reserveStudentSpot("Student2", 2, 11, 14); // Re-reserves cleared space

    // Display final lot status
    cout << "\nFinal Faculty Lot Status:\n";
    facultyLot2->display();

    cout << "\nFinal Student Lot Status:\n";
    studentLot2->display();


    // strategy pattern functionality 

    // create users
    User admin("Bob", "123");
    User student("Steve", "456");
    User faculty("Jane", "789");

    //create strategies
    AdminParkingStrategy adminStrategy;
    StudentParkingStrategy studentStrategy;
    FacultyParkingStrategy facultyStrategy;

    //set user strategies
    admin.setStrategy(&adminStrategy);
    student.setStrategy(&studentStrategy);
    faculty.setStrategy(&facultyStrategy);

    //execute strategies
    admin.executeStrategy();  
    student.executeStrategy(); 
    faculty.executeStrategy(); 

    return 0;
}


