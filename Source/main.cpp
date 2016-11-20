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
    void move1(size_t r, size_t c,size_t ns, size_t ew) { 
        data[cols*r+c].id = '0';
        data[cols*(r+ew)+(c+ns)].id = 'P';//x , y
        std::cout << "***move****\nprev:\n[" << r << "][" << c << "]" <<  data[cols*r+c].id << "\n";
        std::cout << "\ncurrent:\n[" << (r+ew) << "][" << (c+ns) << "]" <<  data[cols*(r+ew)+(c+ns)].id << "\n";
    }
    char north(size_t r, size_t c){
        std::cout<< "row = " << r << std::endl;
        std::cout<< "col = " << c << std::endl;
        //data[cols*(r+ew)+(c+ns)].id = 'P';//x , y
        return data[cols*(r-1)+(c+(0))].id;//x , y
    }
    char south(size_t r, size_t c){
        std::cout<< "row = " << r << std::endl;
        std::cout<< "col = " << c << std::endl;
        //data[cols*(r+ew)+(c+ns)].id = 'P';//x , y
        return data[cols*(r+(1))+(c+0)].id;//x , y
    }
    char west(size_t r, size_t c){
        std::cout<< "row = " << r << std::endl;
        std::cout<< "col = " << c << std::endl;
        //data[cols*(r+ew)+(c+ns)].id = 'P';//x , y
        return data[cols*(r+0)+(c-1)].id;//x , y
    }
    
    char east(size_t r, size_t c){
        std::cout<< "row = " << r << std::endl;
        std::cout<< "col = " << c << std::endl;
        //data[cols*(r+ew)+(c+ns)].id = 'P';//x , y
        return data[cols*(r+0)+(c+1)].id;//x , y
    }
    
//    void updateBoard(size_t r, size_t c){
//        data[cols*(r+0)+(c+1)].id
//    }
    
    
        //data[cols*r+1+c+1] = std::move(data[cols*r+c]);}
    //data[cols*r+c].id='-1'
};

/*******Global variables******/
const size_t numRows = 8;//number of rows on board
const size_t numCols = 8;//number of cols on board

Board<BoardObject> board(numRows, numCols);//board declared as global variable
Board<Item> boardItems(numRows, numCols);//board declared as global variable
Board<Enemy> boardCharacters(numRows, numCols);//board declared as global variable
//Board<BoardObject> Arr2D(numRows, numCols);//board declared as global variable


Player p1;//player
Player *pPtr;
//vector<BoardObject*> board;

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
void handleUserInput();
void checkSquare();
void look(Player *p);

/*****************************************************************************************/
int main(int argc, char** argv) {
    srand(time(0));// seed srand with time(0)
    createBoard();//creates the board
    printBoard();
    startup();
    
    printBoard();
    while(1){
       handleUserInput(); 
       printBoard();
    }
    
    //printBoard();
    
    //checkSquare();
    //handleUserInput();
    /*Enemy e1(1);
    e1.displayStats();
    generateItemForEnemy(e1);
    e1.displayStats();
    Player p(2);*/

    //generateItem(e1);
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
            if(i%numRows == 0 || i%numRows== numRows-1){
                board(i,j).id == 'W'; 
                std::cout << "row [" << i << "] col[" << j << "] =" << board(i,j).id << std::endl;
            }
            if(j%numCols == 0 || j%numCols== numCols-1){
                board(i,j).id == 'W'; 
                std::cout << "row [" << i << "] col[" << j << "] =" << board(i,j).id << std::endl;
            }
       }
    }
}

//creates a random object on the board
void createBoardOject(int val, int row, int col, Board <BoardObject> Arr2D){
    switch(val){
        case 0:
        {
            //Item i1;
            board(row,col) = Item();
            boardItems(row,col) = Item();
            break;
        }
        case 1:
        {
            //Item em1;
            board(row,col) = Item();
            break;
        }
        case 2:
        { 
            //Enemy em1;
            board(row,col) = Enemy();
//            Enemy en1;
//            board(row,col) = en1;
//            boardCharacters(row,col).generateItemForEnemy();
            break;
        }
        case 3:
        {
            //Empty em1;
            board(row,col) = Empty();
            break;
        }
        default:
        {
            Empty em1;
            board(row,col) = em1;
        }    
    }
    //std::cout << "row%numrows = " << row%numRows << std::endl;
    //std::cout << "col%numcolls = " << col%numCols << std::endl;
    //std::cout << "row [" << row << "] col[" << col << "] = board(row,col).id " << std::endl;
    if(row%numRows == 0 || row%numRows== numRows-1){
       board(row,col).id == 'W'; 
    }
    if(col%numCols == 0 || col%numCols== numCols-1){
       board(row,col).id == 'W'; 
    }
    std::cout << "row [" << row << "] col[" << col << "] =" << board(row,col).id << std::endl;
}

