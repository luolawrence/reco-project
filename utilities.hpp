//
//  utilities.hpp
//  Reco
//
//  Created by Lawrence Luo on 1/3/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <stdio.h>
#include "SOI.hpp"

//function that figures out if a person exists in the database already
SOI GetSOI(string firstName, string lastName); //returns the line number
    //change this ^ so that is returns the actual SOI instance
bool exists(string firstName, string lastName);

void updateDatabase(SOI soi);

#endif /* utilities_hpp */
