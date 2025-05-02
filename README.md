# Wumpus Game

### Introduction:
This project was the final project for our C/C++ class. We were instructed to completely write our own version of the game *Hunt the Wumpus* in C++ 17. The project was loosly based on the introduction scene of *Indiana Jones and the Raiders of the Lost Ark*. Using text inputs, the player is able to navigate around a randomly generated map looking for bags of sands to swap for the idol statue. Descriptions are given to the player to help them navigate around the map to avoid traps and find the artifact. The program showcases text input and parsing, memory management, random probability calculations, and proper object oriented design.

## How to Build the project:
This project used g++ with visual studio and codelite to build this project in C++ 17.
To build this project navigate into the src folder and run the following command:
- g++ -Wall -std=c++17 *.cpp -o IndianaJonesGame.exe

## Debug mode:
Debug mode is accessed through the main menu when the game is launched. Simply input 'd' into the main menu and you will enter a seeded run of the game. It will also print the map out after every move to better show where you are in the map. If you need to debug the random games, you can simply input 'm' when the game asks for actions and it will print the map out.

## g++ Version Output:
g++ (MinGW.org GCC-6.3.0-1) 6.3.0 Copyright (C) 2016 Free Software Foundation, This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
