#include "Item.h"

Item::Item() {
    id = 'I';
    weight = 0;
    atk = 0;
    def  = 0;
    health  = 0;
    strength  = 0;
    name  = "";
    type  = "";
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

//void Item::operator =(const Item item&) { 
//        weight = item.weight;
//        atk = item.atk;
//        def = item.def;
//        health = item.health;
//        strength = item.strength;
//        name = item.name;
//        type = item.type;
//    }

/**weapon constructor */
Weapon::Weapon() {
    type = "Weapon";
}

Weapon::Weapon(const Item& item){
        weight = item.weight;
        atk = item.atk;
        def = item.def;
        health = item.health;
        strength = item.strength;
        name = item.name;
        type = item.type;
}

/**weapon constructor */
Weapon::~Weapon() {
}

/**Sword class */
Sword::Sword() {
    weight = 10;
    atk = 10;
    name = "Sword";
}

Sword::~Sword(){
    
}

Dagger::Dagger(){
    weight = 5;
    atk = 5;
    name = "Dagger";
}
Dagger::~Dagger(){
    
}

Armour::Armour(){
    type = "Armour";
}
Armour::~Armour(){
    
}

Armour::Armour(const Item& item){
    weight = item.weight;
        atk = item.atk;
        def = item.def;
        health = item.health;
        strength = item.strength;
        name = item.name;
        type = item.type;
}

PlateArmour::PlateArmour(){
    weight = 40;
    def = 10;
    atk = -5;
    name = "Plate Armour";
}
PlateArmour::~PlateArmour(){
 
}

LeatherArmour::LeatherArmour(){
    weight = 20;
    def = 5;
    name = "Leather Armour";
}
LeatherArmour::~LeatherArmour(){
    
}
   
Shield::Shield(){
    type = "Shield";
}
Shield::~Shield(){
    
}

Shield::Shield(const Item& item){
    weight = item.weight;
        atk = item.atk;
        def = item.def;
        health = item.health;
        strength = item.strength;
        name = item.name;
        type = item.type;
}

SmallShield::SmallShield(){
    weight = 10;
    def = 5;
    name = "Small Shield";
}
SmallShield::~SmallShield(){
    
}

LargeShield::LargeShield(){
    weight = 30;
    def = 10;
    name = "Large Shield";
}
LargeShield::~LargeShield(){
    
}

Ring::Ring(){
    type = "Ring";
}

Ring::~Ring(){
    
}

Ring::Ring(const Item& item){
    weight = item.weight;
    atk = item.atk;
    def = item.def;
    health = item.health;
    strength = item.strength;
    name = item.name;
    type = item.type;
}

RingOfLife::RingOfLife(){
    weight = 0;
    health = 10;
    name = "Ring of Life";
}

RingOfLife::~RingOfLife(){
    
}

RingOfStrength::RingOfStrength(){
    strength = 50;
    health = -10;
    name = "Ring of Strength";
}

RingOfStrength::~RingOfStrength(){
    
}