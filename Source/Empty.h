/**
 * File: Empty.h
 * Date: 24/11/16
 * Authors: Essa Alyami 
 */
#ifndef EMPTY_H//if header not defined
#define EMPTY_H//define it here
#include "BoardObject.h"

class Empty : public BoardObject {
public://public constructors, attributes and member functions
    Empty();//default constructor
    Empty(const Empty& orig);//copy constructor
    virtual ~Empty();//virtual deconstructor
private:

};

#endif /* EMPTY_H */

