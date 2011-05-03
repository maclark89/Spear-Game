//
//  main.cpp
//  BoxGame
//
//  Created by Michael Clark on 5/2/11.
//

/********************************************
 * The idea behind this project is a simple *
 * game of catch the user must play with a  *
 * box and a spear. The random number will  *
 * determine the spear's position, and the  *
 * user will have to position the box to    *
 * catch it accordingly.                    *
 ********************************************/

#include <iomanip>
#include <iostream>
#include <time.h>

#include "Box.h"
#include "Spike.h"

using namespace std;


int main ()
{
    //Initializing a random number for
    //the purpose of creating our first box object
    //and spike objects.
    srand(time(NULL)); 
    
    
    //Beginning the game/instructions on how to play.
    cout << "Welcome to a fun game of catch!" << endl;
    cout << "\nIt honestly doesn't make much sense, but you are";
    cout << " going to want to catch this falling spike in a box!" << endl;
    
    sleep(3);
    
    cout << "\nJust tell me how many spaces over it is when it appears";
    cout << ", and I'll move the box";
    cout << " to catch it for you!" << endl;
    
    sleep(3);
    
    cout << endl << "Here goes!" << endl;
    
    cout << "The first one will be easy, I'll catch it for you." << endl;
    cout << "(If I can do it myself, why are you telling me what to ";
    cout << "do? Oh well, I digress.)" << endl << endl;
    
    sleep(3);
    
    //This will serve as a demonstration for the user.
    
    //Creating the lovely objects.
    
    Spike objSpike;
    Box objBox;
    
    //Outputting for the user to see 
    cout << objSpike.getLocation() << endl << endl;
    
    cout << "Alright, here's where you'd normally tell me how far over the box is,";
    cout << " and where I'd move the box to suit your request." << endl;
    cout << "Looks like that box is about five spaces over though, so I'll put the box down." << endl;
    
    sleep(3);
    
    cout << objSpike.getLocation() << endl;
    cout << objBox.getLocation() << endl << endl;
    
    sleep(3);
    
    cout << objBox.getDestroyed() << "<--- See! We got it!" << endl;
    
    sleep(3);
    
    cout << "Your turn now!" << endl;
    
    //user input holder
    int input = 0;
    //and the lovely SPEAR'S POSITION!!!
    int spikePosition;
    //string equivalent of the spear's position.
    string strSpike;
    //throwing a box string in here. #messy
    string strBox;
    
    
    //Randomizing the spike's position.
    spikePosition = rand() % 10 + 1;
    
    
    do {

        objSpike.setup(strSpike, spikePosition);
        
        objBox.setup(strBox, spikePosition);
        
        
        cout << "Okay, you can either guess the spike number, or enter ""-1"" to quit playing.";
        cout << endl << endl;
        
        cout << objSpike.getLocation() << endl << endl;
        
        cin >> input;
        
        
        if (input == spikePosition && input != -1) {
            cout << "Looks like you may have it!" << endl << endl;
            
            sleep(3);
            
            cout << objSpike.getLocation() << endl;
            cout << objBox.getLocation() << endl << endl;
            
            sleep(3);
            
            cout << objBox.getDestroyed() << "<--- We got it!" << endl;
        }
        
        if (input != spikePosition && input != -1) {
            cout << "Hmmm... Idk about that one..." << endl << endl;
            
            sleep(3);
            
            cout << objSpike.getLocation() << endl;
            cout << objBox.getLocation() << endl << endl;
            
            sleep(3);
            
            cout << "Running out of time! Try again!" << endl;
            
            cin >> input;
            
            if (input == spikePosition) {
                cout << "Looks like you may have it!" << endl << endl;
                
                sleep(3);
                
                cout << objSpike.getLocation() << endl;
                
                sleep(3);
                
                cout << objBox.getDestroyed() << "<--- We got it!" << endl;
            }
            else 
                cout << "You just killed me." << endl << endl;
            
            //Resetting the string variables so that the
            //last ones arent kept.
            strBox = "";
            strSpike = "";
            
        }
            spikePosition = rand() % 10 + 1;
        
    } while (input != -1);
  
    return 0;
}

