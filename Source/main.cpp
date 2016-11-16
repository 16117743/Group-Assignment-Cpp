#include <cstdlib>
#include <iostream>
#include <string>
#include <vector> 
#include "BoardObject.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Empty.h"
#include "Inventory.h"
#include <ctime>
#include "Item.h"
#include <memory>

using namespace std;

/* Board class */
template<typename T>
class Board {
    //std::vector<std::unique_ptr<T> > data;
    std::vector<T> data;
    const size_t cols;
public:
    Board(size_t R, size_t C) : data(R*C), cols(C) {}
    T operator()(size_t r, size_t c) const { return data[cols*r+c]; }
    T& operator()(size_t r, size_t c) { return data[cols*r+c]; }
};

//number of rows on board
const size_t numRows = 8;
//number of cols on board
const size_t numCols = 8;
//board declared as global variable
Board<BoardObject> Arr2D(numRows, numCols);
Player p1;

//prototype functions
int randomBoardObjectAssignment();
void createBoard();
void createBoardOject(int val,int row,int col,Board <BoardObject> &Arr2D);
void printBoard();
void startup();
int raceSelection();
void selectStartingPoint();
int randomItemTypeAssignment();
void generateItem(int rand);

int main(int argc, char** argv) {
    srand(time(0));// seed srand with time(0)
    createBoard();//creates the board

    Enemy e1(1);
    Player p(2);
    e1.displayStats();
    p.displayStats();
    //Enemy e1(new Human);
    //Player p(new Elf);
    
   // e1.displayStats();
    
    return 0;
}

//creates the board
void createBoard(){
    for (size_t i=0; i<numRows; ++i)
    {
       int ii = i;
       for (size_t j=0; j<numCols; ++j)
       {
           int rand = randomBoardObjectAssignment();
           createBoardOject(rand,i,j,Arr2D);
       }
    }
}

void startup(){
    std::cout << "welcome to Group X Fantasy game\n Please enter number for selecting character race" << std::endl;
    std::cout << "1- Human\n2-Elf\n3-Dwarf\n4-Hobbit\n5-Dwarf" << std::endl;
    raceSelection();
    selectStartingPoint();
}

int raceSelection(){
    bool validSelection = false;
    int selection = -1;
    
    do
    {
        std::cin >> selection;
        if(selection < 1 || selection > 5)
        {
            std::cout << "invalid selection, please try again" << std::endl;
            validSelection = false;
        }
        else
        {
            std::cout << "You have selected the race ";
            switch(selection){
                case 1:
                    std::cout << "Human\n";
                    break;
                case 2: 
                    std::cout << "Dwarf\n";
                    break;
                case 3:
                    std::cout << "Elf\n";
                    break;
                case 4:
                    std::cout << "Hobbit\n";
                    break;
                case 5:
                    std::cout << "Orc\n";
                    break;
            }
            validSelection = true;
        }
    }
    while (validSelection == false);
    return selection;
}

void selectStartingPoint(){
    std::cout << "please select a valid starting point by indicating x and y coordinates\n (0 is the first index in a row or column)"<< std::endl;
    printBoard();
    
    int row = -1;
    int col = -1;
    bool validSelection = false;
    do
    {
        std::cout << "Enter row" << std::endl;
        std::cin >> row;
        std::cout << "Enter col" << std::endl;
        std::cin >> col;
        if(row < 0 || row > 7 || col < 0 || col > 7)//boundary checking
        {
            std::cout << "square is out of bounds, please try again" << std::endl;
        }
        else if (Arr2D(row,col).id!= ' ') // square is not empty
        {
            std::cout << "Square is not empty, please try again" << std::endl;
        }
        else{
            std::cout << "You have selected a valid starting point, the game will now begin" << std::endl;
            Arr2D(row,col) = p1;
            validSelection = true;
        }
    }
    while (validSelection == false);
}

//generates a random number for creating a type of board object
int randomBoardObjectAssignment(){ 
    int f = rand()%4;
    return f;
}

//generates a random number for creating a type of item
int randomItemTypeAssignment(){
    int f = rand()%9;
    return f;
}

void generateItem(int rand){
    switch(rand)
    {
        case 0: // sword
            p1.pickup(new Sword);
        break;
        case 1: // dagger
            p1.pickup(new Dagger);
        break;
        case 2: // leather
            p1.pickup(new PlateArmour);
        break;
        case 3: // plate
            p1.pickup(new LeatherArmour);
        break;
        case 4: // large shield
            p1.pickup(new LargeShield);
        break;
        case 5: // small shield
            p1.pickup(new SmallShield);
        break;
        case 6: // ring of str
            p1.pickup(new RingOfStrength);
        break;
        case 7: // ring of life
            p1.pickup(new RingOfLife);
        break;          
    }
}


//creates a random object on the board
void createBoardOject(int val, int row, int col, Board <BoardObject> &Arr2D){
    switch(val){
        case 0:
            Arr2D(row,col) = Item();
            break;
        case 1:
            Arr2D(row,col) = Item();
            break;
        case 2:
            Arr2D(row,col) = Empty();
            break;
        case 3:
            Arr2D(row,col) = Empty();
            break;
    }
}

//prints the board
void printBoard(){
    for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < numCols; j++) {
                std::cout << Arr2D(i,j).id << ", ";//print the type of Board Object
            }
            std::cout << '\n';
        }
}

/*
     p1 = Player();
    startup();
     
    printBoard();//prints the board
    int row1;
    int col1;
    
    while(1){
    std::cout << "row" << std::endl;
    std::cin >> row1;
    std::cout << "col" << std::endl;
    std::cin >> col1;

    if(Arr2D(row1,col1).id == 'I'){
        int rand = randomItemTypeAssignment();
        generateItem(rand);
    }
    else{}
    
    
    p1.inventory.printInventory();
    }*/


/* dynamically allocate objects
 
 std::vector<std::unique_ptr<BoardObject> > my_vector;
    int object_count = 64;
    my_vector.reserve(object_count);
    for(int index = 0; index < object_count; index++)
    {
      my_vector.push_back(std::unique_ptr<BoardObject>(new Sword()));
    }
 
 */