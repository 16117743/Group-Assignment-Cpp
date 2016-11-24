/**
 * File: BoardObject.cpp
 * Date: 24/11/16
 * Authors: Thomas Flynn and Essa Alyami
 * Class Description
 * Character class 
 */
#include "BoardObject.h"//include header
#include <string>//include library
BoardObject::BoardObject() //default constructor
{
    id = ' ';//assign attributes
}

//constructor
BoardObject::BoardObject(int xx, int yy, char type)//arg1 = row, arg2 = col, arg3 = char identity
{
    r = xx;//assign attributes
    c = yy;//assign attributes
    id = type;//assign attributes
}

BoardObject::BoardObject(const BoardObject& orig)//copy constructor
{
}


BoardObject::~BoardObject()//deconstructor
{
}
