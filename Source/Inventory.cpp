#include "Inventory.h"


Inventory::Inventory() {
}

Inventory::Inventory(const Inventory& orig) {
}

Inventory::~Inventory() {
}

 bool Inventory::addItem(Item * my_item) {
     wearables.push_back(my_item);
     return true;
 }
 
bool Inventory::removeItem(int index) {
    wearables.erase(wearables.begin() + index);
    return true;
 }
 
void Inventory::printInventory() {
    std::cout << "*******Inventory***********" << std::endl;
    for(int i=0; i<wearables.size(); ++i)
        std::cout << "[" << i << "] = " << wearables[i]->name << std::endl;
}

