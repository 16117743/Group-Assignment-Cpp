#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include <iostream>
#include <string>
#include <ctime>
class Enemy : public Character{
public:
    Enemy();
    Enemy(Character c);
    Enemy(const Enemy& orig);
    Enemy(int row,int col);
    ~Enemy();
    void generateItemForEnemy();
private:

};

#endif /* ENEMY_H */

