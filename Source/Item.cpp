#include "Item.h"

Item::Item() {
    id = 'I';
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

/**weapon constructor */
Weapon::Weapon() {
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

}
Armour::~Armour(){
    
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
    
}
Shield::~Shield(){
    
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
    
}

Ring::~Ring(){
    
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