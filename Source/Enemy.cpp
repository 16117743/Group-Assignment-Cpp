#include "Enemy.h"

Enemy::Enemy() {
    //std::string temp = "E";
   // std::cout<< "Enemy constructor called" << std::endl;
    //id.assign("E");
}

Enemy::Enemy(int row, int col) : Character (row,col, 'E'){
    std::cout << "2 arg enemy constructor" << std::endl;
}

Enemy::Enemy(const Enemy& orig) {
}

Enemy::~Enemy() {
   // std::cout<< "Enemy destructor called" << std::endl;
}

