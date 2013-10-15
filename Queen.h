#ifndef _QUEEN_H
#define _QUEEN_H
#include "Figure.h"

class Queen : public Figure
{
public:
    Queen(char cColor) : Figure(cColor) {}
    ~Queen() {}
private:
    virtual char GetPiece();
    bool AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]);
};
#endif
