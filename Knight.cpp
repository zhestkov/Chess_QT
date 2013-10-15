#include "Knight.h"

char Knight::GetPiece() {
    return 'N';
}

bool Knight::AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) {
    // Клетка назначения не занята или занята фигурой соперника
    if ((y1 == y + 1) || (y1 == y - 1)) {
        if ((x1 == x + 2) || (x1 == x - 2)) {
            return true;
        }
    }
    if ((y1 == y + 2) || (y1 == y - 2)) {
        if ((x1 == x + 1) || (x1 == x - 1)) {
            return true;
        }
    }
    return false;
}
