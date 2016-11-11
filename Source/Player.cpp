#include "Player.h"

Player::Player() {
    std::cout<< "player constructor called" << std::endl;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
    std::cout<< "player destructor called" << std::endl;
}

