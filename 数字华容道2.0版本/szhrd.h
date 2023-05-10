#ifndef SZHRD_H
#define SZHRD_H

#include <iostream>
#include "lesson1.h"

class Szhrd
{
public:
    Szhrd();
    Szhrd(int r,int c){
        row = r;
        col = c;
        board = new int*[r];
        for(int i = 0; i < r; i++){
            board[i] = new int[c];
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                board[i][j] = 0;
            }
        }
    }
    ~Szhrd(){
        for(int i = 0; i < row; i++){
            delete[] board[i];
        }
        delete[] board;
    }


    int getBoard(int,int);
    //Game
    void makeBoard();
    bool isSolved();
    void swap(int&,int&);
    bool ok();
    void clear();
    int getStep();

    //WASD
    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();
private:
    int row = 3;
    int col = 3;
    int **board;
    int steps = 0;
    int x0 = 0;
    int y0 = 0;
};
Q_DECLARE_METATYPE(Szhrd);
#endif // SZHRD_H
