//  Spike.h
//  Random Spike for throwing into box!
//
//  Created by Michael Clark on 5/01/11.
//

#include <string>

#ifndef SPIKE_H
#define SPIKE_H



class Spike
{
private:
    
    //Private variables to be used inside the class.
    std::string spikeLocation;
    int positionNumberForm;
public:
    
    //This is the default constructor.
    Spike();
    
    std::string getLocation();
    

    void setLocation(std::string, int);

};
#endif

