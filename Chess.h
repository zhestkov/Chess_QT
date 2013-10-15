#ifndef _CHESS_H
#define _CHESS_H
#include <iostream>
#include "Board.h"
#include "Figure.h"


class Chess
{
    //private:
public:

    Board GameBoard;
    char cPlayerTurn;
    int cnt;
    int k1,k2; // X,Y � CheckNew ��� White
    int k3,k4; // X,Y � CheckNew ��� Black
    int cntEnpW;// ����� ����, ����� �������� WhitePlayer ����� ������� ������ �� �������
    int cntEnpB;// ����� ����, ����� �������� BlackPlayer ����� ������� ������ �� �������
    Chess() : cPlayerTurn('W') {
    cnt = 0;
    }
    ~Chess() {}

    void GetNextMove(int iStartX, int iStartY, int iEndX, int iEndY, Figure* ChessBoard[8][8]);
    void AlternateTurn();
    int CheckNew(Figure* ChessBoard[8][8]);
    void CheckCastl(Figure* ChessBoard[8][8]);
    bool IsGameOver();
    void start();


};
#endif
