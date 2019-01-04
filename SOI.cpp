//
//  SOI.cpp
//  Reco
//
//  Created by Lawrence Luo on 1/2/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#include "SOI.hpp"
#include <string>

SOI::SOI(string first, string last)
{
    firstName = first;
    lastName = last;
    
    /////structural dummy
    //cout << "(dummy SOI) Created SOI for " << first << " " << last << "\n";
}

SOI::SOI()
{
    
}

string SOI::returnInfo()
{
    return firstName + "," + lastName + "," + to_string(num1) + "," + to_string(num2) + "," + to_string(num3) + "," + to_string(num4) + "\n";
}
