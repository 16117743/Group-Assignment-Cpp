#include "BoardObject.h"
#include <string>
BoardObject::BoardObject() {
    id = ' ';
}

BoardObject::BoardObject(int xx, int yy, char type) {
    //std::cout<< "board object 2 arg constructor called" << std::endl;
    r = xx;
    c = yy;
    id = type;
}

BoardObject::BoardObject(const BoardObject& orig){
}


BoardObject::~BoardObject(){
}
