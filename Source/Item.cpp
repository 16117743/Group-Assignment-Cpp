/**
 * File: Item.cpp
 * Date: 24/11/16
 * Author: Essa Alysami
 * Class Description:
 * Enemy class
 */
#include "Item.h"

Item::Item()//default constructor
 {
    id = 'I';//assign identity 'i'
}

Item::Item(Item *iPtr)//construtor taking a pointer to an item 
 {
    id = iPtr->id;//assign attributes to newly created item based on attributes pointer is pointing to
    weight = iPtr->weight;//assign attributes to newly created item based on attributes pointer is pointing to
    atk =  iPtr->atk;//assign attributes to newly created item based on attributes pointer is pointing to
    def  =  iPtr->def;//assign attributes to newly created item based on attributes pointer is pointing to
    health  =  iPtr->health;//assign attributes to newly created item based on attributes pointer is pointing to
    strength  =  iPtr->strength;//assign attributes to newly created item based on attributes pointer is pointing to
    name  =  iPtr->name;//assign attributes to newly created item based on attributes pointer is pointing to
    type  =  iPtr->type;//assign attributes to newly created item based on attributes pointer is pointing to
}

Item::Item(const Item& orig)//copy constructor
{
}

Item::~Item()//deconstructor
{
}

void Item::displayI()//displays item stats
{
    std::cout << "Item: " << name << std::endl;//print out item attributes
    std::cout << "Weight: " << weight <<std::endl;//print out item attributes
    std::cout << "Attack mod: " << atk <<std::endl;//print out item attributes
    std::cout << "Defence mod: " << def <<std::endl;//print out item attributes
    std::cout << "Health mod: " << health <<std::endl;//print out item attributes
    std::cout << "Strength mod: " << strength <<std::endl;//print out item attributes
}

/**weapon constructor */
Weapon::Weapon() // default constructor
{
    type = "Weapon";//assign newly created item attributes
}

Weapon::Weapon(const Item& item)//copy constructor
{
    weight = item.weight;//assign newly created item attributes
    atk = item.atk;//assign newly created item attributes
    def = item.def;//assign newly created item attributes
    health = item.health;//assign newly created item attributes
    strength = item.strength;//assign newly created item attributes
    name = item.name;//assign newly created item attributes
    type = item.type;//assign newly created item attributes
}

Weapon::~Weapon()//deconstructor
{
}

/**Sword class */
Sword::Sword()// default constructor
{
    weight = 10;//assign newly created item attributes
    atk = 10;//assign newly created item attributes
    name = "Sword";//assign newly created item attributes
}

Sword::~Sword()//deconstructor
{
    
}

Dagger::Dagger()// default constructor
{
    weight = 5;//assign newly created item attributes
    atk = 5;//assign newly created item attributes
    name = "Dagger";//assign newly created item attributes
}
Dagger::~Dagger()//deconstructor
{  
}

Armour::Armour()// default constructor
{
    type = "Armour";//assign newly created item attributes
}
Armour::~Armour()//deconstructor
{
}

Armour::Armour(const Item& item)//copy constructor
{
    weight = item.weight;//assign newly created item attributes
    atk = item.atk;//assign newly created item attributes
    def = item.def;//assign newly created item attributes
    health = item.health;//assign newly created item attributes
    strength = item.strength;//assign newly created item attributes
    name = item.name;//assign newly created item attributes
    type = item.type;//assign newly created item attributes
}

PlateArmour::PlateArmour()// default constructor
{
    weight = 40;//assign newly created item attributes
    def = 10;//assign newly created item attributes
    atk = -5;//assign newly created item attributes
    name = "Plate Armour";//assign newly created item attributes
}
PlateArmour::~PlateArmour()//deconstructor
{
}

LeatherArmour::LeatherArmour()// default constructor
{
    weight = 20;
    def = 5;
    name = "Leather Armour";//assign newly created item attributes
}
LeatherArmour::~LeatherArmour()//deconstructor
{
}
   
Shield::Shield()// default constructor
{
    type = "Shield";//assign newly created item attributes
}
Shield::~Shield()//deconstructor
{
}

Shield::Shield(const Item& item)//copy constructor
{
    weight = item.weight;//assign newly created item attributes
    atk = item.atk;//assign newly created item attributes
    def = item.def;//assign newly created item attributes
    health = item.health;//assign newly created item attributes
    strength = item.strength;//assign newly created item attributes
    name = item.name;//assign newly created item attributes
    type = item.type;//assign newly created item attributes
}

SmallShield::SmallShield()// default constructor
{
    weight = 10;//assign newly created item attributes
    def = 5;//assign newly created item attributes
    name = "Small Shield";//assign newly created item attributes
}
SmallShield::~SmallShield()//deconstructor
{
}

LargeShield::LargeShield()// default constructor
{
    weight = 30;//assign newly created item attributes
    def = 10;//assign newly created item attributes
    name = "Large Shield";//assign newly created item attributes
}
LargeShield::~LargeShield()//deconstructor
{
}

Ring::Ring()// default constructor
{
    type = "Ring";
}

Ring::~Ring()//deconstructor
{
}

Ring::Ring(const Item& item)//copy constructor
{
    weight = item.weight;//assign newly created item attributes
    atk = item.atk;//assign newly created item attributes
    def = item.def;//assign newly created item attributes
    health = item.health;//assign newly created item attributes
    strength = item.strength;//assign newly created item attributes
    name = item.name;//assign newly created item attributes
    type = item.type;//assign newly created item attributes
}

RingOfLife::RingOfLife()// default constructor
{
    weight = 0;//assign newly created item attributes
    health = 10;//assign newly created item attributes
    name = "Ring of Life";//assign newly created item attributes
}

RingOfLife::~RingOfLife()//deconstructor
{ 
}

RingOfStrength::RingOfStrength()// default constructor
{
    strength = 50;//assign newly created item attributes
    health = -10;//assign newly created item attributes
    name = "Ring of Strength";//assign newly created item attributes
}

RingOfStrength::~RingOfStrength()//deconstructor
{
    
}
