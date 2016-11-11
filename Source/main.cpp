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

template<typename T>
class Board {
    std::vector<T> data;
    const size_t cols;
public:
    Board(size_t R, size_t C) : data(R*C), cols(C) {}
    T operator()(size_t r, size_t c) const { return data[cols*r+c]; }
    T& operator()(size_t r, size_t c) { return data[cols*r+c]; }
};
const size_t numRows = 8;
const size_t numCols = 8;
Board<BoardObject> Arr2D(numRows, numCols);

int randomAssignment();
void createBoardOject(int val,int row,int col,Board <BoardObject> &Arr2D);
void printBoard();

int main(int argc, char** argv) {
    srand(time(0));// seed srand with time(0)

    for (size_t i=0; i<numRows; ++i)
    {
       int ii = i;
       for (size_t j=0; j<numCols; ++j)
       {
           int rand = randomAssignment();
           createBoardOject(rand,i,j,Arr2D);
       }
    }
        
    printBoard();

    return 0;
}

int randomAssignment(){
    int fMin = 0;
    int fMax = 100;  
    int f = rand()%3;
    return f;
}

void createBoardOject(int val, int row, int col, Board <BoardObject> &Arr2D){
    switch(val){
        case 0:
            Arr2D(row,col) = Enemy(row,col);
            break;
        case 1:
            Arr2D(row,col) = Player(row,col);
            break;
        case 2:
            Arr2D(row,col) = Enemy(row,col);
            break;
        case 3:
            break;
    }
}

void printBoard(){
    for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < numCols; j++) {
                std::cout << Arr2D(i,j).id << ", ";
            }
            std::cout << '\n';
        }
}