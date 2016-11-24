/**
 * File: Character.cpp
 * Date: 24/11/16
 * Authors: Thomas Flynn and Mashhour Alysami
 * Class Description:
 * Character class 
 */
#include "Character.h"

Character::Character() {
}

//Constructor
Character::Character(int racesw)//arg = value used to determine which race to choose
{
    switch(racesw)//switch on value entered by user 
    {
        case 0://case human
        {
            Human h1;//create local scope object of type human
            race = h1.race;//character object is assigned the same traits of locally created object
            atk = h1.atk;//character object is assigned the same traits of locally created object
            atkChance = h1.atkChance;//character object is assigned the same traits of locally created object
            def = h1.def;//character object is assigned the same traits of locally created object
            defChance = h1.defChance;//character object is assigned the same traits of locally created object
            health = h1.health;//character object is assigned the same traits of locally created object
            strength = h1.strength;//character object is assigned the same traits of locally created object
            break;//break statement
        }
        case 1://case Elf
        {
            Elf el1;//create local scope object of type elf
            race = el1.race;//character object is assigned the same traits of locally created object
            atk = el1.atk;//character object is assigned the same traits of locally created object
            atkChance = el1.atkChance;//character object is assigned the same traits of locally created object
            def = el1.def;//character object is assigned the same traits of locally created object
            defChance = el1.defChance;//character object is assigned the same traits of locally created object
            health = el1.health;//character object is assigned the same traits of locally created object
            strength = el1.strength;//character object is assigned the same traits of locally created object
            break;//break statement
        }
        case 2://case dwarf
        {
            Dwarf d1;//create local scope object of type dwarf
            race = d1.race;//character object is assigned the same traits of locally created object
            atk = d1.atk;//character object is assigned the same traits of locally created object
            atkChance = d1.atkChance;//character object is assigned the same traits of locally created object
            def = d1.def;//character object is assigned the same traits of locally created object
            defChance = d1.defChance;//character object is assigned the same traits of locally created object
            health = d1.health;//character object is assigned the same traits of locally created object
            strength = d1.strength;//character object is assigned the same traits of locally created object
            break;//break statement
        }
        case 3://case hobbit
        {
            Hobbit ho1;//create local scope object of type hobbit
            race = ho1.race;//character object is assigned the same traits of locally created object
            atk = ho1.atk;//character object is assigned the same traits of locally created object
            atkChance = ho1.atkChance;//character object is assigned the same traits of locally created object
            def = ho1.def;//character object is assigned the same traits of locally created object
            defChance = ho1.defChance;//character object is assigned the same traits of locally created object
            health = ho1.health;//character object is assigned the same traits of locally created object
            strength = ho1.strength;//character object is assigned the same traits of locally created object
            break;//break statement
        }
        case 4://case orc
        {
            Orc o1;//create local scope object of type orc
            race = o1.race;//character object is assigned the same traits of locally created object
            atk = o1.atk;//character object is assigned the same traits of locally created object
            atkChance = o1.atkChance;//character object is assigned the same traits of locally created object
            def = o1.def;//character object is assigned the same traits of locally created object
            defChance = o1.defChance;//character object is assigned the same traits of locally created object
            health = o1.health;//character object is assigned the same traits of locally created object
            strength = o1.strength;//character object is assigned the same traits of locally created object
            break;//break statement
        }
    }
}

Character::Character(const Character& orig){}//copy constructor
Character::~Character() {}//deconstructor

void Character::displayStats()//display attributes of the character
{
    std::cout << "Race(" << race << ") A(" << atk << ") AC(" << atkChance <<
            ") D(" << def << ") DC(" << defChance << 
            ") H(" << health << ") S(" << strength << ")\n";
}

void Character::displayE()
{
    std::cout << "Race: " << race;//print out
    std::cout << "\nAttack: " << atk;//print out
    std::cout << "\nAttack chance: " << atkChance;//print out
    std::cout << "\nDefence: " << def;//print out
    std::cout << "\nDefence chance: " << atk;//print out
    std::cout << "\nHealth: " << health;//print out
    std::cout << "\nStrength: " << strength << std::endl;//print out
}

