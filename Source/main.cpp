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

void randomAssignment();
void createBoardOject(int val);

template<typename T>
class Board {
        std::vector<T> data;
        const size_t cols;
public:
        Board(size_t R, size_t C) : data(R*C), cols(C) {}
        T operator()(size_t r, size_t c) const { return data[cols*r+c]; }
        T& operator()(size_t r, size_t c) { return data[cols*r+c]; }
};

int main(int argc, char** argv) {
   srand(time(0));// seed srand with time(0)
        const size_t numRows = 8;
        const size_t numCols = 8;
        Board<BoardObject> Arr2D(numRows, numCols);

        for (size_t i=0; i<numRows; ++i)
        {
            int ii = i;
           for (size_t j=0; j<numCols; ++j){
               randomAssignment();
                Arr2D(i,j) = Enemy(i,j);
           }
        }
        
        for (size_t i = 0; i < numRows; i++) {
            for (size_t j = 0; j < numCols; j++) {
                //std::cout << Arr2D(i,j).id << ", ";
            }
            std::cout << '\n';
        }

    return 0;
}

void randomAssignment(){
    int fMin = 0;
    int fMax = 100;
    
    int f = rand()%3;
    //std::cout<< "generated: " << f << std::endl;
    createBoardOject(f);
}

void createBoardOject(int val){
    switch(val){
        case 0:
            //std::cout << "0 here" << endl;// empty
            break;
        case 1:
           // std::cout << "1 here" << endl;// items
            break;
        case 2:
           // std::cout << "2 here" << endl;//enemy
            break;
        case 3:
            break;
    }
}