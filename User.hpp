#ifndef USER_H
#define USER_H

#include "ParkingStrategy.hpp"
#include <string>


using namespace std;

class User 
{
    private:

        ParkingStrategy* strategy;  
        string userID;
        string userName;



    public:
        User(const string& user_name, const string& user_id) {
            this->userName=user_name;
            this->userID=user_id;
            this->strategy=NULL;
        }

        void setStrategy(ParkingStrategy* new_strat) 
        {
            strategy = new_strat;
        }

        void executeStrategy() const 
        {
            strategy->park();
        }

        string getName()  
        { 
            return userName; 
        }
        string getUID()  
        { 
            return userID; 
        }
};

#endif