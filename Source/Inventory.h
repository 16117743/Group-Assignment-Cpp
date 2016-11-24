/**
 * File: Inventory.h
 * Date: 24/11/16
 * Authors: Thomas Flynn
 */
#ifndef INVENTORY_H//if header not defined
#define INVENTORY_H//define it here
#include "Item.h"//include header
#include <vector> //include library
#include <iostream>//include library
#include <map>//include library
#include <string>//include library
#include <iostream>//include library
#include <algorithm>//include library
#include <cstddef>//include library
#include <memory>//include library
#include <utility>//include library 
using std::vector; //using vector from std library

class Inventory 
{
public://public constructors, attributes and member functions
   std::vector<Item*> weapon;//vector of weapons
   std::vector<Item*> armour;//vector of armour
   std::vector<Item*> shield;//vector of shield
   std::vector<Item*> rings;//vector of rings
   Inventory();// default constructor
   Inventory(const Inventory& orig);//copy constructor
   ~Inventory(); //deconstructor
   bool addItem(Item * iPtr);//member function that takes a pointer to an item as argument and adds an item to inventory
   bool removeItem(int index);//member function that takes an index as argument and removes an item from inventory
   void printInventory();//member function to print inventory
   private://private constructors, attributes and member functions
};

#endif /* INVENTORY_H */