void Character::displayI()
{
    std::cout << "Race: " << race;//print out
    std::cout << "\nAttack: " << atk;//print out
    std::cout << "\nAttack chance: " << atkChance;//print out
    std::cout << "\nDefence: " << def;//print out
    std::cout << "\nDefence chance: " << defChance;//print out
    std::cout << "\nHealth: " << health;//print out
    std::cout << "\nStrength: " << strength << std::endl;//print out
}

void Character::displayStats2()
{
    inventory.printInventory();
}

void Character::updateOrcStats()//called to update Orc's attributes after stats changing due to day or night
{
    if(this->inventory.weapon.size()>0)//if the character has a weapon then update traits
    {
        this->strength-= this->inventory.weapon[0]->weight;//update traits
        this->atk+= this->inventory.weapon[0]->atk;//update traits
        this->def+= this->inventory.weapon[0]->def;//update traits
        this->health+= this->inventory.weapon[0]->health;//update traits
    }
    if(this->inventory.armour.size()>0)
    {
        this->strength-= this->inventory.armour[0]->weight;//update traits
        this->atk+= this->inventory.armour[0]->atk;//update traits
        this->def+= this->inventory.armour[0]->def;//update traits
        this->health+= this->inventory.armour[0]->health;//update traits
    }
    if(this->inventory.shield.size()>0)
    {
        this->strength-= this->inventory.shield[0]->weight;//update traits
        this->atk+= this->inventory.shield[0]->atk;//update traits
        this->def+= this->inventory.shield[0]->def;//update traits
        this->health+= this->inventory.shield[0]->health;//update traits
    }
    for(unsigned int i=0; i< this->inventory.rings.size(); ++i)
    {
        this->strength-= this->inventory.rings[0]->weight;//update traits
        this->atk+= this->inventory.rings[0]->atk;//update traits
        this->def+= this->inventory.rings[0]->def;//update traits
        this->health+= this->inventory.rings[0]->health;//update traits
    }
}//updateOrcStats

