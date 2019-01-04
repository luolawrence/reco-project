//
//  main.cpp
//  Reco
//
//  Created by Lawrence Luo on 12/31/18.
//  Copyright © 2018 Lawrence Luo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "running.hpp"
#include "utilities.hpp"
#include "Tracker.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    //return 0;
    
    //Start Displaying program
    //Ask for user input
    //string firstName, lastName;
    int mode;
    string modeString;
    bool done = false;
    
    while (!done)
    {
        //User selects a mode
        cout << "Select mode: (1) SOI Lookup, (2) New SOI Tracking Session, (3) Update SOI Information, (4) Close a Tracker, (5) Close All Trackers and Exit: ";
        cin >> mode;
        
        //error checking
        if (mode < 1 || mode > 5)
        {
            cerr << "ERROR: mode must be 1, 2, or 3";
            exit(1);
        }
        
        //Display the corresponding string
        switch(mode)
        {
            case 1: //SOI Lookup
            {
                cout << "Mode 1: SOI Lookup selected\n";
                
                //Open the database file
                fstream fs;
                fs.open ("/Users/LawrenceLuo/Documents/Reco Project/Reco/Reco/Database.csv");
                if (!fs)
                {
                    cerr << "ERROR: Unable to open file Database.csv\n";
                    exit(1);   // call system to stop
                }
                
                string firstName, lastName;
                cout << "Enter the SOI's first and last name: ";
                cin >> firstName >> lastName; //Add error checking later
                
                //lookup in the file
                bool ex = exists(firstName, lastName);
                
                if (!ex)
                {
                    cout << firstName << " " << lastName << " not found" << endl;
                }
                else
                {
                    SOI dummy = GetSOI(firstName, lastName);
                    cout << "Displaying SOI Information:\n" << dummy.returnInfo() << "\n";
                }
                
                
                //Close the database file
                fs.close();
                break;
            }
            case 2:
            {
                string firstName, lastName;
                cout << "Mode 2: New SOI Tracking Session selected\n";
                cout << "Enter the SOI's first and last name: ";
                cin >> firstName >> lastName;
                
                //create a tracker on the heap
                tracker* t = new tracker(firstName, lastName);
                
                //then add it to the running trackers
                add(t);
                
                break;
            }
            case 3:
            {
                string firstName, lastName;
                int n1, n2, n3, n4;
                cout << "Mode 3: Update SOI Information selected\n";
                cout << "Type the first and last name of desired SOI: ";
                cin >> firstName >> lastName;
                
                if(exists(firstName, lastName))
                {
                    if (tracking(firstName,lastName))
                    {
                        cout << firstName << " " << lastName << " is currently being tracked\n";
                    }
                    else
                    {
                        cout << "Type the information for " << firstName << " " << lastName << ": ";
                        cin >> n1 >> n2 >> n3 >> n4; /////add error checking
                        
                        SOI person = SOI(firstName, lastName);
                        person.num1 = n1;
                        person.num2 = n2;
                        person.num3 = n3;
                        person.num4 = n4;
                        
                        updateDatabase(person);
                    }                  
                }
                else
                {
                    cout << firstName << " " << lastName << " not found" << endl;
                }
                
                
                break;
            }
            case 4:
            {
                string firstName, lastName;
                cout << "Mode 4: Close a Tracker\n";
                cout << "Enter desired SOI's first and last name: ";
                cin >> firstName >> lastName;
                close(firstName, lastName);
                
                break;
            }
            case 5:
            {
                cout << "Closing all trackers and exiting program\n";
                done = true;
                
                //Close all of the trackers
                closeAll();
                
                break;
            }
        }
    }
}
