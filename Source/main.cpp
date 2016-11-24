/*********Group 11 C++ Assignment************************************************ 
 * File: main.cpp
 * Date:  23-11-16
 * Members: 
 *  Thomas Flynn, 16117743
 *  Mashhour Alyami, 15065073
 *  Essa Alyami, 16032063
 *  Raksha Ramdas, 16052439
 *
 * Roles:
 *  Thomas Flynn: Lead developer
 *  Mashhour Alyami: Developed Character class and created STL document
 *  Essa Alyami: Developed Item, Wall, and BoardOject class
 *  Raksha Ramdas: Drew up UML plan and created makefile
 *
 * Game Description:
 *  Fantasy Game played through a text interface. The aim
 *  of the game is to collect as much gold as possible by defeating enemy characters.
 * 
 * Objectives not achieved:
 *  1-Dynamic allocation of board size functionality
 *  2-Drop item functionality
 *  3-Item inventory swap functionality
 *  4-Game implemented as a class
 * 
 * Reasons not achieved:
 *  1-Board class has been implemented to be initialised by compile time consts
 *  2-Item created on heap, poor memory management
 *  3-poor memory management
 *  4-Couldn't transfer functionality built in main to Game class
 * 
 * Solutions:
 *  1-Reconfigure the Board class to not be initialized with const int
 *  2-Implement deconstructor for item class or use unique pointer
 *  3-Reconfigure the inventory class implementation
 *  4-Start initial development around "Game" class and build from there.
 *************************************************************************/

#include <cstdlib>//include library for castlib
#include <iostream>//include library for iostream
#include <string>//include library for string
#include <vector> //include library for vector
#include <ctime>//include library for ctime
#include <memory>//include library for memory
#include "BoardObject.h"//include header file for BoardObject
#include "Character.h"//include header file for Character
#include "Player.h"//include header file for Player
#include "Enemy.h"//include header file for Enemy
#include "Empty.h"//include header file for Empty
#include "Inventory.h"//include header file for Inventory
#include "Item.h"//include header file for Item
#include "Wall.h"//include header file for Wall

using namespace std;//using std namespace

/********Global variables********/
const size_t numRows = 8;//number of rows on board
const size_t numCols = 8;//number of cols on board
unsigned int dayNightCtr =0;//int for counting the player's command, user in relation day night determination
bool dayFlag = true;////boolean for storing status of day or night
bool gameOverFlag = false;//boolean for storing current game continuation status
bool playAgain = true;//boolean for storing user's decision to play again
Player p1;//player object
Player *pPtr;//pointer to player object

/********prototype functions********/
void createBoard();//create the board
void createBoardOject(unsigned int val,unsigned int row,unsigned int col);//assign a board object to the board
void printBoard();//prints the board for debugging purposes
void startup();//initiates game start sequence by caling raceSelection() and sselectStartingPoint()
int raceSelection();//asks user to input starting race selection
void selectStartingPoint();//asks user to input starting square
int randomItemTypeAssignment();//assigns a random item to the board
void generateItemForEnemy(Character &c);//generates a random item for the enemy, takes character refernce as param
void generateRandomItem(unsigned int row, unsigned int col);//generates a random item , take row and col as param
void attackRound(Player *player, Character *enemy);//initiates an attack sequence, takes player and character pointers as params
bool isEnemyDefeated(Character *enemy);//checks to see if the enemy has died, takes enemy pointer as param
bool isGameOver(Player *player);//checks to see if the player has died, takes player pointer as param
void gameOver(Player *player);//prints the amount of gold a player has collected, takes player pointer as param
void update(Character &c);//updates player stats and board, take a reference to character object as param
void handleUserInput(Player *pPtr);//handles the user's input, takes player pointer as param
void checkSquare();//checks the current square
void look(Player *p);//print infomation about surrounding squares
void confirmMovement(unsigned int r, unsigned int c, Player *pPtr);//checks designated square to move to
void infoSquare(unsigned int r,unsigned int c,char ch);//prints information about squares
void exit();//exits the current game

/*********Board class************************************************ 
 * Description:
 * Stores BoardObject, Item and Characters.
 * The Board class accepts classes as T
 * Example:
 *   board<BoardObject>, boardItems<Item>, boardCharacters<Character>
 *************************************************************************/
