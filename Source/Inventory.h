#ifndef INVENTORY_H
#define INVENTORY_H
#include "Item.h"
#include <vector> 
#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using std::vector;

class Inventory {
public:
   std::vector<Item*> wearables;
   Inventory();
   Inventory(const Inventory& orig);
   ~Inventory(); 
   bool addItem(Item * my_item);
   bool removeItem(int index);
   void printInventory();
   private: 
   std::map<std::string, int> my_item_counts;
};

#endif /* INVENTORY_H */

