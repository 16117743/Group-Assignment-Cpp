#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H
#include <iostream>
#include <string>

class BoardObject {
public:
    int x;//x coordinates
    int y;//y coordinates
    char id;

    BoardObject();
    BoardObject(int xx, int yy, char type);
    BoardObject(const BoardObject& orig);//copy constructor

//    BoardObject BoardObject::operator=(const BoardObject&mx)const;   
    virtual ~BoardObject();
private:

};

#endif /* BOARDOBJECT_H */

