#include "Player.h"

Player::Player() {
    id = 'P';
    gold = 0;
}

Player::Player(Character c) {
    race = c.race;
    atk = c.atk;
    atkChance = c.atkChance;
    def = c.def;
    defChance = c.defChance;
    health = c.health;
    strength = c.strength;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
    //std::cout<< "player destructor called" << std::endl;
}

void Player::pickup(Item *item) {
    inventory.addItem(item);
    //std::cout<< "character destructor called" << std::endl;
}

