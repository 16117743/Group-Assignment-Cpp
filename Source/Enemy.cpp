#include "Enemy.h"

Enemy::Enemy() {
    id = 'E';
    int random = rand()%5;
    Character *c;
    switch(random){
        case 0:
            c = new Human();
        break;
        case 1:
            c = new Elf();
        break;
        case 2:
            c = new Dwarf();
        break;
        case 3:
            c = new Hobbit();
        break;
        case 4:
            c = new Orc();
        break;
    }
    race = c->race;
    atk = c->atk;
    atkChance = c->atkChance;
    def = c->def;
    defChance = c->defChance;
    health = c->health;
    strength = c->strength;
}

Enemy::Enemy(Character c) {
    race = c.race;
    atk = c.atk;
    atkChance = c.atkChance;
    def = c.def;
    defChance = c.defChance;
    health = 15;
    //health = c.health;
    strength = c.strength;
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
   // std::cout<< "Enemy destructor called" << std::endl;
}

void Enemy::generateItemForEnemy(){
    int random = rand()%8;
    switch(random)
    {
        case 0:
        {// sword
            pickup(new Sword);
        break;
        }
        case 1: // dagger
        {
            pickup(new Dagger);
        break;
        }
        case 2: // leather
        {
            pickup(new PlateArmour);
        break;
        }
        case 3: // plate
        {
            pickup(new LeatherArmour);
        break;
        }
        case 4: // large shield
        {
            pickup(new LargeShield);
        break;
        }
        case 5: // small shield
        {
            pickup(new SmallShield);
        break;
        }
        case 6: // ring of str
        {
            pickup(new RingOfStrength);
        break;
        }
        case 7: // ring of life
        {
            pickup(new RingOfLife);
        break;          
        }
    }
}