void Character::attack(Character *c, bool daynight)//args = defendingCharacter pointer, boolean that signals day or night
{
    if(c->race == "Orc")//if defending character is an orc
    {
        if(daynight==true)//Defending Orc's day time stats has to be updated
        {
            c->race = "Orc";//assign defending orc's attributes
            c->atk = 25;//assign defending orc's attributes
            c->atkChance = 25;//assign defending orc's attributes
            c->def = 10;//assign defending orc's attributes
            c->defChance = 25;//assign defending orc's attributes
            c->strength = 130;//assign defending orc's attributes
            c->updateOrcStats();//calls character member function that factors in item's carried 
        }
        else if(daynight==false)//Defending Orc's night time stats has to be updated
        {
            c->atk = 45;//assign defending orc's attributes
            c->atkChance = 100;//assign defending orc's attributes
            c->def = 25;//assign defending orc's attributes
            c->defChance = 50;//assign defending orc's attributes
            c->strength = 130;//assign defending orc's attributes
            c->updateOrcStats();//calls character member function that factors in item's carried 
        }
    }
    if(this->race == "Orc")//if attacking character is an orc
    {
        if(daynight==true)//if it is day time
        {
            this->race = "Orc";//assign attacking orc's attributes
            this->atk = 25;//assign attacking orc's attributes
            this->atkChance = 25;//assign attacking orc's attributes
            this->def = 10;//assign attacking orc's attributes
            this->defChance = 25;//assign attacking orc's attributes
            this->strength = 130;//assign attacking orc's attributes
            this->updateOrcStats();//assign attacking orc's attributes
        }
        else if(daynight==false)//if it is night time
        {
            this->atk = 45;//assign attacking orc's attributes
            this->atkChance = 100;//assign attacking orc's attributes
            this->def = 25;//assign attacking orc's attributes
            this->defChance = 50;//assign attacking orc's attributes
            this->strength = 130;//assign attacking orc's attributes
            this->updateOrcStats();//assign attacking orc's attributes
        }
    }
    unsigned int atkRand = rand()%100;//assign atkRand the remainder of the randomly generated number, mod 100 
    if(atkRand < atkChance)// if atkRand is less than the attacker's attack chance 
    {
        unsigned int defRand = rand()%100;//assign defRand the remainder of the randomly generated number, mod 100 
        unsigned int randDmg = rand()%6;//generate 0-5 random damage for the hobbit special ability
        if(defRand < c->defChance)//defender resolution 
        {
            std::cout<< "successful defence!\n";//print out
            if(c->race == "Human")//if defender is human
            {
                std::cout<< "Human ability activated!\nno damage dealt\n";//print out
            }
            else if(c->race == "Elf")//if defender is elf
            {
		unsigned int increase = 1;
                c->health+= increase;//increase elf's health by 1
                std::cout<< "Defending Elf ability activated!\nhealth increased by 1\n";//print out
            }
            else if(c->race == "Dwarf")//if defender is dwarf
            {
                std::cout<< "Defending Dwarf ability activated!\nno damage dealt\n";//print out
            }
            else if(c->race == "Hobbit")//if defender is hobbit
            {
                c->health -= randDmg;//damage dealt to defending hobbit is limited to 0-5
                std::cout<< "Defending Hobbit ability activated!\n0-5 random damage inflicted\ndmg inflicted =" << randDmg <<std::endl;//print out
            }
            else if(c->race == "Orc")//if defender is orc
            {
                std::cout<< "Defending Orc\n";//print out
                if(daynight==true)//if it is daytime
                    std::cout<< "day ";//print out
                else if(daynight==false)//if it night time
                    std::cout<<"night ";//print out
                std::cout<<"time ability activated!\n";//print out
                
                if(daynight==true)//if it is daytime
                {
                    int dmgAmount = atk - c->def; //difference between attackers value and defenders value
                    if(dmgAmount <0) //if defender's defence is higher than attack
                        dmgAmount = 0;//prevent defender from inflicting damage when defence is higher than attack
                    c->health = c->health - (dmgAmount*(3/4));//damage inflicted is offset by 1/4
                }
                else if(daynight==false)//if it night time
                {
		    unsigned int increase = 1;
                    c->health+=increase ;//increase defending orc's health by 1
                }
                
                }
        }// if defender blocks
        else if (defRand>= c->defChance)//defender fails to block
        {
            std::cout<< "successful attack!\n";//print out
            unsigned int dmgAmount = atk - c->def; //difference between attackers value and defenders value
            if(dmgAmount <0) //if defender's defence is higher than attack
                dmgAmount = 0;//prevent defender from inflicting damage when defence is higher than attack
            c->health = c->health - dmgAmount;//deduct defender's health
            std::cout<< dmgAmount << " damage dealt!\n";//print out
        }
    }//endif attack success
}//end attack()

void Character::drop(int choice)//args = choice of weapon chosen
{
    switch(choice)//switch on choice 
    {
        case 1://case weapon sword
            if(inventory.weapon.size()==1)//if the user already has a weapon
            {
                std::cout << "weapon dropped\n";//print out
                inventory.weapon.erase(inventory.weapon.begin()+0);//erase weapon that the inventory object has
            }
            else{
                std::cout << "you don't have a weapon to drop\n";//print out
            }
            break;//break statement
        case 2:
            if(inventory.armour.size()==1)//if the user already has a
            {
                std::cout << "Armour dropped\n";//print out
                inventory.armour.erase (inventory.armour.begin()+0);//erase armour that the inventory object has
            }
            else{
                std::cout << "you don't have armour to drop\n";//print out
            }
            break;//break statement
        case 3:
            if(inventory.shield.size()==1)//if the user already has a shield
            {
                std::cout << "Shield dropped\n";//print out
                inventory.shield.erase (inventory.shield.begin()+0);//erase shield that the inventory object has
            }
            else{
                std::cout << "you don't have a shield to drop\n";//print out
            }
            break;//break statement
        case 4:
            if(inventory.rings.size()==1)//if the user already has a ring
            {
                std::cout << "Rings dropped\n";//print out
                inventory.rings.erase (inventory.rings.begin()+0);//erase shield that the inventory object has
            }
            else if(inventory.rings.size()==2)//if the user already has rings
            {
                std::cout << "Rings dropped\n";//print out
                inventory.rings.erase (inventory.rings.begin()+0);//erase shield that the inventory object has
                inventory.rings.erase (inventory.rings.begin()+1);//erase shield that the inventory object has
            }
            else if(inventory.rings.size()==3)//if the user already has a rings
            {
                inventory.rings.erase (inventory.rings.begin()+0);//erase shield that the inventory object has
                inventory.rings.erase (inventory.rings.begin()+1);//erase shield that the inventory object has
                inventory.rings.erase (inventory.rings.begin()+2);//erase shield that the inventory object has
            }
            else{
                std::cout << "you don't have rings to drop\n";//print out
            }
            break;//break statement
    }//end switch(choice)
}//end drop

