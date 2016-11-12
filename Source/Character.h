#include "BoardObject.h"
#ifndef Character_h
#define Character_h  
#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Character : public BoardObject
{
private:
    
public:
    string type;
    int health;
    int atk;
    int atkChance;
    int def;
    int defChance;
    int weight;
    int strength;

    Character();
    Character(int row, int col,char type);
    Character(const Character& orig);
    ~Character();
    void move(string direction);
    Item pickup();
    void drop();
    void attack();
    void printInventory();
};

class Human : public Character {
    public:
        //trait: SD never cause damage
    Human();
    Human(const Human& orig);
    virtual ~Human();
    private:
};

class Elf : public Character {
    public:
        //trait: SD always increases health by 1
    Elf();
    Elf(const Elf& orig);
    virtual ~Elf();
    private:
};
class Dwarf : public Character {
    public:
        //trait: SD never cause damage
    Dwarf();
    Dwarf(const Dwarf& orig);
    virtual ~Dwarf();
    private:
};

class Hobbit : public Character {
    public:
        //trait: SD causes 0-5 damage regardless of attack
    Hobbit();
    Hobbit(const Hobbit& orig);
    virtual ~Hobbit();
    private:
};

class Orc : public Character {
    public:
        //trait: day / night time
    Orc();
    Orc(const Orc& orig);
    virtual ~Orc();
    private:
};

#endif

