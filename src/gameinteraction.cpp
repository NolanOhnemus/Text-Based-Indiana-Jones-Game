#include "gameinteraction.h"
#include "indianajones.h"
#include <iostream>

/*Game Interaction Class*/

GameInteraction::GameInteraction(){
    
}
GameInteraction::GameInteraction(int width, int height, char roomKind, IndianaJones *indy){
    xPosition = width;
    yPosition = height;
    token = roomKind;
    indianajones = indy;
}

void GameInteraction::actualInteraction(){
    return;
}

void GameInteraction::closeInteraction(){
    return;
}

char GameInteraction::display(){
    return token;
}


/*Guard Class*/

void Guard::closeInteraction(){
    cout << "You hear the sound of footsteps near you." << endl;
}

void Guard::actualInteraction(){
    cout << "The temple guards catch you and scrafice you to Kali." << endl;
    indianajones -> setStatus('L');
}



/* Boulder Class*/

void Boulder::closeInteraction(){
    cout << "You hear a rumbling in the distance." << endl;
}

void Boulder::actualInteraction(){
    cout << "The boulder starts tumbling towards you and runs you to a random spot in the cave!" << endl;
    this -> moveIndianaJones();
}

void Boulder::moveIndianaJones(){
    indianajones -> randomlyMove(WIDTH, HEIGHT);
}

/* Treasure Class*/

void Treasure::closeInteraction(){
    cout << "You feel a stairway leading up to the idol." << endl;
}

void Treasure::actualInteraction(){
    cout << "You remove the idol from its podeum causing a cave in which crushes you." << endl;
    indianajones -> setStatus('L');
}

/* Key room class */

void Key::closeInteraction(){
    cout << "You hear the faint sound of cloth ruffling." << endl;
}

void Key::actualInteraction(){
    cout << "You find and fill a bag with sand." << endl;
    this -> addKey();
}

void Key::addKey(){
    indianajones -> addKey();
}