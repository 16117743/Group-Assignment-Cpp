#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Inventory.h"
#include <iostream>
#include <string>

class Player : public Character {
public:
    Inventory inventory;
    int gold;
    Player();
    Player(Character c);
    Player(const Player& orig);
    ~Player();
    void pickup(Item *item);

private:

};

#endif /* PLAYER_H */

