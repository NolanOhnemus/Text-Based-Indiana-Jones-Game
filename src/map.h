/*
 * map.h
 *
 *      Author: [[TODO]]
 */

#ifndef MAP_H_
#define MAP_H_

class GameInteraction;
class IndianaJones;

class Map {
    // constants for the height and width of the map
    static constexpr int WIDTH = 6;
    static constexpr int HEIGHT = 6;
    // constants for the number of different room kinds
    static constexpr int NUM_OF_KEYS = 3;
    static constexpr int NUM_OF_GUARDS = 6;
    static constexpr int NUM_OF_BOULDERS = 4;
    static constexpr int NUM_OF_TREASURES = 1;
    // the 2-D array containig the rooms
    GameInteraction *rooms[WIDTH][HEIGHT] = {};
public:
  // initialize empty map
  Map();
  // load the map with rooms
  void load(IndianaJones *indianajones, bool debug);
  // write the full map to cout
  void display(IndianaJones *indianajones);
  //randomly generate a map
  // if debug is true the map is seeded to be consistent
  // uses roulette wheel probabilites to ensure that all room kinds are present and random
  void generateMap(char[WIDTH][HEIGHT], bool debug);
  //randomly generate a room token based on weights
  // Uses roulette wheel probabilities to pick a random room based on the weights of each room kind.
  char getRandomRoomToken(double[], int, double, int&, int&, int&, int&);
  // get a specific room to analyze
  GameInteraction *getRoom(int width, int height);
};

#endif /* MAP_H_ */
