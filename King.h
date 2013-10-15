#ifndef _KING_H
#define _KING_H
#include "Figure.h"

class King : public Figure
{
public:
    King(char cColor) : Figure(cColor) {}
    ~King() {}
private:
    virtual char GetPiece();
    bool AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]);
};
#endif
