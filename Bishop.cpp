#include "Bishop.h"



char Bishop::GetPiece() {
    return 'B';
}
bool Bishop::AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) {
    if ((y1 - y == x1 - x) || (y1 - y == x - x1)) {
        int xOffset = (x1 - x > 0) ? 1 : -1;
        int yOffset = (y1 - y> 0) ? 1 : -1;
        int xCheck;
        int yCheck;
        for (xCheck = x + xOffset, yCheck = y + yOffset;
            xCheck !=  x1;
            xCheck += xOffset, yCheck += yOffset)
        {
            if (ChessBoard[xCheck][yCheck] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}
