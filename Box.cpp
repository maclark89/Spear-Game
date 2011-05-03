//  Random Box thingy.
//
//  Created by Michael Clark on 5/01/11.
//

#include "Box.h"

//This is the default constructor
Box::Box() {
    //This will place the box directly in the middle,
    //to catch the spike.
    boxLocation = "    |_|    ";
    positionNumberForm = 5;
    boxDestroyed = "    |╫|    ";
    
}

std::string Box::getLocation() {
    return boxLocation;
}

std::string Box::getDestroyed() {
    return boxDestroyed;
}

void Box::setLocation(std::string stringValue, int intValue) {
    boxLocation = stringValue;
    positionNumberForm = intValue;
}