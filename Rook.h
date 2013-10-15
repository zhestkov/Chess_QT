#ifndef _ROOK_H
#define _ROOK_H
#include "Figure.h"

class Rook : public Figure
{
public:
    Rook(char cColor) : Figure(cColor) {}
    ~Rook() {}
private:
    virtual char GetPiece();
    bool AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]);
};
#endif
