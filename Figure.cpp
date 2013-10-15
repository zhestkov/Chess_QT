#include "Figure.h"

char Figure::GetColor() {
    return mcColor;
}

bool Figure::IsLegalMove(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) {
    Figure* movePosition = ChessBoard[x1][y1];
    if ((movePosition == 0) || (mcColor != movePosition->GetColor())) {
        return AreSquaresLegal(x,y,x1,y1,ChessBoard);
    }
    return false;
}



