#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include <iostream>
#include <string>

class Player : public Character {
public:
    Player();
    Player(int row, int col);//2 arg constructor
    Player(const Player& orig);
    virtual ~Player();

private:

};

#endif /* PLAYER_H */

