/**
 * File: BoardObject.h
 * Date: 24/11/16
 * Authors: Thomas Flynn and Mashhour Alyami 
 */
#ifndef BOARDOBJECT_H//if header not defined
#define BOARDOBJECT_H//define it here
#include <iostream>//include library
#include <string>//include library

class BoardObject//base class for Items, Characters and Walls
{
public:
    int r;//row coordinates
    int c;//col coordinates
    char id;//char to store identity of board object
    BoardObject();//default constructor
    BoardObject(int xx, int yy, char type);//3 arg constructor, arg1 row, arg2 col, arg 3 identity
    BoardObject(const BoardObject& orig);//copy constructor
    void test1(){std::cout<< "base\n";} //test function
    ~BoardObject();//deconstructor
private:

};

#endif /* BOARDOBJECT_H */

