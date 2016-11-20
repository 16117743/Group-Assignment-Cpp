#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H
#include <iostream>
#include <string>

class BoardObject {
public:
    int r;//y coordinates
    int c;//x coordinates
    char id;
//    Character *cPtr;
    //Item iPtr;

    BoardObject();
    BoardObject(int xx, int yy, char type);
    BoardObject(const BoardObject& orig);//copy constructor
    void test1(){std::cout<< "base\n";}
    //virtual void displayStats2();
    
//    BoardObject BoardObject::operator=(const BoardObject&mx)const;   
    virtual ~BoardObject() = default;
private:

};

#endif /* BOARDOBJECT_H */

