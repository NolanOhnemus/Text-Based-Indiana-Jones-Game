# Wumpus Lab
## Who's involved
- Nolan Ohnemus
- Cecelia Henson
### Note:
This lab was done 70% by myself as we had problems with communication and with a group member being MIA. The Main, Map, and IndianaJones class were almost entirly written by me but most of the GameInteraction class was written by Cecelia. She assited with getting the framework done for the class but I did have to change some things later down the road.
## How to Build the project
I used g++ with visual studio and codelite to help build this project in C++ 17.
To build this project I went into the src folder and ran the following command:
- g++ -Wall -std=c++17 *.cpp -o IndianaJonesGame.exe
## Debug mode
Debug mode is accessed through the main menu when the game is launched. Simply input 'd' into the main menu and you will enter a seeded run of the game. It will also print the map out after every move to better show where you are in the map. If you need to debug the random games, you can simply input 'm' when the game asks for actions and it print the map out.
## Changes Made to the Project
Only minor cosmetic changes were done to the project mainly in what the clues are to the reader. Treasure chests didn't feel very Indiana Jones so keys and treasure chests were replaced with bags of sand and the idol podeum much like the into to the first movie. I also added clues to let the player know when they are close to a wall to make it a little easier if you've been moved randomly. I also made the Key class inherit from the GameInteraction class which was not origianily in the diagram but made it more consistent and easier to work with.
## g++ Version Output
g++ (MinGW.org GCC-6.3.0-1) 6.3.0 Copyright (C) 2016 Free Software Foundation, This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
