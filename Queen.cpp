#include "Queen.h"

char Queen::GetPiece() {
    return 'Q';
}

bool Queen::AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) {
    if (x1 == x) {
        int yOffset = (y1 - y > 0) ? 1 : -1;
        for (int yCheck = y + yOffset; yCheck != y1; yCheck += yOffset) {
            if (ChessBoard[x][yCheck] != 0) {
                return false;
            }
        }
        return true;
    } else if (y1 == y) {
        int xOffset = (x1 - x > 0) ? 1 : -1;
        for (int xCheck = x + xOffset; xCheck !=  x1; xCheck += xOffset) {
            if (ChessBoard[xCheck][y] != 0) {
                return false;
            }
        }
        return true;
    } else if ((y1 - y == x1 - x) || (y1 - y == x - x1)) {
        int xOffset = (x1 - x > 0) ? 1 : -1;
        int yOffset = (y1 - y > 0) ? 1 : -1;
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
