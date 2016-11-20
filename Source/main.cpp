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
#include "Wall.h"
#include <memory>

using namespace std;


Player p1;//player
Player *pPtr;

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
    void move1(size_t r, size_t c,size_t r1, size_t c1)
    { 
        std::cout << "move current row" << r << std::endl;
        std::cout << "move current col" << c<< std::endl;
        std::cout << "move current player row" << pPtr->r << std::endl;
        std::cout << "move current player col" << pPtr->c<< std::endl;
        data[cols*r+c].id = ' ';
        r+= r1;
        c += c1;
        data[cols*r+c].id = 'P';//x , y
        pPtr->r = r;
        pPtr->c = c;
        
    }
    char north(size_t r, size_t c){
        return data[cols*(r-1)+(c+(0))].id;//x , y
    }
    char south(size_t r, size_t c){
        return data[cols*(r+(1))+(c+0)].id;//x , y
    }
    char west(size_t r, size_t c){
        return data[cols*(r+0)+(c-1)].id;//x , y
    }
    
    char east(size_t r, size_t c){
        return data[cols*(r+0)+(c+1)].id;//x , y
    }
};

/*******Global variables******/
const size_t numRows = 8;//number of rows on board
const size_t numCols = 8;//number of cols on board

Board<BoardObject> board(numRows, numCols);//board declared as global variable
Board<Item> boardItems(numRows, numCols);//board declared as global variable
Board<Enemy> boardCharacters(numRows, numCols);//board declared as global variable

/********prototype functions*****/
int randomBoardObjectAssignment();
void createBoard();
void createBoardOject(int val,int row,int col,Board <BoardObject> Arr2D);
void printBoard();
void startup();
int raceSelection();
void selectStartingPoint();
int randomItemTypeAssignment();
void generateItemForEnemy(Character &c);
void attackRound(Player &player, Enemy &enemy);
bool isEnemyDefeated(Enemy &enemy);
bool isGameOver(Player &player);
void gameOver(Player &player);
void update(Character &c);//updates player stats and board
void handleUserInput(Player *pPtr);
void checkSquare();
void look(Player *p);
void confirmMovement(int r, int c, Player *pPtr);

/*****************************************************************************************/
int main(int argc, char** argv) {
    srand(time(0));// seed srand with time(0)
    createBoard();//creates the board
    printBoard();
    startup();
    pPtr = &p1;
    
    printBoard();
    while(1){
       handleUserInput(pPtr); 
       printBoard();
    }
    return 0;
}

//creates the board
void createBoard(){
    for (size_t i=0; i<numRows; ++i)
    {
       int ii = i;
       for (size_t j=0; j<numCols; ++j)
       {
           int rand1 = rand()%5;
           createBoardOject(rand1,i,j, board);
       }
    }
}

//creates a random object on the board
void createBoardOject(int val, int row, int col, Board <BoardObject> Arr2D){
    if(row%numRows == 0 || row%numRows== numRows-1){
        board(row,col)= Wall();
    }
    else if(col%numCols == 0 || col%numCols== numCols-1){
        board(row,col)= Wall(); 
    }
    else
    {
        switch(val)
        {
            case 0:
            {
                board(row,col) = Item();
                boardItems(row,col) = Item();
                break;
            }
            case 1:
            {
                board(row,col) = Item();
                break;
            }
            case 2:
            { 
                board(row,col) = Enemy();
                boardCharacters(row,col) = Enemy();
                boardCharacters(row,col).generateItemForEnemy();
                break;
            }
            case 3:
            {
                board(row,col) = Empty();
                break;
            }
            default:
            {
                Empty em1;
                board(row,col) = em1;
            }    
        }
    }
}

//prints the board
void printBoard()
{
    for (size_t i = 0; i < numRows; i++)
    {
        for (size_t j = 0; j < numCols; j++)
        {
            std::cout << "["<< i << "][" << j << "]" << board(i,j).id << ", ";//print the type of Board Object
        }
        std::cout << '\n';
    }
}

void startup(){
    std::cout << "welcome to Group X Fantasy game\n Please enter number for selecting character race" << std::endl;
    std::cout << "1- Human\n2-Elf\n3-Dwarf\n4-Hobbit\n5-Dwarf" << std::endl;
    raceSelection();
    selectStartingPoint();
}

