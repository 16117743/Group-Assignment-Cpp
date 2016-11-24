/**
 * File: Enemy.h
 * Date: 24/11/16
 * Authors: Thomas Flynn  
 */
#ifndef ENEMY_H//if header not defined
#define ENEMY_H//define it here
#include "Character.h"//include header
#include <iostream>//include library
#include <string>//include library
#include <ctime>//include library
class Enemy : public Character//extends character
{
public://public constructors, attributes and member functions
    Enemy();//default constructor
    Enemy(Character c);//constructor taking a character object as an argument
    Enemy(const Enemy& orig);//copy constructor
    Enemy(int row,int col);
    ~Enemy();//deconstructor
    void generateItemForEnemy();//generates an item for enemy
private://private constructors, attributes and member functions

};

#endif /* ENEMY_H */

