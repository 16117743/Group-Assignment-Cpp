/**
 * File: Character.h
 * Date: 24/11/16
 * Authors: Thomas Flynn and Mashhour Alysami 
 */
#include "BoardObject.h"//include header file for 
#ifndef Character_h//if character header not defined
#define Character_h //define it here 
#include "Item.h"//include header file for Item.h
#include "Inventory.h"//include header file for Inventory.h
#include <iostream>//include library for iostream
#include <string>//include library for string
#include <ctime>//include library for ctime
 
using namespace std;//using std namespace

class Character : public BoardObject//character extends BoardObject
{
private://private attributes
    
public://public constructors, attributes and member functions
    /**Atributes*/
    string race;//attribute
    unsigned int health;//attribute
    unsigned int atk;//attribute
    unsigned int atkChance;//attribute
    unsigned int def;//attribute
    unsigned int defChance;//attribute
    unsigned int weight;//attribute
    unsigned int strength;//attribute
    Inventory inventory;//attribute of type inventory
    
    /**Constructors*/
    Character();//default constructor
    Character(int race);//constructor taking an int as an arg
    Character(const Character& orig);//copy constructor
    ~Character();//deconstructor

    /**member functions*/
    bool move(string direction);//function for moving character
    void drop(int index);//drops an item
    void attack(Character *c,bool daynight);//attacks a character
    void displayStats();//displays characters stats
    void displayStats2();//displays characters stats
    bool pickup(Item *item);//adds item to character inventory
    void updateStats(Item *item);//updates characters stats
    void displayI();//displays character's inventory
    void displayE();//displays character's inventory
    void updateOrcStats();//updates character's of type orc
};

/**Races*/
class Human : public Character //extends character
{
    public:
        //trait: SD never cause damage
    Human();//default constructor
    Human(const Human& orig);//copy constructor
    virtual ~Human();//virtual deconstructor
    private:
};

class Elf : public Character//extends character
 {
    public:
        //trait: SD always increases health by 1
    Elf();//default constructor
    Elf(const Elf& orig);//copy constructor
    virtual ~Elf();//virtual deconstructor
    private:
};
class Dwarf : public Character //extends character
{
    public:
        //trait: SD never cause damage
    Dwarf();//default constructor
    Dwarf(const Dwarf& orig);//copy constructor
    virtual ~Dwarf();//virtual deconstructor
    private:
};

class Hobbit : public Character //extends character
{
    public:
        //trait: SD causes 0-5 damage regardless of attack
    Hobbit();//default constructor
    Hobbit(const Hobbit& orig);//copy constructor
    virtual ~Hobbit();//virtual deconstructor
    private:
};

class Orc : public Character //extends character
{
    public:
        //trait: day / night time
    Orc();//default constructor
    Orc(const Orc& orig);//copy constructor
    virtual ~Orc();//virtual deconstructor
    private:
};

#endif 

