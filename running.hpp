//
//  running.hpp
//  Reco
//
//  Created by Lawrence Luo on 1/2/19.
//  Copyright © 2019 Lawrence Luo. All rights reserved.
//

#ifndef running_hpp
#define running_hpp

#include <stdio.h>
#include "SOI.hpp"
#include "Tracker.hpp"

//function that continues to run existing trackers
void running();
void closeAll();
void close(string firstName, string lastName);
void add(tracker* t);
bool tracking(string firstName, string lastName);
#endif /* running_hpp */
