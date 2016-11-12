#include <cstdlib>
#include <iostream>
#include <string>
#include <vector> 
#include "BoardObject.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include <ctime>

using namespace std;

/* Board class */
template<typename T>
class Board {
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

//prototype functions
int randomBoardObjectAssignment();
int randomItemTypeAssignment();
void createBoard();
void createBoardOject(int val,int row,int col,Board <BoardObject> &Arr2D);
void printBoard();

int main(int argc, char** argv) {
    srand(time(0));// seed srand with time(0)

    createBoard();//creates the board
        
    printBoard();//prints the board

    return 0;
}

//generates a random number for creating a type of board object
int randomBoardObjectAssignment(){ 
    int f = rand()%3;
    return f;
}

//generates a random number for creating a type of item
int randomItemTypeAssignment(){
    int f = rand()%9;
    return f;
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

//creates a random object on the board
void createBoardOject(int val, int row, int col, Board <BoardObject> &Arr2D){
    switch(val){
        case 0:
            Arr2D(row,col) = Enemy(row,col);
            break;
        case 1:
            Arr2D(row,col) = Player(row,col);
            break;
        case 2:
            Arr2D(row,col) = Item();
            break;
        case 3:
            break;
    }
}

//prints the board
void printBoard(){
    for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < numCols; j++) {
                std::cout << Arr2D(i,j).id << ", ";
            }
            std::cout << '\n';
        }
}