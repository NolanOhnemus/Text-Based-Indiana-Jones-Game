#include <iostream>
#include <stdio.h>
#include "map.h"
#include "indianajones.h"
#include "gameinteraction.h"
using namespace std;


bool debug = false;
string menu(){
    string menu = 
    "\n"
    "MENU\n"
    "List of Rules:\n"
    "This is a 6x6 grid you will be searching to find\n"
    "teasure in.\n"
"-	Use e/w/n/s to move directions.\n"
"-	You have to find the key before you can open the treasure.\n" 
"-	There is only 1 treasure chest.\n"
"-	There are possible 3 keys that you can find.\n"
"-	There are 6 guards you have to avoid. \n"
"-	There are 4 boulders that could run you over. \n"
"-	M to display map\n\n";

    return menu;
}

void gatherClues(Map *map, IndianaJones *indianajones){
    int indyX = indianajones -> getPositionX();
    int indyY = indianajones -> getPositionY();
    
    if(indyX > 0){
        GameInteraction *room = map -> getRoom(indyX - 1, indyY);
        room -> closeInteraction();
    }
    if(indyX < 5){
        GameInteraction *room = map -> getRoom(indyX + 1, indyY);
        room -> closeInteraction();
    }
    if(indyY > 0){
        GameInteraction *room = map -> getRoom(indyX, indyY - 1);
        room -> closeInteraction();
    }
    if(indyY < 5){
        GameInteraction *room = map -> getRoom(indyX, indyY + 1);
        room -> closeInteraction();
    }
    
    GameInteraction *room;
    if(indyX > 1){
        room = map -> getRoom(indyX - 2, indyY);
        if(room -> display() == 'B' || room -> display() == 'T')
        {
            room -> closeInteraction();
        }
    }
    if(indyX < 4){
        room = map -> getRoom(indyX + 2, indyY);
        if(room -> display() == 'B' || room -> display() == 'T')
        {
            room -> closeInteraction();
        }
    }
    if(indyY > 1){
        room = map -> getRoom(indyX, indyY - 2);
        if(room -> display() == 'B' || room -> display() == 'T')
        {
            room -> closeInteraction();
        }
    }
    if(indyY < 4){
        room = map -> getRoom(indyX, indyY + 2);
        if(room -> display() == 'B' || room -> display() == 'T')
        {
            room -> closeInteraction();
        }
    }
}

void requestAction(){
    cout << "Action: N)orth, S)outh, E)ast, W)est, U)nlock Treasure, H)elp, Q)uit: " << endl;
}

void checkCurrentSpace(Map *map, IndianaJones *indianajones){
    int indyX = indianajones -> getPositionX();
    int indyY = indianajones -> getPositionY();
    GameInteraction *currentRoom = map -> getRoom(indyX, indyY);
    currentRoom -> actualInteraction();
}

void handleAction(Map *map, IndianaJones *indianajones){
    char input;
    cin >> input;
    input = tolower(input);
    switch(input){
        case 'n':
            indianajones -> direction(input);
            checkCurrentSpace(map, indianajones);
            break;
        case 's':
            indianajones -> direction(input);
            checkCurrentSpace(map, indianajones);
            break;
        case 'e':
            indianajones -> direction(input);
            checkCurrentSpace(map, indianajones);
            break;
        case 'w':
            indianajones -> direction(input);
            checkCurrentSpace(map, indianajones);
            break;
        case 'u':
            if(indianajones -> hasKey()){
                cout << "Which way is the treasure? N/S/E/W?" << endl;
                char answer;
                cin >> answer;
                answer = tolower(answer);
                int indyX = indianajones -> getPositionX();
                int indyY = indianajones -> getPositionY();
                if(answer == 'n'){
                    GameInteraction *roomCheck = map -> getRoom(indyX, indyY + 1);
                    if(roomCheck -> display () == 'T'){
                        indianajones -> setStatus('W');
                    }
                    else indianajones -> removeKey();
                }
                else if(answer == 's'){
                    GameInteraction *roomCheck = map -> getRoom(indyX, indyY - 1);
                    if(roomCheck -> display () == 'T'){
                        indianajones -> setStatus('W');
                    }
                    else indianajones -> removeKey();
                }
                else if(answer == 'e'){
                    GameInteraction *roomCheck = map -> getRoom(indyX + 1, indyY);
                    if(roomCheck -> display () == 'T'){
                        indianajones -> setStatus('W');
                    }
                    else indianajones -> removeKey();
                }
                else if(answer == 'w'){
                    GameInteraction *roomCheck = map -> getRoom(indyX - 1, indyY);
                    if(roomCheck -> display () == 'T'){
                        indianajones -> setStatus('W');
                    }
                    else indianajones -> removeKey();
                }
            }
            else cout << "You do not have a key to try and unlock the chest." << endl;
            break;
        case 'h':
            cout << menu();
            break;
        case 'q':
            exit(0);
        case 'm':
            map -> display(indianajones);
    }
}

void playGame(bool debug){
    Map *map = new Map();
    IndianaJones *indianajones = new IndianaJones(1, 1);
    map -> load(indianajones, debug);
    //checkCurrentSpace(map, indianajones);
    while(indianajones -> getStatus() == 'P'){
        if(debug){
            map -> display(indianajones);
        }
        gatherClues(map, indianajones);
        requestAction();
        handleAction(map, indianajones);
    }
    if(indianajones -> getStatus() == 'W'){
        cout << "Congrats! You found the treasure!" << endl;
    }
    else if(indianajones -> getStatus() == 'L'){
        cout << "You lose!" << endl;
    }
    exit(0);
}


int main()
{
    char userChoice;
	cout << "Welcome to the off brand Indiana Jones Game" << endl;
    cout << "Press r to see the rules, p to play the game, d to play on debug mode, or enter any key to quit" << endl;
    while(cin >> userChoice){
        if(tolower(userChoice) == 'p'){
            playGame(false);
        }else if(tolower(userChoice) == 'r'){
            cout << menu() << endl;
        }else if(tolower(userChoice) == 'd'){
            playGame(true);
        }else{
            exit(0);
        }
    }
}
