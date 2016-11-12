#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include <iostream>
#include <string>

class Player : public Character {
public:
    //inventory...
    int gold;
    Player();
    Player(int row, int col);//2 arg constructor
    Player(const Player& orig);
    ~Player();

private:

};

#endif /* PLAYER_H */

