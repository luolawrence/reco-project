//
//  Tracker.cpp
//  Reco
//
//  Created by Lawrence Luo on 1/2/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#include "Tracker.hpp"
#include <iostream>
#include <string>
#include "utilities.hpp"

using namespace std;

tracker::tracker(string firstName, string lastName)
{
    SOI person;
    bool ex = exists(firstName, lastName);
    
    //if doesn't exist
    if (!ex)
    {
        person = SOI(firstName, lastName);
    }
    else
    {
        person = GetSOI(firstName, lastName);
    }
    
    soi = person;
    
    //check if the person already exists in the database
    //if so load the existing data from database then update it by scraping
    //else, create a new database entry
    
    /////structural dummy
    if (!ex)
    {
        cout << "(dummy tracker) Creating New SOI and Instantiating New Tracker for SOI: " << soi.firstName << " " << soi.lastName << "\n";
    }
    else
    {
           cout << "(dummy tracker) Instantiating Tracker for Existing SOI: " << soi.firstName << " " << soi.lastName << "\n";
    }
}


void tracker::execute()
{
    /////structural dummy
    cout << "(dummy tracker) Executing Tracker for " << soi.firstName << " " << soi.lastName << "\n";
}

void tracker::close()
{
    /////structural dummy
    cout << "(dummy tracker) Closing Tracker\n";
    
    //Store all SOI information in the database
    updateDatabase(soi);
}

//for testing purposes
string tracker::returnName()
{
    return soi.firstName + " " + soi.lastName;
}
//for testing purposes
string tracker::returnNums()
{
    return to_string(soi.num1) + " " + to_string(soi.num2) + " " + to_string(soi.num3) + " " + to_string(soi.num4);
}

//void tracker::reload(SOI person)
//{
//    /////structural dummy
//    cout << "(dummy tracker) reloading tracker for " << person.firstName << " " << person.lastName << "\n";
//}
