#include "Rook.h"

char Rook::GetPiece() {
    return 'R';
}

bool Rook::AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) {
    if (x == x1) {
        // убедимся, что все поля для хода не содержат своих же фигур
        int yOffset = (y1 - y > 0) ? 1 : -1;
        for (int yCheck = y + yOffset; yCheck !=  y1; yCheck += yOffset) {
            if (ChessBoard[x][yCheck] != 0) {
                return false;
            }
        }
        return true;
    } else if (y1 == y) {
        int xOffset = (x1 - x > 0) ? 1 : -1;
        for (int xCheck = x + xOffset; xCheck != x1; xCheck += xOffset) {
            if (ChessBoard[xCheck][y] != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}
