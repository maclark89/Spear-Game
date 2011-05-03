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

void Spike::setup(std::string value, int intValue) {
    
    positionNumberForm = intValue;
    
    //This for loop will set the string up for being 
    //where the user will want to guess for.
    for (int count = 0; count < intValue; count++) {
        value += " ";
    }
    
    value += "╫";
    
    spikeLocation = value;
}