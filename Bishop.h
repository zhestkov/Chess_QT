#ifndef _BISHOP_H
#define _BISHOP_H
#include "Figure.h"


class Bishop : public Figure
{
public:
    Bishop(char cColor) : Figure(cColor) {}
    ~Bishop() {}
private:
    virtual char GetPiece();
    bool AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]);
};

#endif
