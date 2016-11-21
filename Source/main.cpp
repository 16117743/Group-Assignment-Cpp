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
    std::vector<T> data;
    const size_t cols;
public:
    Board(size_t R, size_t C) : data(R*C), cols(C) {}
    T operator()(size_t r, size_t c) const { return data[cols*r+c]; }
    T& operator()(size_t r, size_t c) { return data[cols*r+c]; }
    void move1(size_t r, size_t c,size_t r1, size_t c1)
    { 
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
    char standingSquare(size_t r, size_t c){
        return data[cols*(r)+(c)].id;//x , y
    }
};

/*******Global variables******/
const size_t numRows = 8;//number of rows on board
const size_t numCols = 8;//number of cols on board
int dayNightCtr =0;
bool dayFlag = true;
bool gameOverFlag = false;
bool playAgain = true;

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
void generateRandomItem(int row, int col);
void attackRound(Player *player, Character *enemy);
bool isEnemyDefeated(Character *enemy);
bool isGameOver(Player *player);
void gameOver(Player *player);
void update(Character &c);//updates player stats and board
void handleUserInput(Player *pPtr);
void checkSquare();
void look(Player *p);
void confirmMovement(int r, int c, Player *pPtr);
void infoSquare(int r,int c,char ch);
void exit();

/*****************************************************************************************/
int main(int argc, char** argv) {
    srand(time(0));// seed srand with time(0)
    char playAgainChar;
    do
    {
        createBoard();//creates the board
        printBoard();
        startup();
        pPtr = &p1;
        do
        {
            handleUserInput(pPtr); 
            dayNightCtr +=1;
            if(dayNightCtr%10<5){
                dayFlag= true;
                std::cout << "it is day time\n";
            }
            else if(dayNightCtr%10>5){
                dayFlag = false;
                std::cout << "it is night time\n";
            }
            if(isGameOver(pPtr)==true){
                gameOver(pPtr);
                break;
            }
        }
        while(gameOverFlag==false);
        std::cout << "game over\nplay again y/n\n";
        std::cin>>playAgainChar;
        
        if(playAgainChar == 'y'){
           std::cout << "you have opted to play again\n";
           playAgain = true;
        }
        else if(playAgainChar == 'n'){
           std::cout << "you have opted not to play again\n";
           playAgain = false;
        }
        else {
           std::cout << "you did not choose 'y', the game will now end\n";
           playAgain = false;
        }
    }
    while(playAgain==true);
    std::cout << "Thank you for playing\n";
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
                generateRandomItem(row,col);
                break;
            }
            case 1:
            {
                board(row,col) = Item();
                generateRandomItem(row,col);
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

void generateRandomItem(int row, int col){
    int random = rand()%8;
    switch(random)
    {
        case 0:
        {// sword
            boardItems(row,col) = Item(new Sword());
        break;
        }
        case 1: // dagger
        {
            boardItems(row,col) = Item(new Dagger());
        break;
        }
        case 2: // leather
        {
            boardItems(row,col) = Item(new LeatherArmour());
        break;
        }
        case 3: // plate
        {
            boardItems(row,col) = Item(new PlateArmour());
        break;
        }
        case 4: // large shield
        {
            boardItems(row,col) = Item(new LargeShield());
        break;
        }
        case 5: // small shield
        {
            boardItems(row,col) = Item(new SmallShield());
        break;
        }
        case 6: // ring of str
        {
            boardItems(row,col) = Item(new RingOfStrength());
        break;
        }
        case 7: // ring of life
        {
            boardItems(row,col) = Item(new RingOfLife());
        break;          
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
    std::cout << "welcome to Group 8 Fantasy game\nCommands:\n"
            "'a' = attack\n'n' = move north \n's' = move south\n'e' = move east\n'w' = move west\n'x' = exit current game"
            "'p' = pickup item\n'i' = list inventory\n'd' = drop item\n'e' = exit game\n\nPlease enter number for selecting character race" << std::endl;
    std::cout << "1-Human\n2-Elf\n3-Dwarf\n4-Hobbit\n5-Dwarf" << std::endl;
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
        if(selection < 1 || selection > 7)
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
        if(row <= 0 || row > numRows-1 || col <=0 || col > numCols-1)//boundary checking
        {
            std::cout << "square is out of bounds, please try again" << std::endl;
        }
        else
        {
            if (board(row,col).id== ' '){ // square is not empty
               //board(row,col) = Player(); 
            }
            std::cout << "You have selected a valid starting point, the game will now begin" << std::endl;  
            pPtr->r = row;
            pPtr->c = col;
            int r = pPtr->r;
            int c = pPtr->c;
            confirmMovement(r, c , pPtr);
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
    Item iPtr;
    Character *ePtr;
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
            case 'p'://look
            {
                std::cout<<"****pickup****"<< std::endl;
                if(board(tRow,tCol).id=='I')
                {
                    iPtr = boardItems(tRow,tCol);
                    if(pPtr->pickup(&iPtr)==true)
                    {
                         board(tRow,tCol).id = 'P';
                    }
                    else{
                         std::cout<<"insufficient strength to pick up item"<< std::endl;
                    }
                }
                else{
                    std::cout<<"There is no item here to pickup"<< std::endl;
                }
                valid = true;
                break;
            }
            case 'c'://character stats
            {
                pPtr->displayStats();  
                valid = true;
                break;
            }
            case 'd'://drop
            {
                std::cout<<"****drop****"<< std::endl;
                std::cout<<"choose type of item to drop by selecting corresponding index\n1-Weapon\n2-Armour\n3-Shield\n4-Rings"<< std::endl;
                int choice;
                bool validChoice = false;
                do
                {
                    std::cin>> choice;
                    if(choice > 0 || choice < 5){
                        pPtr->drop(choice);
                        validChoice = true;
                        break;
                    }
                    else{
                        validChoice = false;
                        std::cout<<"Invalid choice, please select from within the index specified"<< std::endl;
                    }
                }
                while(validChoice ==false);
                valid = true;
                break;
            }
            case 'a'://attack command
            {
                std::cout<<"****attack****"<< std::endl;
                if(board(tRow,tCol).id=='E'){
                    ePtr = &boardCharacters(tRow,tCol);
                    attackRound(pPtr,ePtr);
                }
                else
                    std::cout << "there is no enemy here to attack\n";
                
                valid = true;
                break;
            }
            case 'l'://look
            {
                look(pPtr);
                valid = true;
                break;
            }
            case 'i'://inventory
            {
                std::cout<<"inventory"<< std::endl;
                p1.displayStats2();
                valid = true;
                break;
            }
            case 'x':  {
                std::cout<<"exit!"<< std::endl;
                exit();
                break;
            }
            default:
            {
                std::cout<<"not a valid command"<< std::endl;
                valid = false;
                break;
            }
        }
    }
    while(valid == false);
}

void exit(){
    gameOverFlag = true;
}
    
void confirmMovement(int r, int c, Player *pPtr){
    char ds = board(r,c).id;
    int tRow = pPtr->r;
    int tCol = pPtr->c;
    switch(ds){
        case 'W':
            std::cout<<"you try to move but a wall impedes your path"<< std::endl;
        break;
        case 'E':
        {
            std::cout<<"you are standing beside an enemy"<< std::endl;
            pPtr->r = r;
            pPtr->c = c;
        break;
        }
        case 'I':
        {
            std::cout<<"you are standing beside an item"<< std::endl;
            pPtr->r = r;
            pPtr->c = c;
        break;
        }
        case ' ':
        {
            std::cout<<"you are standing on empty square"<< std::endl;
            pPtr->r = r;
            pPtr->c = c;
            board(r,c).id = 'P';
        break;
            std::cout<<"you are standing on empty square"<< std::endl;
            pPtr->r = r;
            pPtr->c = c;
            board(r,c).id = 'P';
        }
        default:
            break;
    }
    
}

void look(Player *p){
    char ch;
    printBoard();
    int row = p->r;
    int col = p->c;
    std::cout<< "\n****Look****" << std::endl;
    
    ch = board.north(row,col);
    std::cout<< "you look north and see " << std::endl;
    infoSquare(row-1,col,ch);
    
    ch = board.south(row,col);
    std::cout<< "\nyou look south and see " << std::endl;
    infoSquare(row+1,col,ch);
    
    ch = board.east(row,col);
    std::cout<< "\nyou look east and see " << std::endl;
    infoSquare(row,col+1,ch);
    
    ch = board.west(row,col);
    std::cout<< "\nyou look west and see " << std::endl;
    infoSquare(row,col-1,ch);
    ch = board.standingSquare(row,col);
    std::cout<< "\nyou look at the current square and see " << std::endl;
    infoSquare(row,col,ch);
}

void infoSquare(int r,int c,char ch){
    switch(ch)
    {
        case 'W':
            std::cout<< "a wall:\n " << std::endl;
        break;
        case 'E':
            std::cout<< "an enemy:\n ";
            boardCharacters(r,c).displayStats();
        break;
        case 'I':
            std::cout<< "an Item:\n";
            std::cout<< "Name: " << boardItems(r,c).name <<std::endl;
            std::cout << "Weight: " << boardItems(r,c).weight <<std::endl;
            std::cout << "Attack mod: " << boardItems(r,c).atk <<std::endl;
            std::cout << "Defence mod: " << boardItems(r,c).def <<std::endl;
            std::cout << "Health mod: " << boardItems(r,c).health <<std::endl;
            std::cout << "Strength mod: " << boardItems(r,c).strength <<std::endl;
        break;
        case ' ':
            std::cout<< "an Empty square:\n";// << board.north(row,col) << std::endl;
        break;
        default:
            std::cout<< "an Empty square:\n";// << board.north(row,col) << std::endl;
        break;
    }
}

void attackRound(Player *player, Character *enemy){
    std::cout << "You try to attack the enemy:\n";
    player->attack(enemy,dayFlag);
    if(isEnemyDefeated(enemy)==true){//enemy attacks back if not defeated
        std::cout << "You have slain the enemy\n";
        board(pPtr->r,pPtr->c).id = ' ';
        pPtr->gold += boardCharacters(pPtr->r,pPtr->c).def;
        std::cout << "your now have " << pPtr->gold << " gold \n";
    }
    else if(isEnemyDefeated(enemy)==false){//enemy attacks back if not defeated
        std::cout << "Enemy attacks:\noutcome = ";
        enemy->attack(player,dayFlag);
        std::cout << "Your stats:\n";
        player->displayStats();
        std::cout << "Enemy stats:\n";
        enemy->displayStats();
    }
}

bool isGameOver(Player *player){
    if(player->health <=0)
        return true;
    else 
        return false;
}


void gameOver(Player *player){
    std::cout << "You have been defeated, thank you for playing\n"<<std::endl;
    std::cout << "You collected "<< player->gold << " gold\nplay again? y/n\n" << std::endl;
}

bool isEnemyDefeated(Character *enemy){
    if(enemy->health<=0){
        //enemy->id = ' '; //removes enemy from the board by changing BoardObject.id
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