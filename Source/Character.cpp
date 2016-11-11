#include "Character.h"

Character::Character() {
    std::cout << "default character constructor" << std::endl;
   // id = "C";
}

Character::Character(int row, int col, char type) : BoardObject(row,col,type){
    std::cout << "2 arg character constructor" << std::endl;
}

Character::Character(const Character& orig){
    
}

Character::~Character() {
    std::cout<< "character destructor called" << std::endl;
}

