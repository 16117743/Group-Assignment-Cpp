/**
 * File: Item.h
 * Date: 24/11/16
 * Authors: Thomas Flynn and Essa Alysami 
 */
#ifndef ITEM_H//if item header not defined
#define ITEM_H//define it here
#include "BoardObject.h"//include header for BoardObject
#include <string>//include library for string
#include <iostream>//include library for iostream
#include <ctime>//include library for ctime

class Item : public BoardObject //estends BoardObject
{
public://public constructors, attributes and member functions
    /**Attributes*/
    unsigned int weight;//attribute
    unsigned int atk;//attribute
    unsigned int def;//attribute
    unsigned int health;//attribute
    unsigned int strength;//attribute
    std::string name;//attribute
    std::string type;//attribute
    /**Constructors*/
    Item();
    Item(const Item& orig);
    Item(Item *iPtr);
    virtual ~Item();

    /**Member functions*/
    void displayI();//prints item information
    void displayE();//prints item information
    private://private constructors, attributes and member functions

};

class Weapon : public Item//extends item
{
    public:
    Weapon();//default constructor
    Weapon(const Item& orig);//copy constructor
    virtual ~Weapon();//virtual deconstructor
    private:
};

class Sword : public Weapon 
{
    public:
    Sword();//default constructor
    Sword(const Item& orig);//copy constructor
    virtual ~Sword();//virtual deconstructor
    private:
};

class Dagger : public Weapon 
{
    public:
    Dagger();//default constructor
    Dagger(const Item& orig);//copy constructor
    virtual ~Dagger();//virtual deconstructor
    private:
};

class Armour : public Item //extends item
{
    public:
    Armour();//default constructor
    Armour(const Item& orig);//copy constructor
    virtual ~Armour();//virtual deconstructor
    private:
};

class PlateArmour : public Armour 
{
    public:
    PlateArmour();//default constructor
    PlateArmour(const Item& orig);//copy constructor
    virtual ~PlateArmour();//virtual deconstructor
    private:
};

class LeatherArmour : public Armour 
{
    public:
    LeatherArmour();//default constructor
    LeatherArmour(const Item& orig);//copy constructor
    virtual ~LeatherArmour();//virtual deconstructor
    private:
};

class Shield : public Item//extends item
{
    public:
    Shield();//default constructor
    Shield(const Item& orig);//copy constructor
    virtual ~Shield();//virtual deconstructor
    private:
};

class SmallShield : public Shield //extends item
{
    public:
    SmallShield();//default constructor
    SmallShield(const Item& orig);//copy constructor
    virtual ~SmallShield();//virtual deconstructor
    private:
};

class LargeShield : public Shield //extends item
{
    public:
    LargeShield();//default constructor
    LargeShield(const Item& orig);//copy constructor
    virtual ~LargeShield();//virtual deconstructor
    private:
};

class Ring : public Item //extends item
{
    public:
        
    Ring();//default constructor
    Ring(const Item& orig);//copy constructor
    virtual ~Ring();//virtual deconstructor
    private:
};

class RingOfLife : public Ring //extends item
{
    public:
    RingOfLife();//default constructor
    RingOfLife(const Item& orig);//copy constructor
    virtual ~RingOfLife();//virtual deconstructor
    private:
};

class RingOfStrength : public Ring //extends item
{
    public:
    RingOfStrength();//default constructor
    RingOfStrength(const Item& orig);//copy constructor
    virtual ~RingOfStrength();//virtual deconstructor
    private:
};

#endif /* ITEM_H */

