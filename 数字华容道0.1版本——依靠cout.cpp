#include <iostream>
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
    void showboard();
    void makemap();
    bool move(int,int);
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
    board[row - 1][col - 1] = 0;
    srand(time(0));    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int x = i + rand() % (row - i);
            int y = j + rand() % (col - j);
            swap(board[i][j], board[x][y]);
        }
    }
}
bool SzhrdGame::isSolved() {
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
void SzhrdGame::showboard() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
bool SzhrdGame::move(int a, int b) {
    int x = a - 1;
    int y = b - 1;
    bool flag = true;
    if (x > 0 && board[x - 1][y] == 0) {
        swap(board[x][y], board[x - 1][y]);
    }
    else if (x < row-1 && board[x + 1][y] == 0) {
        swap(board[x][y], board[x + 1][y]);
    }
    else if (y > 0 && board[x][y - 1] == 0) {
        swap(board[x][y], board[x][y - 1]);
    }
    else if (y < col-1 && board[x][y + 1] == 0) {
        swap(board[x][y], board[x][y + 1]);
    }
    else {
        flag = false;
    }
    return flag;
}
int put() {
    int x;
    cin >> x;
    return x;
}
int main() {
    SzhrdGame a(2, 2);
    a.makeboard();
    
    while (!a.isSolved()) {
        a.showboard();
        int x, y;
        cin >> x >> y;
        bool c = a.move(x, y);
    }
    cout << "victory";
    return 0;
}