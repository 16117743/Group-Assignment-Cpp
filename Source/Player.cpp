/**
 * File: Player.cpp
 * Date: 24/11/16
 * Author: Thomas Flynn
 * Class Description:
 * Provides functionality for players.
 */

#include "Player.h"//include header

Player::Player()//default constructor
{
    id = 'P';//assign attributes
    gold = 0;//assign attributes
}

Player::Player(Character c)//constructor taking a character object as an argument
 {
    id = 'P';//assign attributes
    gold = 0;//assign attributes
    race = c.race;//assign attributes
    atk = c.atk;//assign attributes
    atkChance = c.atkChance;//assign attributes
    def = c.def;//assign attributes
    defChance = c.defChance;//assign attributes
    health = c.health;//assign attributes
    strength = c.strength;//assign attributes
}

Player::Player(const Player& orig)//copy constructor
{
}

Player::~Player()//deconstructor
{
}



