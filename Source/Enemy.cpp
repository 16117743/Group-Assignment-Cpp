/**
 * File: Enemy.cpp
 * Date: 24/11/16
 * Author: Thomas Flynn
 * Class Description:
 * Enemy class
 */
#include "Enemy.h"//include header file for enemy
Enemy::Enemy() //default constructor
{
    id = 'E';//assign identity
    int random = rand()%5;//generate a random val 0-4
    Character *c;//pointer of type character
    switch(random)//switch on random value
    {
        case 0://case human
            c = new Human();//character pointer points object on the heap
        break;//break statement
        case 1://case Elf
            c = new Elf();//character pointer points object on the heap
        break;//break statement
        case 2://case Dwarf
            c = new Dwarf();//character pointer points object on the heap
        break;//break statement
        case 3://case Hobbit
            c = new Hobbit();//character pointer points object on the heap
        break;//break statement
        case 4://case Orc
            c = new Orc();//character pointer points object on the heap
        break;//break statement
    }
    race = c->race;//assign attribute to newly constructed enemy
    atk = c->atk;//assign attribute to newly constructed enemy
    atkChance = c->atkChance;//assign attribute to newly constructed enemy
    def = c->def;//assign attribute to newly constructed enemy
    defChance = c->defChance;//assign attribute to newly constructed enemy
    health = c->health;//assign attribute to newly constructed enemy
    strength = c->strength;//assign attribute to newly constructed enemy
}

Enemy::Enemy(Character c)//constructor that takes a character object as an argument
{
    race = c.race;//assign attributes of the character passed into the constructor as a pointer
    atk = c.atk;//assign attributes of the character passed into the constructor as a pointer
    atkChance = c.atkChance;//assign attributes of the character passed into the constructor as a pointer
    def = c.def;//assign attributes of the character passed into the constructor as a pointer
    defChance = c.defChance;//assign attributes of the character passed into the constructor as a pointer
    health = c.health;//assign attributes of the character passed into the constructor as a pointer
    strength = c.strength;//assign attributes of the character passed into the constructor as a pointer
}

Enemy::Enemy(const Enemy& orig) {}//copy constructor

Enemy::~Enemy() {}//deconstructor

void Enemy::generateItemForEnemy()//generates a random item for the enemy
{
    int random = rand()%8;//generate random value between 0-7
    switch(random)//switch on randomly generated value
    {
        case 0:// sword
        {
            pickup(new Sword);//pass newly created object into enemy's pickup member function
        break;//break statement
        }
        case 1: // dagger
        {
            pickup(new Dagger);//pass newly created object into enemy's pickup member function
        break;//break statement
        }
        case 2: // leather
        {
            pickup(new PlateArmour);//pass newly created object into enemy's pickup member function
        break;//break statement
        }
        case 3: // plate
        {
            pickup(new LeatherArmour);//pass newly created object into enemy's pickup member function
        break;//break statement
        }
        case 4: // large shield
        {
            pickup(new LargeShield);//pass newly created object into enemy's pickup member function
        break;//break statement
        }
        case 5: // small shield
        {
            pickup(new SmallShield);//pass newly created object into enemy's pickup member function
        break;//break statement
        }
        case 6: // ring of strength
        {
            pickup(new RingOfStrength);//pass newly created object into enemy's pickup member function
        break;//break statement
        }
        case 7: // ring of life
        {
            pickup(new RingOfLife);//pass newly created object into enemy's pickup member function
        break; //break statement    
        }
    }//end switch(random)
}//generateItemForEnemy()


