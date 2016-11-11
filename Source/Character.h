#include "BoardObject.h"
#ifndef Character_h
#define Character_h  
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
    Character(int row, int col,char type);
    Character(const Character& orig);
    virtual ~Character();
};
#endif

