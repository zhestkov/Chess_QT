#ifndef _PAWN_H
#define _PAWN_H
#include "Figure.h"

class Pawn : public Figure
{
public:
    Pawn(char cColor) : Figure(cColor) {}
    ~Pawn() {}
private:
    virtual char GetPiece();
    bool AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]);
};
#endif



// En passant
// B-      BW      --
// --  =>  --  =>  -B
// -W      --      --
