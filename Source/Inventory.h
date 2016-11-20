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
#include <memory>
#include <utility>  //declarations of unique_ptr
using std::vector;

class Inventory {
public:
   //std::vector<Item*> wearables;
   //std::unique_ptr<Item*> weapon;
  // std::unique_ptr<Item*> armour;
  // std::unique_ptr<Item*> shield;
//   Item* weapon;
//   Item* armour;
//   Item* shield;
   std::vector<Item*> weapon;
   std::vector<Item*> armour;
   std::vector<Item*> shield;
   std::vector<Item*> rings;
   Inventory();
   Inventory(const Inventory& orig);
   ~Inventory(); 
   bool addItem(Item * iPtr);
   bool removeItem(int index);
   void printInventory();
   private: 
};

#endif /* INVENTORY_H */

