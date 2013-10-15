#ifndef _FIGURE_H
#define _FIGURE_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>



using namespace std;


class Figure
{
public:
    int cnt;
    Figure(char cColor) : mcColor(cColor) { cnt = 0; }
    ~Figure() {}
    virtual char GetPiece() = 0;
    char GetColor();
    bool IsLegalMove(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]);
private:
    virtual bool AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) = 0;
    char mcColor;
};



#endif
