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
#include <fstream>

#include "Box.h"
#include "Spike.h"

using namespace std;

//Number of scores to hold in a highscore array.
const int NUMBER_OF_SCORES = 10;

//Prototype of a high score module that will accept an array
//of integers and sort them into the 
int highscoreModule(int);

int main ()
{
    //Initializing a random number for
    //the purpose of creating our first box object
    //and spike objects.
    srand(time(NULL)); 
    
    /*This will actually be the beginnings of a high score
     system implementation.*/
    int score = 0;
    
    //This is an initialization of an array of scores that will be written to 
    //a file to keep track of high scores.
    int highscore[NUMBER_OF_SCORES];
    for (int count = 0; count < 10; count++) {
        highscore[count] = 0;
    }
    
    ofstream scoreFile;
    //Opening a file to be written to.
    scoreFile.open("HighScores.txt");
        
    //Beginning the game/instructions on how to play.
    cout << "Welcome to a fun game of catch!" << endl;
    cout << "\nIt honestly doesn't make much sense, but you are";
    cout << " going to want to catch this falling spike in a box!" << endl;
    
    sleep(3);
    
    cout << "\nJust tell me how many spaces over it is when it appears";
    cout << ", and I'll move the box";
    cout << " to catch it for you!" << endl;
    
    sleep(1);
    
    cout << endl << "Here goes!" << endl;
    
    cout << "The first one will be easy, I'll catch it for you." << endl;
    cout << "(If I can do it myself, why are you telling me what to ";
    cout << "do? Oh well, I digress.)" << endl << endl;
    
    sleep(1);
    
    //This will serve as a demonstration for the user.
    
    //Creating the lovely objects.
    
    Spike objSpike;
    Box objBox;
    
    //Outputting for the user to see 
    cout << objSpike.getLocation() << endl << endl;
    
    cout << "Alright, here's where you'd normally tell me how far over the box is,";
    cout << " and where I'd move the box to suit your request." << endl;
    cout << "Looks like that box is about five spaces over though, so I'll put the box down." << endl;
    
    sleep(1);
    
    cout << objSpike.getLocation() << endl;
    cout << objBox.getLocation() << endl << endl;
    
    sleep(1);
    
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
            
            //incrementing the score for this playthrough.
            score += 1;
        }
        
        if (input != spikePosition && input != -1) {
            cout << "Hmmm... Idk about that one..." << endl << endl;
            
            sleep(3);
            
            cout << objSpike.getLocation() << endl;
            cout << objBox.getLocation() << endl << endl;
            
            sleep(1);
            
            cout << "Running out of time! Try again!" << endl;
            
            cin >> input;
            
            if (input == spikePosition) {
                cout << "Looks like you may have it!" << endl << endl;
                
                sleep(1);
                
                cout << objSpike.getLocation() << endl;
                
                sleep(2);
                
                cout << objBox.getDestroyed() << "<--- We got it!" << endl;
                
                //incrementing score.
                score += 1;
            }
            else 
                cout << "You just killed me." << endl << endl;
            
            //Resetting the string variables so that the
            //last ones arent kept.
            strBox = "";
            strSpike = "";
            
        }
        //Setting the spike's position randomly again.
        spikePosition = rand() % 10 + 1;
        
        
    } while (input != -1);
    
    //Writing the score to a file.
    scoreFile << score << endl;
    
    //closing the scorefile.
    scoreFile.close();
    return 0;
}

int highscoreModule(int scores[NUMBER_OF_SCORES]) {
    bool swap;
    double temp;
    
    do
    {
        swap = false;
        for (int count = 0; count < (NUMBER_OF_SCORES - 1); count++) {
            if (scores[count] > scores[count +1]) {
                temp = scores[count];
                
                scores[count] = scores[count + 1];
                
                scores[count + 1] = temp;
                
                swap = true;
            }
        }
    } while (swap);
}
