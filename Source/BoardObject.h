#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H
#include <iostream>
#include <string>

class BoardObject {
public:
    int r;//y coordinates
    int c;//x coordinates
    char id;
    BoardObject();
    BoardObject(int xx, int yy, char type);
    BoardObject(const BoardObject& orig);//copy constructor
    void test1(){std::cout<< "base\n";}  
    ~BoardObject();
private:

};

#endif /* BOARDOBJECT_H */

