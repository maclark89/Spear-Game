//  Random Spike thingy.
//
//  Created by Michael Clark on 5/01/11.
//

#include "Spike.h"

//This is the default constructor
Spike::Spike() {
    //This, by default will select the location that
    //the spike is placed in as 
    spikeLocation = "     ╫     ";
    positionNumberForm = 5;
}

std::string Spike::getLocation() {
    return spikeLocation;
}

void Spike::setLocation(std::string stringValue, int intValue) {
    spikeLocation = stringValue;
    positionNumberForm = intValue;
}