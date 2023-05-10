#ifndef SZHRD_H
#define SZHRD_H

#include <iostream>
#include "lesson1.h"
#include <QSound>
#include <QMediaPlayer>



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

        sound2 -> setMedia(QUrl::fromLocalFile("C://Users//54016//Desktop//QtSzhrdGame//SzhrdGame//background.mp3"));
        sound2 -> setVolume(50);

        sound -> setMedia(QUrl::fromLocalFile("C://Users//54016//Desktop//QtSzhrdGame//SzhrdGame//1.wav"));
        sound -> setVolume(50);
    }
    ~Szhrd(){
        for(int i = 0; i < row; i++){
            delete[] board[i];
        }
        delete[] board;
        sound2 -> stop();
        delete sound2;
        delete sound;
    }


    int getBoard(int,int);
    //Game
    void makeBoard();
    bool isSolved();
    void swap(int&,int&);
    bool ok();
    void clear();
    int getStep();
    void vipmakeBoard();
    void playmusic();
    void closemusic();
    void resetSteps();

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

    QMediaPlayer *sound2 = new QMediaPlayer;
    QMediaPlayer * sound = new QMediaPlayer;

};
Q_DECLARE_METATYPE(Szhrd);
#endif // SZHRD_H
