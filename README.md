# Wumpus Game

### Introduction:
This project served as the final assignment for our C/C++ programming course. We were tasked with independently developing a complete version of Hunt the Wumpus using C++17. Our implementation was loosely inspired by the opening scene of Indiana Jones and the Raiders of the Lost Ark. Through text-based inputs, players navigate a randomly generated map in search of bags of sand to exchange for an idol statue. Descriptive cues are provided to assist players in avoiding traps and successfully locating the artifact. The project demonstrates key programming concepts, including text input handling and parsing, memory management, random probability generation, and robust object-oriented design.

## How to Build the project:
This project used g++ with visual studio and codelite to build this project in C++ 17.
To build this project navigate into the src folder and run the following command:
- g++ -Wall -std=c++17 *.cpp -o IndianaJonesGame.exe

## Debug mode:
Debug mode is accessed through the main menu when the game is launched. Simply input 'd' into the main menu and you will enter a seeded run of the game. It will also print the map out after every move to better show where you are in the map. If you need to debug the random games, you can simply input 'm' when the game asks for actions and it will print the map out.

## g++ Version Output:
g++ (MinGW.org GCC-6.3.0-1) 6.3.0 Copyright (C) 2016 Free Software Foundation, This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