//prints the board
void printBoard(){
    for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < numCols; j++) {
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
                    p1 = Player(0);
                    //pPtr = p1;
                    break;
                case 2: 
                    std::cout << "Dwarf\n";
                     p1 = Player(1);
                    break;
                case 3:
                    std::cout << "Elf\n";
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
        if(row < 0 || row > 7 || col < 0 || col > 7)//boundary checking
        {
            std::cout << "square is out of bounds, please try again" << std::endl;
        }
//        else if (board(row,col).id!= ' ') // square is not empty
//        {
//            std::cout << "Square is not empty, please try again" << std::endl;
//        }
        else{
            std::cout << "You have selected a valid starting point, the game will now begin" << std::endl;
            board(row,col) = Player();    
            pPtr->r = row;
            pPtr->c = col;
            std::cout<< "boards p id " << board(row,col).id << std::endl;
            std::cout<< "actual p row " << row << std::endl;
            std::cout<< "actual p col " << col << std::endl;
            validSelection = true;
        }
    }
    while (validSelection == false);
}

void handleUserInput(){
    bool valid = true;
    char input;
    std::cout<<"please enter command"<< std::endl;
    do
    {
        std::cin >> input;
        switch(input)
        {
            case 'w'://north
            {
                std::cout<<"moving west"<< std::endl;
                int tRow = pPtr->r;
                int tCol = pPtr->c;
                board.move1(tRow,tCol,0,-1);//row,col
                pPtr->c+= (-1);
                tCol = pPtr->c;
                std::cout<< "boards p id " << board(tRow,tCol).id << std::endl;
                std::cout<< "boards p row " << board(tRow,tCol).r << std::endl;
                std::cout<< "boards p col " << board(tRow,tCol).c << std::endl;
                std::cout<< "actual p row " << pPtr->r << std::endl;
                std::cout<< "actual p col " << pPtr->c << std::endl;
                valid = true;
                break;
            }
            case 's'://south
            {
                std::cout<<"moving south"<< std::endl;
                int tRow = pPtr->r;
                int tCol = pPtr->c;
                board.move1(pPtr->r,pPtr->c,1,0);//
                pPtr->r+=1;
                tRow = pPtr->r;
                std::cout<< "boards p id " << board(tRow,tCol).id << std::endl;
                std::cout<< "boards p row " << board(tRow,tCol).r << std::endl;
                std::cout<< "boards p col " << board(tRow,tCol).c << std::endl;
                std::cout<< "actual p row " << pPtr->r << std::endl;
                std::cout<< "actual p col " << pPtr->c << std::endl;
                valid = true;
                break;
            }
            case 'e'://east
            {
                std::cout<<"moving east"<< std::endl;
                int tRow = pPtr->r;
                int tCol = pPtr->c;
                board.move1(pPtr->r,pPtr->c,0,1);
                pPtr->c+=1;
                tCol = pPtr->c;
                std::cout<< "boards p id " << board(tRow,tCol).id << std::endl;
                std::cout<< "boards p row " << board(tRow,tCol).r << std::endl;
                std::cout<< "boards p col " << board(tRow,tCol).c << std::endl;
                std::cout<< "actual p row " << pPtr->r << std::endl;
                std::cout<< "actual p col " << pPtr->c << std::endl;
                valid = true;
                break;
            }
            case 'n'://west
            {
                std::cout<<"moving north"<< std::endl;
                int tRow = pPtr->r;
                int tCol = pPtr->c;
                board.move1(pPtr->r,pPtr->c,-1,0);
                pPtr->r+= (-1);
                tRow = pPtr->r;
                std::cout<< "boards p id " << board(tRow,tCol).id << std::endl;
                std::cout<< "boards p row " << board(tRow,tCol).r << std::endl;
                std::cout<< "boards p col " << board(tRow,tCol).c << std::endl;
                std::cout<< "actual p row " << pPtr->r << std::endl;
                std::cout<< "actual p col " << pPtr->c << std::endl;
                valid = true;
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
        if(board(testRow,testCol).id!= 'P'){
            std::cout<<"ERROR: Board and player out of sync"<< std::endl;
            board(testRow,testCol).id = 'P';
            std::cout<<"real player row: " << pPtr->r << std::endl;
            std::cout<<"real player col: " << pPtr->c << std::endl;
            std::cout<<"board player id: " << board(testRow,testCol).id << std::endl;
        }
    }
    while(valid == false);
}

void checkSquare(){
    std::cout<< "you look north and see " << board.north(1,1) << std::endl;
    std::cout<< "you look south and see "  << board.south(1,1) << std::endl;
    std::cout<< "you look east and see "  << board.east(1,1) << std::endl;
    std::cout<< "you look west and see " << board.west(1,1) << std::endl;
        
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