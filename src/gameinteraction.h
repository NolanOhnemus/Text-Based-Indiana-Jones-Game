#ifndef GAMEINTERACTION_H_
#define GAMEINTERACTION_H_

#include <string>
#include "indianajones.h"
#include "map.h"

using namespace std;

class IndianaJones;

/* GameInteraction class
 * This class is responsible for the base rooms in the map. 
*/
class GameInteraction{
public:
    //interaction for when the player gets close to the room
    virtual void closeInteraction();
    // interaction for when the player enters a room
    virtual void actualInteraction();
    //Constructor that sets the position, room token, and keeps a reference for the pay if the room needs it
    GameInteraction(int width, int height, char token, IndianaJones *indianajones);
    //Default constructor does nothing
    GameInteraction();
    // returns the room token
    char display();
protected:
    // the x position of the room
    int xPosition;
    // the y position of the room
    int yPosition;
    /* 
     * The room token catagorized by a few different types
     * G - Guards
     * K - Keys
     * T - Treasure
     * B - Boulder
     * ' ' - empty room
    */
    char token;
    // pointer to the player for future use
    IndianaJones *indianajones;
};


/* Boulder class. Responsible for boulder type rooms*/
class Boulder: public GameInteraction{
public:
    // boulder constructor
    Boulder(int width, int height, char token, IndianaJones *indianajones) : GameInteraction(width, height, token, indianajones) {};
    // interaction when the player gets close
    void closeInteraction() override;
    // interaction when the player enters the room
    void actualInteraction() override;
    // randomly moves the player
    void moveIndianaJones();
private:
    // constant representing the world height and width
    static constexpr int WIDTH = 6;
    static constexpr int HEIGHT = 6;
};

/* Guard class. Responsible for guard type rooms*/
class Guard: public GameInteraction{
public:
    Guard(int width, int height, char token, IndianaJones *indianajones) : GameInteraction(width, height, token, indianajones) {};
    // interaction when the player gets close
    void closeInteraction() override;
    // interaction when the player enters the room
    void actualInteraction() override;
};

/* Treasure class. Responsible for treasure type rooms*/
class Treasure: public GameInteraction{
public:
    // constructor for treasure rooms
    Treasure(int width, int height, char token, IndianaJones *indianajones) : GameInteraction(width, height, token, indianajones) {};
    // interaction when the player gets close
    void closeInteraction() override;
    // interaction when the player enters the room
    void actualInteraction() override;
};

/* Key class. Responsible for key type rooms*/
class Key: public GameInteraction{
public:
    // constructor for key rooms
    Key(int width, int height, char token, IndianaJones *indianajones) : GameInteraction(width, height, token, indianajones) {};
    // interaction when the player gets close
    void closeInteraction() override;
    // interaction when the player enters the room
    void actualInteraction() override;
    // gives a key to the player
    void addKey();
};

#endif