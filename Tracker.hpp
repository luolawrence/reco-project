//
//  Tracker.hpp
//  Reco
//
//  Created by Lawrence Luo on 1/2/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#ifndef Tracker_hpp
#define Tracker_hpp

#include <stdio.h>
#include "SOI.hpp"

class tracker {
public:
    void execute();
    void close(); //First store records in Database and then delete tracker instance
    //void reload(SOI person);
    
    string returnName();//for testing purposes
    string returnNums(); //for testing purposes
    
    tracker(string firstName, string lastName);
private:
    SOI soi;
};





#endif /* Tracker_hpp */
