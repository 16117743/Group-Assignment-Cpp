#include "BoardObject.h"
#include "Character.h"
#include <string>
BoardObject::BoardObject() {
    //std::cout<< "board object constructor called" << std::endl;
    //x = 2;
    id = ' ';
}

BoardObject::BoardObject(int xx, int yy, char type) {
    //std::cout<< "board object 2 arg constructor called" << std::endl;
    r = xx;
    c = yy;
    id = type;
}

//BoardObject::BoardObject::operator = (const BoardObject &bo)
//{
//return *this;
//}

BoardObject::BoardObject(const BoardObject& orig){
}

//BoardObject::~BoardObject() {
   // std::cout<< "board object destructor called" << std::endl;
//}

//void BoardObject::printEnemy(){
//    cPtr->displayStats();
//}

