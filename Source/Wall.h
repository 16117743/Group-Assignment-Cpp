/**
 * File: Wall.h
 * Date: 24/11/16
 * Authors: Thomas Flynn and Essa Alyami 
 */
#ifndef WALL_H//if header not defined
#define WALL_H//define it here
#include "BoardObject.h"//include header file
class Wall: public BoardObject//extends BoardObject
 {
public://public constructors, attributes and member functions
    Wall();//constructor
    Wall(const Wall& orig);//copy constructor
    virtual ~Wall();//virtual deconstructor
private://private constructors, attributes and member functions

};

#endif /* WALL_H */

