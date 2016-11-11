#include "Character.h"
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player : public Character {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
private:

};

#endif /* PLAYER_H */