int raceSelection()
{
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
            switch(selection)
            {
                case 1:
                    std::cout << "Human\n";
                    p1 = Player(0);
                    //pPtr = p1;
                    break;
                case 2: 
                    std::cout << "Elf\n";
                     p1 = Player(1);
                    break;
                case 3:
                    std::cout << "Dwarf\n";
                     p1 = Player(2);
                    break;
                case 4:
                    std::cout << "Hobbit\n";
                     p1 = Player(3);
                    break;
                case 5:
                    std::cout << "Orc\n";
                     p1 = Player(4);
                    break;
            }
            validSelection = true;
            pPtr = &p1;
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
        if(row < 0 || row > numRows-1 || col < 0 || col > numCols-1)//boundary checking
        {
            std::cout << "square is out of bounds, please try again" << std::endl;
        }
        else if (board(row,col).id!= ' ') // square is not empty
        {
            std::cout << "Square is not empty, please try again" << std::endl;
        }
        else
        {
            std::cout << "You have selected a valid starting point, the game will now begin" << std::endl;
            board(row,col) = Player();    
            pPtr->r = row;
            pPtr->c = col;
            validSelection = true;
        }
    }
    while (validSelection == false);
}

void handleUserInput(Player *pPtr){
    bool valid = true;
    char input;
    int tRow = pPtr->r;
    int tCol = pPtr->c;
    char input2;
    std::cout<<"please enter command"<< std::endl;
    do
    {
        std::cin >> input;
        switch(input)
        {
            case 'w'://north
            {
                confirmMovement(tRow,tCol-1, pPtr);
                valid = true;
                break;
            }
            case 's'://south
            {
                confirmMovement(tRow+1,tCol, pPtr);
                break;
            }
            case 'e'://east
            {
                confirmMovement(tRow,tCol+1, pPtr);
                break;
            }
            case 'n'://north
            {
                confirmMovement(tRow-1,tCol, pPtr);
                break;
            }
            case 'd'://look
                std::cout<<"drop"<< std::endl;
                valid = true;
                break;
            case 'a'://look
                std::cout<<"attack"<< std::endl;
                valid = true;
                break;
            case 'l'://look
                look(pPtr);
                valid = true;
                break;
            case 'i'://inventory
                std::cout<<"inventory"<< std::endl;
                p1.displayStats();
                valid = true;
                break;
            default:
                std::cout<<"not a valid command"<< std::endl;
                valid = false;
                break;
        }
        int testRow = pPtr->r;
        int testCol = pPtr->c;
//        if(board(testRow,testCol).id!= 'P'){
//            std::cout<<"ERROR: Board and player out of sync"<< std::endl;
//        }
    }
    while(valid == false);
}
    
void confirmMovement(int r, int c, Player *pPtr){
    char ds = board(r,c).id;
    int tRow = pPtr->r;
    int tCol = pPtr->c;
    std::cout<<"player current row "<< tRow << std::endl;
    std::cout<<"player current col "<< tCol << std::endl;
    switch(ds){
        case 'W':
            std::cout<<"a wall impedes your path"<< std::endl;
        break;
        case 'E':
        {
            std::cout<<"you are standing beside an enemy"<< std::endl;
            if(board(pPtr->r,pPtr->c).id == 'P')
                board(pPtr->r,pPtr->c).id = ' ';
            pPtr->r = r;
            pPtr->c = c;
        break;
        }
        case 'I':
        {
            std::cout<<"you are standing beside an item"<< std::endl;
            if(board(pPtr->r,pPtr->c).id == 'P')
                board(pPtr->r,pPtr->c).id = ' ';
            pPtr->r = r;
            pPtr->c = c;
        break;
        }
        case ' ':
        {
            std::cout<<"you are standing on empty square"<< std::endl;
            if(board(pPtr->r,pPtr->c).id == 'P')
                board(pPtr->r,pPtr->c).id = ' ';
            
            pPtr->r = r;
            pPtr->c = c;
            board(r,c).id = 'P';
        break;
        }
        default:
            break;
    }
    
}

void look(Player *p){
    printBoard();
    int row = p->r;
    int col = p->c;
    std::cout<< "row = " << row << std::endl;
    std::cout<< "col = " << col << std::endl;
    std::cout<< "you look north and see " << board.north(row,col) << std::endl;
    std::cout<< "you look south and see "  << board.south(row,col) << std::endl;
    std::cout<< "you look east and see "  << board.east(row,col) << std::endl;
    std::cout<< "you look west and see " << board.west(row,col) << std::endl;
}
void printCharacterStats(){
    
}

void attackRound(Player &player, Enemy &enemy){
    std::cout << "Player attacks:\noutcome = ";
    if(player.attack(enemy)==true)//if the attack was successful
    {
        if(isEnemyDefeated(enemy)==false){//enemy attacks back if not defeated
            std::cout << "Enemy attacks:\noutcome = ";
            enemy.attack(player);
        }
    }
}

bool isGameOver(Player &player){
    if(player.health <=0)
        return true;
    else 
        return false;
}


void gameOver(Player &player){
    std::cout << "You have been defeated, thank you for playing\n"<<std::endl;
    std::cout << "You collected"<< player.gold << std::endl;
}

bool isEnemyDefeated(Enemy &enemy){
    if(enemy.health<0){
        enemy.id = ' '; //removes enemy from the board by changing BoardObject.id
        return true;//enemy is defeated
    }
    return false;//enemy is not defeated
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