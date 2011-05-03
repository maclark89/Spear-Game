//  Box.h
//  Random Box object for holding stuff.
//
//  Created by Michael Clark on 5/01/11.
//

#include <string>

#ifndef BOX_H
#define BOX_H



class Box
{
private:
    
    //Private variables to be used inside the class.
    std::string boxLocation;
    int positionNumberForm;
    std::string boxDestroyed;
    
public:
    
    //This is the default constructor.
    Box();
    
    //This will return the box location to 
    //the main.
    std::string getLocation();
    
    std::string getDestroyed(); //HILARIOUS NO!?!?
    
    void setLocation(std::string, int);
    
    void setup(std::string, int);

};
#endif

