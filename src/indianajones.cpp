#include "indianajones.h"
#include <string>
#include <iostream>

class GameInteraction;

IndianaJones::IndianaJones(int startX, int startY){
    playerX = startX;
    playerY = startY;
    status = 'P';
}

int IndianaJones::getPositionX(){
    return playerX;
}

int IndianaJones::getPositionY(){
    return playerY;
}

bool IndianaJones::hasKey(){
    return keys > 0;
}

// P for in progress - W for win - L for lost
void IndianaJones::setStatus(char changedStatus){
    status = changedStatus;
}

char IndianaJones::getStatus(){
    return status;
}

void IndianaJones::addKey(){
    ++keys;
}

void IndianaJones::removeKey(){
    cout << "Attempting to switch the idol out for sand, you drop the bag ripping it." << endl;
    --keys;
}

void IndianaJones::randomlyMove(int x, int y){
        playerX = rand() % x;
        playerY = rand() % y;
}

void IndianaJones::direction(char move){        
        switch(move){
            case 'n':
                if(playerY > 0){
                    if(playerY == 1){
                        cout << "You notice a beam of light." << endl;
                    }  
                    playerY--;
                }
                else{
                    cout << "You step into the light activating spikes which impale you!" << endl;
                    this -> setStatus('L');
                }
                break;
            
            case 'w':
                if(playerX > 0){
                    if(playerX == 1){
                        cout << "You notice a beam of light." << endl;
                    } 
                    playerX--;
                }
                else{
                    cout << "You step into the light activating spikes which impale you!" << endl;
                    this -> setStatus('L');
                }
                break;
            
            case 's':
                if(playerY < 5){
                    if(playerY == 4){
                        cout << "You notice a beam of light." << endl;
                    } 
                    playerY++;
                }
                else{
                    cout << "You step into the light activating spikes which impale you!" << endl;
                    this -> setStatus('L');
                }
                break;
            
            case 'e':
                if(playerX < 5){
                    if(playerX == 4){
                        cout << "You notice a beam of light." << endl;
                    } 
                    playerX++;
                }
                else{
                    cout << "You step into the light activating spikes which impale you!" << endl;
                    this -> setStatus('L');
                }
                break;
        }
}