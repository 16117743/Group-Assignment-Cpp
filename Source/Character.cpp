#include "Character.h"

Character::Character() {
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
    std::cout << "Race(" << race << ") A(" << atk << ") AC(" << atkChance <<
            ") D(" << def << ") DC(" << defChance << 
            ") H(" << health << ") S(" << strength << ")\n";
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
    std::cout << "\nDefence chance: " << defChance;
    std::cout << "\nHealth: " << health;
    std::cout << "\nStrength: " << strength << std::endl;
}

void Character::displayStats2(){
    inventory.printInventory();
}

void Character::updateOrcStats(){
    //std::cout << "1- Orc\n";
    //displayStats();
    //std::cout << "2- Orc\n";
    if(this->inventory.weapon.size()>0){
        this->strength-= this->inventory.weapon[0]->weight;
        this->atk+= this->inventory.weapon[0]->atk;
        this->def+= this->inventory.weapon[0]->def;
        this->health+= this->inventory.weapon[0]->health;
    }
    if(this->inventory.armour.size()>0){
        this->strength-= this->inventory.armour[0]->weight;
        this->atk+= this->inventory.armour[0]->atk;
        this->def+= this->inventory.armour[0]->def;
        this->health+= this->inventory.armour[0]->health;
    }
    if(this->inventory.shield.size()>0){
        this->strength-= this->inventory.shield[0]->weight;
        this->atk+= this->inventory.shield[0]->atk;
        this->def+= this->inventory.shield[0]->def;
        this->health+= this->inventory.shield[0]->health;
    }
    //std::cout << "Rings: \n" << std::endl;
    for(int i=0; i< this->inventory.rings.size(); ++i){
        this->strength-= this->inventory.rings[0]->weight;
        this->atk+= this->inventory.rings[0]->atk;
        this->def+= this->inventory.rings[0]->def;
        this->health+= this->inventory.rings[0]->health;
    }
    //std::cout << "3- Orc\n";
}

void Character::attack(Character *c, bool daynight){
    int atkRand = rand()%100;
    
    if(c->race == "Orc")
    {
        if(daynight==true){
            //std::cout << "Defending Orc's day time stats have been updated\n";
            c->race = "Orc";
            c->atk = 25;//45 night
            c->atkChance = 25;//100 night
            c->def = 10;//25 night
            c->defChance = 25;//50 night
            c->strength = 130;
            c->updateOrcStats();
        }
        else if(daynight==false){
           // std::cout << "Defending Orc's night time stats have been updated\n";
            c->atk = 45;
            c->atkChance = 100;
            c->def = 25;
            c->defChance = 50;
            c->strength = 130;
            c->updateOrcStats();
        }
    }
    if(this->race == "Orc")
    {
        if(daynight==true)
        {
            this->race = "Orc";
            this->atk = 25;//45 night
            this->atkChance = 25;//100 night
            this->def = 10;//25 night
            this->defChance = 25;//50 night
            this->strength = 130;
            this->updateOrcStats();
        }
        else if(daynight==false)
        {
          // std::cout << "Attacking Orc's night time stats have been updated\n";
            this->atk = 45;
            this->atkChance = 100;
            this->def = 25;
            this->defChance = 50;
            this->strength = 130;
            this->updateOrcStats();
        }
    }
    
    if(atkRand<atkChance)// attacker resolution
    {
        int defRand = rand()%100;
        int randDmg = rand()%6;
        if(defRand < c->defChance)//defender resolution
        {
            std::cout<< "successful defence!\n";
            if(c->race == "Human"){
                std::cout<< "Human ability activated!\nno damage dealt\n";
            }
            else if(c->race == "Elf"){
                c->health+=1;
                std::cout<< "Defending Elf ability activated!\nhealth increased by 1\n";
            }
            else if(c->race == "Dwarf"){
                std::cout<< "Defending Dwarf ability activated!\nno damage dealt\n";
            }
            else if(c->race == "Hobbit"){
                c->health -= randDmg;
                std::cout<< "Defending Hobbit ability activated!\n0-5 random damage inflicted\ndmg inflicted =" << randDmg <<std::endl;
            }
            else if(c->race == "Orc")
            {
                std::cout<< "Defending Orc\n";
                if(daynight==true)
                    std::cout<< "day ";
                else if(daynight==false)
                    std::cout<<"night ";
                std::cout<<"time ability activated!\n";
                
                if(daynight==true){
                    int dmgAmount = atk - c->def; //difference between attackers value and defenders value
                    if(dmgAmount <0) //prevent defender from inflicting damage when defence is higher than attack
                        dmgAmount = 0;
                    c->health = c->health - (dmgAmount/4);
                }
                else if(daynight==false){
                    c->health = c->health+=1;//increase defending orc's health by 1
                }
                
                }
        }// if defender blocks
        else if (defRand>= c->defChance)//defender fails to block
        {
            std::cout<< "successful attack!\n";
            int dmgAmount = atk - c->def; //difference between attackers value and defenders value
            if(dmgAmount <0) //prevent defender from inflicting damage when defence is higher than attack
                dmgAmount = 0;
            c->health = c->health - dmgAmount;
            std::cout<< dmgAmount << " damage dealt!\n";
        }
    }//endif attack success
}

bool Character::move(std::string direction) {
    //std::cout<< "character destructor called" << std::endl;
}

void Character::drop(int choice){
    switch(choice){
        case 1:
            if(inventory.weapon.size()==1){
                std::cout << "Sword dropped\n";
                inventory.rings.erase(inventory.rings.begin()+0);
            }
            else{
                std::cout << "you don't have a weapon to drop\n";
            }
            break;
        case 2:
            if(inventory.armour.size()==1){
                std::cout << "Armour dropped\n";
                inventory.armour.erase (inventory.armour.begin()+0);
            }
            else{
                std::cout << "you don't have armour to drop\n";
            }
            break;
        case 3:
            if(inventory.shield.size()==1){
                std::cout << "Shield dropped\n";
                inventory.shield.erase (inventory.shield.begin()+0);
            }
            else{
                std::cout << "you don't have a shield to drop\n";
            }
            break;
        case 4:
            if(inventory.rings.size()==1){
                std::cout << "Rings dropped\n";
                inventory.rings.erase (inventory.rings.begin()+0);
            }
            else if(inventory.rings.size()==2){
                std::cout << "Rings dropped\n";
                inventory.rings.erase (inventory.rings.begin()+0);
                inventory.rings.erase (inventory.rings.begin()+1);
            }
            else if(inventory.rings.size()==3){
                inventory.rings.erase (inventory.rings.begin()+0);
                inventory.rings.erase (inventory.rings.begin()+1);
                inventory.rings.erase (inventory.rings.begin()+2);
            }
            else{
                std::cout << "you don't have rings to drop\n";
            }
            break;
    }
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
