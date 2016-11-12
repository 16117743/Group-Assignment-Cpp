#include "Player.h"

Player::Player() {
    //std::cout<< "player constructor called" << std::endl;
    //std::string temp = "P";
   // std::cout<< "Enemy constructor called" << std::endl;
    id = 'P';
}

Player::Player(int row, int col) : Character (row,col, 'P'){ //calling base constructor
    //std::cout << "2 arg player constructor" << std::endl;
}

Player::Player(const Player& orig) {
}

Player::~Player() {
    //std::cout<< "player destructor called" << std::endl;
}