template<typename T>//T class passed, BoardObject, Item or Character 
class Board //class for storing state of board
{
    public://board attributes, constructors, member functions
        std::vector<T> data;//vector for storing (BoardObject,Item,Character)
        const size_t cols;//the amount of columns for the board
        
        Board(size_t R, size_t C) : data(R*C), cols(C) {}//2 arg constructor for creating board size specified by R and C
        T operator()(size_t r, size_t c) const { return data[cols*r+c]; }//return object of template class (our case BoardObject, Item, Character)
        T& operator()(size_t r, size_t c) { return data[cols*r+c]; }//return address of template class (our case BoardObject, Item, Character)
        void move1(size_t r, size_t c,size_t r1, size_t c1)//args = current row and col, designated row and col
        { 
            data[cols*r+c].id = ' ';//replace previous square with id ' '
            r+= r1;//row index is offset by the coordinates given for arg r1
            c += c1;//col index is offset by the coordinates given for arg c1
            data[cols*r+c].id = 'P';//replace current square with id 'P'
            pPtr->r = r;//assign player's row based on row given
            pPtr->c = c;//assign player's col based on col given
        }
        char north(size_t r, size_t c)//return id of north square
        {
            return data[cols*(r-1)+(c+(0))].id;//return based on north coordinates
        }
        char south(size_t r, size_t c)//return id of south square
        {
            return data[cols*(r+(1))+(c+0)].id;//return based on south coordinates
        }
        char west(size_t r, size_t c)//return id of west square
        {
            return data[cols*(r+0)+(c-1)].id;//return based on west coordinates
        }

        char east(size_t r, size_t c)//return id of east square
        {
            return data[cols*(r+0)+(c+1)].id;//return based on east coordinates
        }
        char standingSquare(size_t r, size_t c)//return id of current square
        {
            return data[cols*(r)+(c)].id;//return based on current coordinates
        }
};//end Board class

/* Global*/
Board<BoardObject> board(numRows, numCols);//vector of BoardObject
Board<Item> boardItems(numRows, numCols);//vector of Item declared
Board<Enemy> boardCharacters(numRows, numCols);//vector of Enemy

int main(int argc, char** argv)//main function from where program starts
{
    srand(time(0));// seed srand with time(0)
    char playAgainChar;//char for storing y/n of user input to play again
    do//while player wants to play
    {
        createBoard();//create the board
        startup();//initiate start up sequence of selecting race and starting position
        pPtr = &p1;
        do//while(gameOverFlag==false)
        {
            handleUserInput(pPtr); //user enters a command
            dayNightCtr +=1;//increment day counter after user inputs a command
            if(dayNightCtr%10<5)//if daycounter remainder of mod 10 is 0-4
            {
                dayFlag= true;// it is day time
                std::cout << "it is day time\n";//print out
            }
            else if(dayNightCtr%10>=5)////if daycounter remainder of mod 10 is less than or greater than 4
            {
                dayFlag = false;// it is day time
                std::cout << "it is night time\n";//print out
            }
            if(isGameOver(pPtr)==true)//if player has died
            {
                gameOver(pPtr);//end the game and print out stats
                break;//break statement
            }
        }//end do while(gameOverFlag==false)
        while(gameOverFlag==false);//stay in loop while user is still playing
        std::cout << "game over\nplay again y/n\n";//print out
        std::cin>>playAgainChar;//store play again y/n char entered by user
        
        if(playAgainChar == 'y'){//the user opted to play again
           std::cout << "you have opted to play again\n";//print out
           playAgain = true;//the user opted to play again
        }
        else if(playAgainChar == 'n'){//the user opted not to play again
           std::cout << "you have opted not to play again\n";//print out
           playAgain = false;//the user did not opt to play again
        }
        else {//the user did not opt to play again
           std::cout << "you did not choose 'y', the game will now end\n";//print out
           playAgain = false;//the user did not opt to play again
        }
    }//end do while(playAgain==true)
    while(playAgain==true);//stay in loop while the player wants to play again
    std::cout << "Thank you for playing\n";//print out
    return 0;//return 0 for exiting main with no error
}

void createBoard()//creates the board
{
    for (size_t i=0; i<numRows; ++i)//for rows
    {
       for (size_t j=0; j<numCols; ++j)//for cols
       {
           unsigned int rand1 = rand()%5;//generate random val 0-4
           createBoardOject(rand1,i,j);//create board object
       }//end for j
    }//end for i
}//end createBoard()

