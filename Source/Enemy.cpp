#include "Enemy.h"

Enemy::Enemy() {
    std::cout<< "Enemy constructor called" << std::endl;
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
    std::cout<< "Enemy destructor called" << std::endl;
}

