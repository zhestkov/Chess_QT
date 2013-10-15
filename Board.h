#ifndef _BOARD_H
#define _BOARD_H
#include "Figure.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Pawn.h"
class Board
{

public:
    Board();
    ~Board();
    Figure* ChessBoard[8][8];
    bool IsInCheck(char cColor);
    bool CanMove(char cColor);
    bool Stalemate();
    void setfigure(int x, int y,int c, char color); // 0 - Bishop, 1 - Knight, 2 - Rook, 3 - Queen

};

#endif
