/**
 * File: Inventory.cpp
 * Date: 24/11/16
 * Author: Thomas Flynn
 * Class Description:
 * Provides functionality for characters to pickup and drop weapons from their inventory.
 */

#include "Inventory.h"//include header file for Inventory


Inventory::Inventory() {}//default constructor

Inventory::Inventory(const Inventory& orig) {}//copy constructor

Inventory::~Inventory() {}//deconstructor

bool Inventory::addItem(Item *iPtr)//takes a pointer to an item as an arg
{
    std::cout << iPtr->name << " added to inventory\nA(" <<iPtr->atk<< 
            ") W(" << iPtr->weight<<
            ") D(" << iPtr->def<<
            ") H(" << iPtr->health<<
            ") S(" << iPtr->strength<< ")" << std::endl;//print out

    if(iPtr->type == "Weapon"){
        if(weapon.size()<1){
            weapon.push_back(new Item(iPtr));
            std::cout << "you now have a weapon\n";//print out
        }
        else{
            std::cout << "previous weapon replaced\n";//print out
        }
    }
    else if (iPtr->type == "Armour"){
        if(armour.size()<1){
           armour.push_back(new Item(iPtr));
           std::cout << "you now have armour\n";//print out
        }
        else{
            std::cout << "previous armour replaced\n";//print out
        }
    }
    else if (iPtr->type == "Shield"){
        if(shield.size()<1){
            shield.push_back(new Item(iPtr));
            std::cout << "you now have a shield\n";//print out
        }
        else{
            std::cout << "previous shield replaced\n";//print out
        }
    }
    else if (iPtr->type == "Ring"){
       rings.push_back(new Item(iPtr));
       std::cout << "ring added\n";
    }
    return true;
}

//removes an item from inventory. 
bool Inventory::removeItem(int index)//arg = index of item to be dropped
{
    switch(index){
        case 1://weapon selected
            std::cout << "weapon dropped!\n";//print out
            weapon.erase(weapon.begin() + index);//erase rings in inventory
            break;//break statement
        case 2://armour selected
            std::cout << "armour dropped!\n";//print out
            armour.erase(armour.begin() + index);//erase rings in inventory
            break;//break statement
        case 3://shield selected
            std::cout << "shield dropped!\n";//print out
            shield.erase( shield.begin() + index);//erase rings in inventory
            break;//break statement
        case 4://ring selected
            std::cout << "rings dropped!\n";//print out
            rings.erase( rings.begin() + index);//erase rings in inventory
            break;//break statement
        default://default case
        break;//break statement
    }
    return true;
 }
 
void Inventory::printInventory() {
    std::cout << "****Inventory****" << std::endl;//print out
    if(weapon.size()>0)//if user has a weapon
    {
        std::cout << "weapon: " << weapon[0]->name << std::endl;//print out
        std::cout << "weight: " << weapon[0]->weight << std::endl;//print out
        std::cout << "attack: " << weapon[0]->atk << std::endl;//print out
    }
    if(armour.size()>0)//if user has armour
    {
        std::cout << "Armour: " <<armour[0]->name << std::endl;//print out
        std::cout << "weight: " << armour[0]->weight << std::endl;//print out
        std::cout << "defence: " << armour[0]->def << std::endl;//print out
    }
    if(shield.size()>0)//if user has a shield
    {
       std::cout << "Shield: " <<shield[0]->name << std::endl;//print out
       std::cout << "weight: " << shield[0]->weight << std::endl;//print out
       std::cout << "defence: " << shield[0]->def << std::endl;//print out
    }
    for(unsigned int i=0; i < rings.size(); ++i)//if user has a weapon
    {
        std::cout << (i+1) << ") : " << rings[i]->name << std::endl;//print out
        std::cout << "strength mod: " << rings[i]->strength << std::endl;//print out
        std::cout << "health mod: " << rings[i]->health << std::endl;//print out
    }
}

