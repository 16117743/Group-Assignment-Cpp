#include "Character.h"

Character::Character() {
    //std::cout << "default character constructor" << std::endl;
   // id = "C";
}

Character::Character(int row, int col, char type) : BoardObject(row,col,type){
    //std::cout << "2 arg character constructor" << std::endl;
}

Character::Character(const Character& orig){
    
}

Character::~Character() {
    //std::cout<< "character destructor called" << std::endl;
}

/**Sword class */
Human::Human() {
    type = "Human";
    atk = 30;
    atkChance = 66;
    def = 20;
    defChance = 50;
    health = 60;
    strength = 100;
}

Human::~Human(){
    
}

Elf::Elf() {
    type = "Elf";
    atk = 40;
    atkChance = 100;
    def = 10;
    defChance = 25;
    health =  40;
    strength = 70;
}

Elf::~Elf(){
    
}

/**Dwarf constructor */
Dwarf::Dwarf() {
    type = "Dwarf";
    atk = 30;
    atkChance = 66;
    def = 20;
    defChance = 66;
    health = 50;
    strength = 130;
}

/**Dwarf destructor */
Dwarf::~Dwarf(){
    
}

/**Sword class */
Hobbit::Hobbit() {
    type = "Hobbit";
    atk = 25;
    atkChance = 33;
    def = 20;
    defChance = 66;
    health = 70;
    strength = 85;
}

Hobbit::~Hobbit(){
    
}

/**Sword class */
Orc::Orc() {
    type = "Orc";
    atk = 25;//45 night
    atkChance = 25;//100 night
    def = 10;//25 night
    defChance = 25;//50 night
    health = 50;
    strength = 130;
}

Orc::~Orc(){
    
}
