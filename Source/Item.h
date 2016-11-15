#ifndef ITEM_H
#define ITEM_H
#include "BoardObject.h"
#include <string>

class Item : public BoardObject {
public:
    int weight;
    int atk;
    int def;
    int health;
    int strength;
    std::string name;
    std::string type;
    Item();
    Item(const Item& orig);
    virtual ~Item();
    void operator = (const Item & );
    private:

};

class Weapon : public Item {
    public:
    Weapon();
    Weapon(const Item& orig);
    virtual ~Weapon();
    private:
};

class Sword : public Weapon {
    public:
    Sword();
    Sword(const Item& orig);
    virtual ~Sword();
    private:
};

class Dagger : public Weapon {
    public:
    Dagger();
    Dagger(const Item& orig);
    virtual ~Dagger();
    private:
};

class Armour : public Item {
    public:
    Armour();
    Armour(const Item& orig);
    virtual ~Armour();
    private:
};

class PlateArmour : public Armour {
    public:
    PlateArmour();
    PlateArmour(const Item& orig);
    virtual ~PlateArmour();
    private:
};

class LeatherArmour : public Armour {
    public:
    LeatherArmour();
    LeatherArmour(const Item& orig);
    virtual ~LeatherArmour();
    private:
};

class Shield : public Item {
    public:
    Shield();
    Shield(const Item& orig);
    virtual ~Shield();
    private:
};

class SmallShield : public Shield {
    public:
    SmallShield();
    SmallShield(const Item& orig);
    virtual ~SmallShield();
    private:
};

class LargeShield : public Shield {
    public:
    LargeShield();
    LargeShield(const Item& orig);
    virtual ~LargeShield();
    private:
};

class Ring : public Item {
    public:
        
    Ring();
    Ring(const Item& orig);
    virtual ~Ring();
    private:
};

class RingOfLife : public Ring {
    public:
    RingOfLife();
    RingOfLife(const Item& orig);
    virtual ~RingOfLife();
    private:
};

class RingOfStrength : public Ring {
    public:
    RingOfStrength();
    RingOfStrength(const Item& orig);
    virtual ~RingOfStrength();
    private:
};

#endif /* ITEM_H */

