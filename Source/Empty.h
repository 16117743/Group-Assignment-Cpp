/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empty.h
 * Author: tom
 *
 * Created on 12 November 2016, 13:07
 */

#ifndef EMPTY_H
#define EMPTY_H
#include "BoardObject.h"

class Empty : public BoardObject {
public:
    Empty();
    Empty(const Empty& orig);
    virtual ~Empty();
private:

};

#endif /* EMPTY_H */

