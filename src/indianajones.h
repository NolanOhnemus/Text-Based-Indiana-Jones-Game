#ifndef INDIANAJONES_H_
#define INDIANAJONES_H_

#include <string>
#include "gameinteraction.h"
#include "map.h"
using namespace std;

class IndianaJones{
public:
    //Constructor which sets the initial position of the player
    IndianaJones(int startX, int startY);
    // return a position coordinate
    int getPositionX();
    int getPositionY();
    //set our position to be random in the map
    // x and y are the max to be random
    void randomlyMove(int x, int y);
    // move the player in a direction
    void direction(char move);
    // return true if the player has any keys
    bool hasKey();
    // set the status of the player so we know if the player is dead, alive, or has won
    void setStatus(char status);
    // get the status of the player so we know if the player is dead, alive, or has won
    char getStatus();
    // add a key to the player
    void addKey();
    //remove a key to the player
    void removeKey();
private:
    // number of keys the player has
    int keys;
    // position of the player
    int playerX;
    int playerY;
    // The current status of the player
    //    - 'P' for in progress
    //    - 'W' for win
    //    - 'L' for lose    
    char status;
};
#endif