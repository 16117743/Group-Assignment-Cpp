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
    Item();
    Item(const Item& orig);
    virtual ~Item();
    private:

};

class Weapon : public Item {
    public:
    Weapon();
    Weapon(const Weapon& orig);
    virtual ~Weapon();
    private:
};

class Sword : public Weapon {
    public:
    Sword();
    Sword(const Sword& orig);
    virtual ~Sword();
    private:
};

class Dagger : public Weapon {
    public:
    Dagger();
    Dagger(const Dagger& orig);
    virtual ~Dagger();
    private:
};

class Armour : public Item {
    public:
    Armour();
    Armour(const Armour& orig);
    virtual ~Armour();
    private:
};

class PlateArmour : public Armour {
    public:
    PlateArmour();
    PlateArmour(const PlateArmour& orig);
    virtual ~PlateArmour();
    private:
};

class LeatherArmour : public Armour {
    public:
    LeatherArmour();
    LeatherArmour(const LeatherArmour& orig);
    virtual ~LeatherArmour();
    private:
};

class Shield : public Item {
    public:
    Shield();
    Shield(const Shield& orig);
    virtual ~Shield();
    private:
};

class SmallShield : public Shield {
    public:
    SmallShield();
    SmallShield(const SmallShield& orig);
    virtual ~SmallShield();
    private:
};

class LargeShield : public Shield {
    public:
    LargeShield();
    LargeShield(const LargeShield& orig);
    virtual ~LargeShield();
    private:
};

class Ring : public Item {
    public:
        
    Ring();
    Ring(const Ring& orig);
    virtual ~Ring();
    private:
};

class RingOfLife : public Ring {
    public:
    RingOfLife();
    RingOfLife(const RingOfLife& orig);
    virtual ~RingOfLife();
    private:
};

class RingOfStrength : public Ring {
    public:
    RingOfStrength();
    RingOfStrength(const Ring& orig);
    virtual ~RingOfStrength();
    private:
};

#endif /* ITEM_H */

