#ifndef BOARDOBJECT_H
#define BOARDOBJECT_H
#include <iostream>
#include <string>

class BoardObject {
public:
    int x;//x coordinates
    int y;//y coordinates

    BoardObject();
    BoardObject(const BoardObject& orig);
    virtual ~BoardObject();
private:

};

#endif /* BOARDOBJECT_H */

