/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wall.h
 * Author: tom
 *
 * Created on 20 November 2016, 17:51
 */

#ifndef WALL_H
#define WALL_H
#include "BoardObject.h"
class Wall: public BoardObject {
public:
    Wall();
    Wall(const Wall& orig);
    virtual ~Wall();
private:

};

#endif /* WALL_H */