//creates a random object on the board
void createBoardOject(unsigned int val, unsigned int row, unsigned int col)//args = random value, row, col
{
    if(row%numRows == 0 || row%numRows== numRows-1)//if its a wall boundary
    {
        board(row,col)= Wall();//assign boardObject
    }
    else if(col%numCols == 0 || col%numCols== numCols-1){//if its a wall boundary
        board(row,col)= Wall();//assign boardObject
    }
    else//if its not a wall boundary
    {
        switch(val)//switch on randomly generated value "val"
        {
            case 0://create item
            {
                board(row,col) = Item();//assign boardObject
                generateRandomItem(row,col);//generate random item for enemy
                break;//break statement
            }
            case 1://create enemy
            {
                board(row,col) = Enemy();//assign boardObject
                boardCharacters(row,col) = Enemy();//assign enemy to boardCharacters
                boardCharacters(row,col).generateItemForEnemy();//generate random item for enemy
                break;//break statement
            }
            case 2://create enemy
            { 
                board(row,col) = Enemy();//assign boardObject
                boardCharacters(row,col) = Enemy();//assign enemy to boardCharacters
                boardCharacters(row,col).generateItemForEnemy();//generate random item for enemy
                break;//break statement
            }
            case 3://create empty 
            {
                board(row,col) = Empty();//assign boardObject
                break;//break statement
            }
            default://create empty
            {
                Empty em1;//create boardObject
                board(row,col) = em1;//assign boardObject
                break;//break statement
            }    
        }//end switch(val)
    }//end else its not a wall boundary
}//end createBoardOject

//generates a random item
void generateRandomItem(unsigned int row, unsigned int col)//args = row, col
{
    unsigned int random = rand()%8;
    switch(random)//switch on random number generated between 0-7
    {
        case 0:// sword
        {
            boardItems(row,col) = Item(new Sword());//assign boardItems an item
        break;//break statement
        }
        case 1: // dagger
        {
            boardItems(row,col) = Item(new Dagger());//assign boardItems an item
        break;//break statement
        }
        case 2: // leather
        {
            boardItems(row,col) = Item(new LeatherArmour());//assign boardItems an item
        break;//break statement
        }
        case 3: // plate
        {
            boardItems(row,col) = Item(new PlateArmour());//assign boardItems an item
        break;//break statement
        }
        case 4: // large shield
        {
            boardItems(row,col) = Item(new LargeShield());//assign boardItems an item
        break;//break statement
        }
        case 5: // small shield
        {
            boardItems(row,col) = Item(new SmallShield());//assign boardItems an item
        break;//break statement
        }
        case 6: // ring of str
        {
            boardItems(row,col) = Item(new RingOfStrength());//assign boardItems an item
        break;//break statement
        }
        case 7: // ring of life
        {
            boardItems(row,col) = Item(new RingOfLife());//assign boardItems an item
        break;//break statement          
        }
    }
}//end generateRandomItem()

//prints the board
void printBoard()//prints the board for debugging
{
    for (size_t i = 0; i < numRows; i++)//iterate through rows
    {
        for (size_t j = 0; j < numCols; j++)//iterate through cols
        {
            std::cout << "["<< i << "][" << j << "]" << board(i,j).id << ", ";//print the type of Board Object
        }//end for j
        std::cout << '\n';//print new line
    }//end for i
}//end printBoard()

void startup(){
    //print out welcome message
    std::cout << "welcome to Group 8 Fantasy game\nCommands:\n"
            "'a' = attack\n'n' = move north \n's' = move south\n'e' = move east\n'w' = move west\n'x' = exit current game"
            "'p' = pickup item\n'i' = list inventory\n'd' = drop item\n'e' = exit game\n\nPlease enter number for selecting character race" << std::endl;
    std::cout << "1-Human\n2-Elf\n3-Dwarf\n4-Hobbit\n5-Dwarf" << std::endl;//print out
    raceSelection();//call function for player to enter race selection
    selectStartingPoint();//call function for player to select starting point
}

