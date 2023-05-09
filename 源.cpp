#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
class SzhrdGame {
private:
    int row;
    int col;
    int steps = 0;
    int **board;
public:
    SzhrdGame(int r,int c) {
        row = r;
        col = c;
        board = new int*[r];
        for (int i = 0; i < c; i++) {
            board[i] = new int[c];
        }
    }
    ~SzhrdGame()
    {
        for (int i = 0; i < row; i++) {
            delete[] board[i];
        }
        delete[] board;
    }
    void makeboard();
    void makemap();
    void move();
    void restart();
    void victory();
    bool isSolved();
};
void SzhrdGame::makeboard() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == row - 1 && j == col - 1) {
                break;
            }
            board[i][j] = i * col + j + 1;
        }
    }
    board[row - 1][col - 1] == 0;
    srand(time(0));    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int x = i + rand() % (row - i);
            int y = j + rand() % (col - j);
            swap(board[i][j], board[x][y]);
        }
    }
}
bool SzhrdGame :: isSolved() {
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
