#ifndef _KNIGHT_H
#define _KNIGHT_H
#include "Figure.h"

class Knight : public Figure
{
public:
    Knight(char cColor) : Figure(cColor) {}
    ~Knight() {}
private:
    virtual char GetPiece();
    bool AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]);
};
#endif
