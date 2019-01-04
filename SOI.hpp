//
//  SOI.hpp
//  Reco
//
//  Created by Lawrence Luo on 1/2/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#ifndef SOI_hpp
#define SOI_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class SOI {
public:
    string firstName;
    string lastName;
    
    //These fields are for testing purposes only
    int num1, num2, num3, num4;
    
    SOI(string first, string last); //Only include mandatory fields as inputs to constructor
    SOI();
    string returnInfo();
private:
    //Move some of the public fields to private based on accessibility requirements
};






#endif /* SOI_hpp */
