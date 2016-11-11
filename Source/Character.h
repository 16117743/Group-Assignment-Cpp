#ifndef Character_h
#define Character_h  
#include "BoardObject.h"
#include <iostream>
#include <string>

using namespace std;

class Character : public BoardObject
{
private:
    
public:
    string name;
    int health;
    int attack;
    int defence;
    int weight;
    int strength;

    Character();
};
#endif

