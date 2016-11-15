#include "Inventory.h"


Inventory::Inventory() {
}

Inventory::Inventory(const Inventory& orig) {
}

Inventory::~Inventory() {
}

bool Inventory::addItem(Item * item) {
    if(item->type == "Weapon"){
       std::cout << "weapon!\n";
//        if(weapon == NULL)
           weapon = new Weapon(*item);
    }
    else if (item->type == "Armour"){
        std::cout << "armour!\n";
 //       if(armour == NULL)
           armour = new Armour(*item);
    }
    else if (item->type == "Shield"){
        std::cout << "shield!\n";
 //       if(shield == NULL)
           shield = new Shield(*item);
    }
    else if (item->type == "Ring"){
       std::cout << "ring!\n";
       rings.push_back(item);
    }
    return true;
}
 
bool Inventory::removeItem(int index) {
    wearables.erase(wearables.begin() + index);
    return true;
 }
 
void Inventory::printInventory() {
    std::cout << "*******Inventory***********" << std::endl;
    if(weapon != NULL){
        std::cout << "weapon: " << weapon->name << std::endl;
        std::cout << "weight: " << weapon->weight << std::endl;
        std::cout << "attack: " << weapon->atk << std::endl;
    }
    if(armour != NULL){
        std::cout << "weapon: " <<armour->name << std::endl;
        std::cout << "weight: " << armour->weight << std::endl;
        std::cout << "defence: " << armour->def << std::endl;
    }
    if(shield != NULL){
       std::cout << "weapon: " <<shield->name << std::endl;
       std::cout << "weight: " << shield->weight << std::endl;
       std::cout << "defence: " << shield->def << std::endl;
    }
    std::cout << "rings: " << std::endl;
    for(int i=0; i<rings.size(); ++i){
        std::cout << (i+1) << ") : " << rings[i]->name << std::endl;
        std::cout << "strength mod: " << rings[i]->strength << std::endl;
        std::cout << "health mod: " << rings[i]->health << std::endl;
    }
}