int raceSelection()//function for player to enter race selection
{
    bool validSelection = false;//stores the validity of the user selection
    unsigned int selection = -1;//stores the selection the user makes
    
    do//while (validSelection == false)
    {
        std::cin >> selection;//user enters selection of race
        if(selection < 1 || selection > 5)//if user selected an invalid race
        {
            std::cout << "invalid selection, please try again" << std::endl;//print out
            validSelection = false;//user entered invalid value
        }
        else//else user enters a valid choice
        {
            std::cout << "You have selected the race ";//print out
            switch(selection)//switch on user selection
            {
                case 1://case human race selected
                    std::cout << "Human\n";//print out
                    p1 = Player(0);//create player of type human
                    validSelection = true;//value entered was valid
                    break;//break statement
                case 2://case elf race selected
                    std::cout << "Elf\n";//print out
                    p1 = Player(1);//create player of type elf
                    validSelection = true;//value entered was valid
                    break;//break statement
                case 3://case dwarf race selected
                    std::cout << "Dwarf\n";//print out
                    p1 = Player(2);//create player of type dwarf
                    validSelection = true;//value entered was valid
                    break;//break statement
                case 4://case hobbit race selected
                    std::cout << "Hobbit\n";//print out
                     p1 = Player(3);//create player of type hobbit
                     validSelection = true;//value entered was valid
                    break;//break statement
                case 5://case orc race selected
                    std::cout << "Orc\n";//print out
                    p1 = Player(4);//create player of type orc
                    validSelection = true;//value entered was valid
                    break;//break statement
                default://case default
                    validSelection = false;//value entered was invalid
                    break;//break statement
            }//end switch(selection)
            validSelection = true;//value entered was valid
            pPtr = &p1;//assign global player pointer the address of the created player
        }//end else choice was valid
    }//end do while (validSelection == false)
    while (validSelection == false);//stay in loop while user enters invalid choices
    return selection;//return the 
}

void selectStartingPoint()//use selects their starting point on the board
{
    std::cout << "please select a valid starting point by indicating x and y coordinates\n (0 is the first index in a row or column)"<< std::endl;//print out
    unsigned int row = -1;//stores row the user selects
    unsigned int col = -1;//stores col the user selects
    bool validSelection = false;//stores status of valid selection
    do//while (validSelection == false)
    {
        std::cout << "Enter row" << std::endl;//print out
        std::cin >> row;//store users row selection
        std::cout << "Enter col" << std::endl;//print out
        std::cin >> col;//store users col selection
        if(row <= 0 || row > numRows-1 || col <=0 || col > numCols-1)//boundary checking
        {
            std::cout << "square is out of bounds, please try again" << std::endl;//print out
        }
        else
        {
            std::cout << "You have selected a valid starting point, the game will now begin" << std::endl;//print out 
            pPtr->r = row;//assign player's row updated row
            pPtr->c = col;//assign player's col updated col
            unsigned int r = pPtr->r;//assign player's row to r
            unsigned int c = pPtr->c;//assign player's col to c
            confirmMovement(r, c , pPtr);//function 
            validSelection = true;//user entered a vlid selection
        }
    }//end do while (validSelection == false)
    while (validSelection == false);
}

