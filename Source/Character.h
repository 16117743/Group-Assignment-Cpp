#include "BoardObject.h"
#ifndef Character_h
#define Character_h  
#include <iostream>
#include <string>
#include "Item.h"
#include <ctime>
#include "Inventory.h"
using namespace std;

class Character : public BoardObject
{
private:
    
public:
    string race;
    int health;
    int atk;
    int atkChance;
    int def;
    int defChance;
    int weight;
    int strength;
    Inventory inventory;
    
    Character();
    Character(int race);
    Character(const Character& orig);
    ~Character();
    bool move(string direction);
    void drop();
    bool attack(Character &c);
    void displayStats();
    bool pickup(Item *item);
    void updateStats(Item *item);
    //void printInventory();
};

/*Races*/

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

