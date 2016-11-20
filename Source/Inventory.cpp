#include "Inventory.h"


Inventory::Inventory() {
}

Inventory::Inventory(const Inventory& orig) {
}

Inventory::~Inventory() {
}

bool Inventory::addItem(Item *iPtr) {
    //std::cout << "add item called!\n";
    std::cout << iPtr->name <<" added to inventory\n";
    if(iPtr->type == "Weapon"){
       std::cout << "weapon!\n";
        if(weapon.size()<1){
            weapon.push_back(new Item(iPtr));
            std::cout << "you now have a weapon\n";
        }
        else{
            //std::replace(weapon.begin(), weapon.end(), weapon[0], iPtr);
            std::cout << "previous weapon replaced\n";
        }
    }
    else if (iPtr->type == "Armour"){
        if(armour.size()<1){
           armour.push_back(new Item(iPtr));
           std::cout << "you now have armour\n";
        }
        else{
//            std::replace(armour.begin(), armour.end(), armour[0], iPtr);
            std::cout << "previous armour replaced\n";
        }
    }
    else if (iPtr->type == "Shield"){
        std::cout << "shield!\n";
        if(shield.size()<1){
            shield.push_back(new Item(iPtr));
            std::cout << "you now have a shield\n";
        }
        else{
            //std::replace(shield.begin(), shield.end(), shield[0], item);
            std::cout << "previous shield replaced\n";
        }
    }
    else if (iPtr->type == "Ring"){
       rings.push_back(new Item(iPtr));
       std::cout << "ring added\n";
    }
    return true;
}
 
bool Inventory::removeItem(int index) {
//    wearables.erase(wearables.begin() + index);
    return true;
 }
 
void Inventory::printInventory() {
    std::cout << "****Inventory****" << std::endl;
    if(weapon.size()>0){
//        std::cout << "weapon: " << weapon[0].name << std::endl;
//        std::cout << "weight: " << weapon[0].weight << std::endl;
//        std::cout << "attack: " << weapon[0].atk << std::endl;
        std::cout << "weapon: " << weapon[0]->name << std::endl;
        std::cout << "weight: " << weapon[0]->weight << std::endl;
        std::cout << "attack: " << weapon[0]->atk << std::endl;
    }
    if(armour.size()>0){
//        std::cout << "weapon: " <<armour[0].name << std::endl;
//        std::cout << "weight: " << armour[0].weight << std::endl;
//        std::cout << "defence: " << armour[0].def << std::endl;
        std::cout << "Armour: " <<armour[0]->name << std::endl;
        std::cout << "weight: " << armour[0]->weight << std::endl;
        std::cout << "defence: " << armour[0]->def << std::endl;
    }
    if(shield.size()>0){
//       std::cout << "Shield: " <<shield[0].name << std::endl;
//       std::cout << "weight: " << shield[0].weight << std::endl;
//       std::cout << "defence: " << shield[0].def << std::endl;
       std::cout << "Shield: " <<shield[0]->name << std::endl;
       std::cout << "weight: " << shield[0]->weight << std::endl;
       std::cout << "defence: " << shield[0]->def << std::endl;
    }
    std::cout << "Rings: \n" << std::endl;
    for(int i=0; i<rings.size(); ++i){
//        std::cout << (i+1) << ") : " << rings[i].name << std::endl;
//        std::cout << "strength mod: " << rings[i].strength << std::endl;
//        std::cout << "health mod: " << rings[i].health << std::endl;
        std::cout << (i+1) << ") : " << rings[i]->name << std::endl;
        std::cout << "strength mod: " << rings[i]->strength << std::endl;
        std::cout << "health mod: " << rings[i]->health << std::endl;
    }
}

