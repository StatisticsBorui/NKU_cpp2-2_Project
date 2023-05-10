#include "szhrd.h"

bool Szhrd::ok(){
    if(isSolved()){
        return false;
    }
    int*check = new int[row*col];
    int count = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(board[i][j] != 0){
                check[count] = board[i][j];
                count++;
            }
        }
    }
    int num = 0;
    for(int i = 0; i < count - 1; i++){
        for(int j = i + 1; j < count; j++){
            if(check[i] > check[j]){
                num++;
            }
        }
    }
    delete[]check;
    num += (row - x0 - 1)*(col - 1);
    if(num % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}

void Szhrd::makeBoard(){
    for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == row - 1 && j == col - 1) {
                    break;
                }
                board[i][j] = i * col + j + 1;
            }
        }
    board[row - 1][col - 1] = 0;
    srand(time(0));
    do{
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int x = i + rand() % (row - i);
                int y = j + rand() % (col - j);
                swap(board[i][j], board[x][y]);
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if(board[i][j] == 0){
                    x0 = i;
                    y0 = j;
                    break;
                }
            }
        }
    }while(!ok());
}

void Szhrd::swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Szhrd::PressUp(){
    if(x0 < row - 1){
        swap(board[x0][y0],board[x0+1][y0]);
        x0++;
        steps++;
    }
}
void Szhrd::PressRight(){
    if(y0 > 0){
        swap(board[x0][y0],board[x0][y0-1]);
        y0--;
        steps++;
    }
}
void Szhrd::PressDown(){
    if(x0 > 0){
        swap(board[x0][y0],board[x0-1][y0]);
        x0--;
        steps++;
    }
}
void Szhrd::PressLeft(){
    if(y0 < col - 1){
        swap(board[x0][y0],board[x0][y0+1]);
        y0++;
        steps++;
    }
}

bool Szhrd::isSolved(){
    int count = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (board[i][j] != count && !(i == row - 1 && j == col - 1)) {
                return false;
            }
            count++;
        }
    }
    return true;
}

int Szhrd::getBoard(int i,int j){
    return board[i][j];
}

void Szhrd::clear(){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            board[i][j] = 0;
        }
    }
}
int Szhrd::getStep(){
    return steps;
}
void Szhrd::vipmakeBoard(){
    for(int i = 0; i < row - 1; i++)
        for(int j = 0; j < col; j++){
            board[i][j] = i * col + j + 1;
        }
    for(int j = 0; j < col-2; j++){
        board[row-1][j] = (row - 1) * col + j + 1;
    }
    board[row-1][col-2] = 0;
    board[row-1][col-1] = row * col - 1;
    x0 = row - 1;
    y0 = col - 2;
}