bool Character::pickup(Item *item)//args = pointer to item picked up
{
    if(strength >= item->weight)//if strength greater than weight
    {
        inventory.addItem(item);//pass pointer to inventory addItem member function
        updateStats(item);//item decrease the weight of the player and adjusts attributes
        return true;//return true if successful
    }
    else{
        return false;//failed to pick up item, not enough strength
    }
}//end pick up

void Character::updateStats(Item *item)//args = pointer to object character picked up
{
    atk = atk+ item->atk;//update character's attributes
    def = def + item->def;//update character's attributes
    health = health + item->health;//update character's attributes
    strength = strength - item->weight;//update strength using weight of item
}//end UpdateStats

/**Races */
Human::Human()//default constructor for human
{   
    race = "Human";//assign newly constructed object a value
    atk = 30;//assign newly constructed object a value
    atkChance = 66;//assign newly constructed object a value
    def = 20;//assign newly constructed object a value
    defChance = 50;//assign newly constructed object a value
    health = 60;//assign newly constructed object a value
    strength = 100;//assign newly constructed object a value
}

Human::~Human(){ }//deconstuctor

Elf::Elf() //default constructor for elf 
{
    race = "Elf";//assign newly constructed object a value
    atk = 40;//assign newly constructed object a value
    atkChance = 100;//assign newly constructed object a value
    def = 10;//assign newly constructed object a value
    defChance = 25;//assign newly constructed object a value
    health =  40;//assign newly constructed object a value
    strength = 70;//assign newly constructed object a value
}

Elf::~Elf(){}//deconstuctor

Dwarf::Dwarf()//default constructor for dwarf 
{
    race = "Dwarf";//assign newly constructed object a value
    atk = 30;//assign newly constructed object a value
    atkChance = 66;//assign newly constructed object a value
    def = 20;//assign newly constructed object a value
    defChance = 66;//assign newly constructed object a value
    health = 50;//assign newly constructed object a value
    strength = 130;//assign newly constructed object a value
}

Dwarf::~Dwarf(){}//deconstuctor

/**Sword class */
Hobbit::Hobbit()//default constructor for hobbit 
{
    race = "Hobbit";//assign newly constructed object a value
    atk = 25;//assign newly constructed object a value
    atkChance = 33;//assign newly constructed object a value
    def = 20;//assign newly constructed object a value
    defChance = 66;//assign newly constructed object a value
    health = 70;//assign newly constructed object a value
    strength = 85;//assign newly constructed object a value
}

Hobbit::~Hobbit(){}////deconstuctor

/**Sword class */
Orc::Orc()//default constructor for orc
{
    race = "Orc";//assign newly constructed object a value
    atk = 25;//assign newly constructed object a value
    atkChance = 25;//assign newly constructed object a value
    def = 10;//assign newly constructed object a value
    defChance = 25;//assign newly constructed object a value
    health = 50;//assign newly constructed object a value
    strength = 130;//assign newly constructed object a value
}

Orc::~Orc(){}//deconstuctor
