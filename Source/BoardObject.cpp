#include "BoardObject.h"

BoardObject::BoardObject() {
    std::cout<< "object constructor called" << std::endl;
    x = 2;
}

BoardObject::~BoardObject() {
    std::cout<< "object destructor called" << std::endl;
}

