/**
 * File: Player.h
 * Date: 24/11/16
 * Authors: Thomas Flynn
 */

#ifndef PLAYER_H//if header not defined
#define PLAYER_H//define it here
#include "Character.h"//include header file
#include "Inventory.h"//include header file
#include <iostream>//include library
#include <string>//include library

class Player : public Character //extends character
{
public://public constructors, attributes and member functions
    int gold;//attribute
    Player();//constructor
    Player(Character c);//constructor taking a character object as a parameter
    Player(const Player& orig);//copy constructor
    ~Player();//deconstructor

private:

};

#endif /* PLAYER_H */

