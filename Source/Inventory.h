#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector> 
#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstddef>
using std::vector;

class Inventory {
public:
   std::vector<Item*> wearables;
   Item* weapon;
   Item* armour;
   Item* shield;
   std::vector<Item*> rings;
   Inventory();
   Inventory(const Inventory& orig);
   ~Inventory(); 
   bool addItem(Item * item);
   bool removeItem(int index);
   void printInventory();
   private: 
};

#endif /* INVENTORY_H */

