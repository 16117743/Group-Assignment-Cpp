#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include <iostream>
#include <string>

class Enemy : public Character{
public:
    Enemy();
    Enemy(const Enemy& orig);
    Enemy(int row,int col);
    ~Enemy();

private:

};

#endif /* ENEMY_H */

