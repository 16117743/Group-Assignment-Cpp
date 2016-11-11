/* 
 * File:   Character.h
 * Author: tom
 *
 * Created on 10 November 2016, 23:40
 */

#ifndef Character_h

#define Character_h  

#include <iostream>

using namespace std;

class Character
{
public:
string name;
int health;
int attack;
int defence;
int weight;
int strength;

Character(string newName);
};
#endif

