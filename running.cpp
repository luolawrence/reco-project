//
//  running.cpp
//  Reco
//
//  Created by Lawrence Luo on 1/2/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#include "running.hpp"
#include <iostream>
#include "Tracker.hpp"
#include <vector>

using namespace std;

//list of running trackers
vector<tracker*> running_trackers;

//function that continues to run existing trackers
void running()
{
    /////structural dummy
    cout << "(dummy running) Running All Trackers\n";
    for (int i = 0; i < running_trackers.size(); i++) //Execute all trackers
    {
        running_trackers[i]->execute();
    }
}

void closeAll()
{
    //iteratively go through and delete each tracker from the heap
    for (int i = 0; i < running_trackers.size(); i++) //Close all trackers
    {
        running_trackers[i]->close();
        
        //remember to delete all of the pointers
        delete running_trackers[i];
    }
    
    /////structural dummy
    cout << "(dummy running) All trackers closed\n";
}

void add(tracker* t)
{
    running_trackers.push_back(t);
    
    /////structural dummy
    cout << "(dummy running) Adding tracker for " << t->returnName() << "\n";
    cout << "Printing all SOIs being tracked\n";
    for (int i = 0; i < running_trackers.size(); i++) //print all SOIs being tracked
    {
        cout << running_trackers[i]->returnName() << "\n";
    }
    cout << "\n";
}

void close(string firstName, string lastName)
{
    /////structural dummy
    cout << "(dummy running) Closing the tracker for " << firstName << " " << lastName << "\n";
    
    //This is O(n), not the fastest way to do it
    //go through the vector and find t
    for (int i = 0; i < running_trackers.size(); i++) //print all SOIs being tracked
    {
        if (running_trackers[i]->returnName() == firstName + " " + lastName)
        {
            running_trackers[i]->close(); //this stores the SOI info in the database
            
            //actually delete the tracker pointer
            delete running_trackers[i];
            
            //remove the pointer from the vector
            running_trackers.erase(running_trackers.begin() + i);
            
            //break out of the loop
            break;
        }
    }
    
    
    
    
    //print the remaining trackers
    cout << "Printing remaining trackers\n";
    
    for (int i = 0; i < running_trackers.size(); i++) //print all SOIs being tracked
    {
        cout << running_trackers[i]->returnName() << "\n";
    }
    cout << "\n";
}

bool tracking(string firstName, string lastName)
{
    for (int i = 0; i < running_trackers.size(); i++) //print all SOIs being tracked
    {
        if (running_trackers[i]->returnName() == firstName + " " + lastName)
        {
            return true;
        }
    }
    return false;
}