void handleUserInput(Player *pPtr)//args = player pointer
{
    bool valid = true;//boolean determines if user entered valid input
    char input;//stores input of the user
    unsigned int tRow = pPtr->r;//assign player's row to tRow
    unsigned int tCol = pPtr->c;//assign player's col to tCol
    Item iPtr;//item pointer
    Character *ePtr;//character pointer for enemy
    std::cout<<"please enter command"<< std::endl;//print out
    do//do while(valid == false)
    {
        std::cin >> input;//store input of user in input char
        switch(input)//switch on user input
        {
            case 'w'://case user enters w
            {
                confirmMovement(tRow,tCol-1, pPtr);//function moves the player
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 's'://case user enters s
            {
                confirmMovement(tRow+1,tCol, pPtr);//function moves the player
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'e'://case user enters e
            {
                confirmMovement(tRow,tCol+1, pPtr);//function moves the player  
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'n'://case user enters n
            {
                confirmMovement(tRow-1,tCol, pPtr);//function moves the player
                break;//break statment
            }
            case 'p'://case user enters p
            {
                std::cout<<"****pickup****"<< std::endl;//print out
                if(board(tRow,tCol).id=='I')//if the current square is an item
                {
                    iPtr = boardItems(tRow,tCol);//iPtr points to Item on the square
                    if(pPtr->pickup(&iPtr)==true)//if the user has enough strength to pickup item
                    {
                         board(tRow,tCol).id = 'P';//assign P char to board
                    }
                    else//insufficient strength to pick up item
                    {
                         std::cout<<"insufficient strength to pick up item"<< std::endl;//print out
                    }
                }//endif(board(tRow,tCol).id=='I')
                else{
                    std::cout<<"There is no item here to pickup"<< std::endl;//print out
                }
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'c'://case user enters c
            {
                pPtr->displayStats();//print player stats
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'd'://case user enters d
            {
                std::cout<<"****drop****"<< std::endl;//print out
                std::cout<<"choose type of item to drop by selecting corresponding index\n1-Weapon\n2-Armour\n3-Shield\n4-Rings"<< std::endl;//print out
                unsigned int choice;//stores the choice the user enters
                bool validChoice = false;//validChoice boolean for determining if user entered a valid choice
                do//do while(validChoice ==false)
                {
                    std::cin>> choice;//store user input in choice variable
                    if(choice > 0 || choice < 5)//if user selects item to drop within limits specifief
                    {
                        pPtr->drop(choice);
                        valid = true;//assign user entered a valid choice to valid
                        break;//break statment
                    }
                    else
                    {
                        validChoice = false;//assign user entered invalid choice to valid
                        std::cout<<"Invalid choice, please select from within the index specified"<< std::endl;//print out
                    }
                }//end do while(validChoice ==false)
                while(validChoice ==false);//stay in loop if user enters invalid choice
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'a'://case user enters a
            {
                std::cout<<"****attack****"<< std::endl;//print out
                if(board(tRow,tCol).id=='E'){
                    ePtr = &boardCharacters(tRow,tCol);
                    attackRound(pPtr,ePtr);
                }
                else
                    std::cout << "there is no enemy here to attack\n";//print out
                
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'l'://case user enters l
            {
                look(pPtr);
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'i'://case user enters i
            {
                std::cout<<"inventory"<< std::endl;//print out
                p1.displayStats2();
                valid = true;//assign user entered a valid choice to valid
                break;//break statment
            }
            case 'x': //case user enters x
            {
                std::cout<<"exit!"<< std::endl;//print out
                exit();//function exits game
                break;//break statment
            }
            default://default case
            {
                std::cout<<"not a valid command"<< std::endl;//print out
                valid = false;//assign false to valid
                break;//break statement
            }
        }//end switch(input)
    }//end do while(valid == false)
    while(valid == false);//keep in loop while user enters invalid arguments
}//end handleUserInput

void exit()//exits the current game
{
    gameOverFlag = true;//assigning true breaks while loop in main function
}//end exit()
    
void confirmMovement(unsigned int r,unsigned int c, Player *pPtr)//args = row, col, player pointer
{
    char ds = board(r,c).id;//ds stores id of designated square
    switch(ds)
    {
        case 'W'://case square is a wall
            std::cout<<"you try to move but a wall impedes your path"<< std::endl;//print out
        break;
        case 'E'://case square is an enemy
        {
            std::cout<<"you are standing beside an enemy"<< std::endl;//print out
            pPtr->r = r;//update player's row
            pPtr->c = c;//update player's col
            break;//break statement
        }
        case 'I'://case square is an item
        {
            std::cout<<"you are standing beside an item"<< std::endl;
            pPtr->r = r;//update player's row
            pPtr->c = c;//update player's col
            break;//break statement
        }
        case ' '://case square is empty
        {
            std::cout<<"you are standing on an empty square"<< std::endl;
            pPtr->r = r;//update player's row
            pPtr->c = c;//update player's col
            board(r,c).id = 'P';//assign player identity to empty square
            break;//break statement
        }
        default://default case
            std::cout<<"you are standing on an empty square"<< std::endl;//print out
            pPtr->r = r;//update player's row
            pPtr->c = c;//update player's col
            board(r,c).id = 'P';//assign player identity to empty square        
            break;//break statement
    }//end switch(ds) 
}//end confirmMovement()

void look(Player *p)//args = player pointer
{
    char ch;// stores the id of the boardObject
    unsigned int row = p->r;//store the row the player is standing on
    unsigned int col = p->c;//store the col the player is standing on
    std::cout<< "****Look****" << std::endl;//print "****Look****"
    
    ch = board.north(row,col);//print square status
    std::cout<< "you look north and see " << std::endl;//print "you look north and see "
    infoSquare(row-1,col,ch);//print square status
    
    ch = board.south(row,col);//print square status
    std::cout<< "\nyou look south and see " << std::endl;//print "you look south and see "
    infoSquare(row+1,col,ch);//print square status
    
    ch = board.east(row,col);//print square status
    std::cout<< "\nyou look east and see " << std::endl;//print "you look east and see "
    infoSquare(row,col+1,ch);//print square status
    
    ch = board.west(row,col);//print square status
    std::cout<< "\nyou look west and see " << std::endl;//print "you look west and see "
    infoSquare(row,col-1,ch);
    ch = board.standingSquare(row,col);//print square status
    std::cout<< "\nyou look at the current square and see " << std::endl;//print "you look north and see "
    infoSquare(row,col,ch);//print square status
}

void infoSquare(unsigned int r,unsigned int c,char ch)//args = row index, col index, id of current square
{
    switch(ch)//switch based on the id of the boardObject
    {
        case 'W'://square is a wall
            std::cout<< "a wall:\n " << std::endl;//print out square status
        break;//break statement
        case 'E'://square is an enemy
            std::cout<< "an enemy:\n ";//print out square status
            boardCharacters(r,c).displayStats();//display enemy stats
        break;//break statement
        case 'I'://square is an item
            std::cout<< "an Item:\n";//print out square status
            std::cout<< "Name: " << boardItems(r,c).name <<std::endl;//print item stats
            std::cout << "Weight: " << boardItems(r,c).weight <<std::endl;//print item stats
            std::cout << "Attack mod: " << boardItems(r,c).atk <<std::endl;//print item stats
            std::cout << "Defence mod: " << boardItems(r,c).def <<std::endl;//print item stats
            std::cout << "Health mod: " << boardItems(r,c).health <<std::endl;//print item stats
            std::cout << "Strength mod: " << boardItems(r,c).strength <<std::endl;//print item stats
        break;//break statement
        case ' '://case blank square
            std::cout<< "an Empty square:\n";// print out square status
        break;//break statement
        default://default square
            std::cout<< "an Empty square:\n";// print out square status
        break;//break statement
    }//end switch(ch)
}//end infoSquare()

void attackRound(Player *player, Character *enemy)//args = player pointer, enemy pointer
{
    std::cout << "You try to attack the enemy:\n";
    player->attack(enemy,dayFlag);//player attacks enemy
    if(isEnemyDefeated(enemy)==true)//if enemy has been defeated
    {
        std::cout << "You have slain the enemy\n";
        board(pPtr->r,pPtr->c).id = ' ';//assign blank to square of defeated enemy
        pPtr->gold += boardCharacters(pPtr->r,pPtr->c).def;//update player's gold by factor of enemy's weight
        std::cout << "your now have " << pPtr->gold << " gold \n";//print out gold amount
    }//endif(isEnemyDefeated(enemy)==true)
    else if(isEnemyDefeated(enemy)==false)//if enemy is still alive after attacking
    {
        std::cout << "Enemy attacks:\n";//print out
        enemy->attack(player,dayFlag);//enemy attacks player, pass dayFlag boolean to attack function
        std::cout << "Your stats:\n";//print out
        player->displayStats();//print player's stats
        std::cout << "Enemy stats:\n";//print out
        enemy->displayStats();//print enemy's stats
    }//endif (isEnemyDefeated(enemy)==false
}//end attackRound()

bool isGameOver(Player *player)//args = player pointer
{
    if(player->health <=0)//if the player has died
        return true;//return true if player has died
    else 
        return false;//return false if player is alive
}

void gameOver(Player *player)//args = player pointer
{
    std::cout << "You have been defeated, thank you for playing\n"<<std::endl;//print out
    std::cout << "You collected "<< player->gold << " gold\n" << std::endl;//print out gold amount
}

bool isEnemyDefeated(Character *enemy)//args = enemy pointer
{
    if(enemy->health<=0)//if enemy has died
        return true;//return enemy is defeated
    else
        return false;//return enemy is not defeated
}

