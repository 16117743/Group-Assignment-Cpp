#include "Character.h"

Character::Character() {
    //std::cout << "default character constructor" << std::endl;
   // id = "C";
}

Character::Character(int racesw){
    switch(racesw){
        case 0:
        {
            Human h1;
            race = h1.race;
            atk = h1.atk;
            atkChance = h1.atkChance;
            def = h1.def;
            defChance = h1.defChance;
            health = h1.health;
            strength = h1.strength;
            //cPtr = this;
        break;
        }
        case 1:
        {
            Elf el1;
            race = el1.race;
            atk = el1.atk;
            atkChance = el1.atkChance;
            def = el1.def;
            defChance = el1.defChance;
            health = el1.health;
            strength = el1.strength;
            //cPtr = this;
        break;
        }
        case 2:
        {
            Dwarf d1;
            race = d1.race;
            atk = d1.atk;
            atkChance = d1.atkChance;
            def = d1.def;
            defChance = d1.defChance;
            health = d1.health;
            strength = d1.strength;
            //cPtr = this;
        break;
        }
        case 3:
        {
            Hobbit ho1;
            race = ho1.race;
            atk = ho1.atk;
            atkChance = ho1.atkChance;
            def = ho1.def;
            defChance = ho1.defChance;
            health = ho1.health;
            strength = ho1.strength;
            //cPtr = this;
        break;
        }
        case 4:
        {
            Orc o1;
            race = o1.race;
            atk = o1.atk;
            atkChance = o1.atkChance;
            def = o1.def;
            defChance = o1.defChance;
            health = o1.health;
            strength = o1.strength;
            //cPtr = this;
        break;
        }
    }
}

Character::Character(const Character& orig){
    
}

Character::~Character() {
    //std::cout<< "character destructor called" << std::endl;
}

void Character::displayStats(){
    std::cout << "\n****Player Stats****\nRace: " << race;
    std::cout << "\nAttack: " << atk;
    std::cout << "\nAttack chance: " << atkChance;
    std::cout << "\nDefence: " << def;
    std::cout << "\nDefence chance: " << atk;
    std::cout << "\nHealth: " << health;
    std::cout << "\nStrength: " << strength << std::endl;
}

void Character::displayE(){
    std::cout << "Race: " << race;
    std::cout << "\nAttack: " << atk;
    std::cout << "\nAttack chance: " << atkChance;
    std::cout << "\nDefence: " << def;
    std::cout << "\nDefence chance: " << atk;
    std::cout << "\nHealth: " << health;
    std::cout << "\nStrength: " << strength << std::endl;
}


void Character::displayI(){
    std::cout << "Race: " << race;
    std::cout << "\nAttack: " << atk;
    std::cout << "\nAttack chance: " << atkChance;
    std::cout << "\nDefence: " << def;
    std::cout << "\nDefence chance: " << atk;
    std::cout << "\nHealth: " << health;
    std::cout << "\nStrength: " << strength << std::endl;
}

void Character::displayStats2(){
    inventory.printInventory();
}

bool Character::attack(Character *c){
    int atkRand = rand()%100;
    
    if(atkRand<atkChance)// attacker resolution
    {
        int defRand = rand()%100;
        if(defRand<c->defChance)//defender resolution
        {
            std::cout<< "successful defence!\n";
            //call defender trait member function
        }
        else{//defence failed
            std::cout<< "successful attack!\n";
            int atkAmount = atk - c->def; //difference between attackers value and defenders value
            if(atkAmount <0) //prevent defender from inflicting damage when defence is higher than attack
                atkAmount = 0;
            c->health = c->health - atkAmount;
            std::cout<< atkAmount << " damage dealt!\n";
        }
    return true;// attacker was successful    
    }//endif attack success
    std::cout<< "attack failed!\n";
    return false;//attacker was unsuccessful
}

bool Character::move(std::string direction) {
    //std::cout<< "character destructor called" << std::endl;
}

bool Character::pickup(Item *item) {
    if(strength >= item->weight){
        inventory.addItem(item);
        updateStats(item);
        return true;
    }
    else{
        return false;
    }
}

void Character::updateStats(Item *item){
    atk = atk+ item->atk;
    def = def + item->def;
    health = health + item->health;
    strength = strength - item->weight;//update strength using weight of item
}

/**Races */
Human::Human() {
    race = "Human";
    atk = 30;
    atkChance = 66;
    def = 20;
    defChance = 50;
    health = 60;
    strength = 100;
}

Human::~Human(){
    
}

Elf::Elf() {
    race = "Elf";
    atk = 40;
    atkChance = 100;
    def = 10;
    defChance = 25;
    health =  40;
    strength = 70;
}

Elf::~Elf(){
    
}

/**Dwarf constructor */
Dwarf::Dwarf() {
    race = "Dwarf";
    atk = 30;
    atkChance = 66;
    def = 20;
    defChance = 66;
    health = 50;
    strength = 130;
}

/**Dwarf destructor */
Dwarf::~Dwarf(){
    
}

/**Sword class */
Hobbit::Hobbit() {
    race = "Hobbit";
    atk = 25;
    atkChance = 33;
    def = 20;
    defChance = 66;
    health = 70;
    strength = 85;
}

Hobbit::~Hobbit(){
    
}

/**Sword class */
Orc::Orc() {
    race = "Orc";
    atk = 25;//45 night
    atkChance = 25;//100 night
    def = 10;//25 night
    defChance = 25;//50 night
    health = 50;
    strength = 130;
}

Orc::~Orc(){
    
}
