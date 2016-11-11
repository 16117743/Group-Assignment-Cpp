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
}

Sword::~Sword(){
    
}

Dagger::Dagger(){
    weight = 5;
    atk = 5;
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
}
PlateArmour::~PlateArmour(){
 
}

LeatherArmour::LeatherArmour(){
    weight = 20;
    def = 5;
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
}
SmallShield::~SmallShield(){
    
}

LargeShield::LargeShield(){
    weight = 30;
    def = 10;
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
}

RingOfLife::~RingOfLife(){
    
}

RingOfStrength::RingOfStrength(){
    strength = 50;
    health = -10;
}

RingOfStrength::~RingOfStrength(){
    
}