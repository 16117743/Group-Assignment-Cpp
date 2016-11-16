#include "Enemy.h"

Enemy::Enemy() {
    //std::string temp = "E";
   // std::cout<< "Enemy constructor called" << std::endl;
    //id.assign("E");
}

Enemy::Enemy(Character c) {
    race = c.race;
    atk = c.atk;
    atkChance = c.atkChance;
    def = c.def;
    defChance = c.defChance;
    health = c.health;
    strength = c.strength;
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
   // std::cout<< "Enemy destructor called" << std::endl;
}

