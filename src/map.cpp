/*
 * map.cpp
 *
 *      Author: Nolan Ohnemus
 */

#include "map.h"
#include "gameinteraction.h"
#include "indianajones.h"
#include <string>
#include <time.h>
#include <iostream>
using namespace std;

Map::Map(){}

void Map::load(IndianaJones *indianajones, bool debug){
    //pre load the room token array with blank characters
    char roomTokens[WIDTH][HEIGHT];
    for(int i = 0; i < HEIGHT; ++i){
        for(int j = 0; j < WIDTH; ++j){
            roomTokens[j][i] = ' ';
        }
    } 

    //generate the map randomly
    generateMap(roomTokens, debug);

    //create the actual rooms based on the tokens generated
    for(int i = 0; i < HEIGHT; ++i){
        for(int j = 0; j < WIDTH; ++j){
            char input = roomTokens[j][i];
            GameInteraction *room;
            switch(input){
                case 'G':
                    room = new Guard(j, i, input, indianajones);
                    break;
                case 'B':
                    room = new Boulder(j, i, input, indianajones);
                    break;
                case 'K':
                    room = new Key(j, i, input, indianajones);
                    break;
                case 'T':
                    room = new Treasure(j, i, input, indianajones);
                    break;
                default:
                    room = new GameInteraction(j, i, input, indianajones);
                    break;
                    
            }
            rooms[j][i] = room;
        }
    }  
}

void Map::generateMap(char roomTokens[WIDTH][HEIGHT], bool debug){

    //Seed the random number generation
    if(debug){
        srand(1);
    }
    else srand(time(NULL));

    //get the constants of the map and set them to mutable variables
    int numberOfSpecialRooms = NUM_OF_KEYS + NUM_OF_GUARDS + NUM_OF_BOULDERS + NUM_OF_TREASURES;
    int numberOfRooms = WIDTH * HEIGHT;
    int keys = NUM_OF_KEYS;
    int guards = NUM_OF_GUARDS;
    int boulders = NUM_OF_BOULDERS;
    int treasures = NUM_OF_TREASURES;

    //get the weights for each different kind of room that will be used in proability calucations
    double keyWeight = (double)keys / (double)numberOfSpecialRooms;
    double guardWeight = (double)guards / (double)numberOfSpecialRooms;
    double boulderWeight = (double)boulders / (double)numberOfSpecialRooms;
    double treasureWeight = (double)treasures / (double)numberOfSpecialRooms;
    double totalWeight = keyWeight + guardWeight + boulderWeight + treasureWeight;
    double weightArray[4] = {keyWeight, guardWeight, boulderWeight, treasureWeight}; 

    //set the first probability of generating a special room
    double probabilityOfSpecial = (numberOfSpecialRooms * 1.0) / numberOfRooms;

    //iterate through each room...
    for(int i = 0; i < HEIGHT; ++i){
        for(int j = 0; j < WIDTH; ++j){
            //... and get a random number to see if the room were making is a special room
            double randomNumber = (double)rand() / (double)RAND_MAX;
            if(randomNumber <= probabilityOfSpecial){
                //get the kind of special room it is
                char randomToken = getRandomRoomToken(weightArray, 4, totalWeight, keys, guards, 
                                                      boulders, treasures);
                roomTokens[j][i] = randomToken;
                //recalculate the probability of getting a special room
                numberOfSpecialRooms--;
                probabilityOfSpecial = (double)numberOfSpecialRooms / (double)numberOfRooms;

                // recalculate the weights of each room
                double keyWeight = (double)keys / (double)numberOfSpecialRooms;
                double guardWeight = (double)guards / (double)numberOfSpecialRooms;
                double boulderWeight = (double)boulders / (double)numberOfSpecialRooms;
                double treasureWeight = (double)treasures / (double)numberOfSpecialRooms;
                double totalWeight = keyWeight + guardWeight + boulderWeight + treasureWeight;
                weightArray[0] = keyWeight;
                weightArray[1] = guardWeight;
                weightArray[2] = boulderWeight;
                weightArray[3] = treasureWeight;
            }
            // if not set it to a blank room
            else{
                roomTokens[j][i] = ' ';
            }
            //recalculate the probability of getting a special room
            --numberOfRooms;
            probabilityOfSpecial = (double)numberOfSpecialRooms / (double)numberOfRooms;
        }
    }
}

//get a random room token based on the weights of the special rooms and how many of each kind there are
char Map::getRandomRoomToken(double weightArray[], int arraySize, double totalWeight, 
                             int &keys, int &guards, int &boulders, int &treasures){
    // set the current weight for what kind of special room it is
    double currentWeight = 0;
    double roomRandom = (double)rand() / (double)RAND_MAX;
    //check each weight to see if we landed on that chunk of the "roulette wheel"
    for(int i = 0; i < arraySize; ++i){
        double weight = weightArray[i];
        //increment current weight
        currentWeight += weight / totalWeight;
        //if we are this kind of special room...
        if(roomRandom <= currentWeight){
            //... check what kind we are based of the index of the chunks 
            //    based on where they are in the array
            switch(i){
                case 0:
                    if(keys > 0){
                        keys--;
                        return 'K';
                    }
                    else return ' ';
                    break;
                case 1:
                    if(guards > 0){
                        guards--;
                        return 'G';
                    } 
                    else return ' ';
                    break;
                case 2:
                    if(boulders > 0){
                        boulders--;
                        return 'B';
                    }
                    else return ' ';
                    break;
                case 3:
                    if(treasures > 0){
                        treasures--;
                        return 'T';
                    }
                    else return ' ';
                    break;
                }
        }
    }
    return ' ';
}

//display the game room
void Map::display(IndianaJones *indianajones){
    int indyX = indianajones -> getPositionX();
    int indyY = indianajones -> getPositionY();
    
    for(int i = 0; i < HEIGHT; ++i){
        for(int j = 0; j < WIDTH; ++j){
            if(i == indyY && j == indyX){
                cout << 'P';
            }
            else {
                GameInteraction *room = this -> getRoom(j, i);
                cout << room -> display();
            }
        }
        cout << endl;
    }
}

//get a specific room in the list of rooms
GameInteraction* Map::getRoom(int width, int height){
    return rooms[width][height];
}