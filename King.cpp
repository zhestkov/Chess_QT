#include "King.h"

char King::GetPiece() {
    return 'K';
}

bool King::AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) {
    if ( x1 == x && cnt == 0 ) {
        if (y1 - y == 2 || y1 - y == -2){
            int yOffset = (y1 - y > 0) ? 1 : -1;
            for (int yCheck = y + yOffset; yCheck !=  y1; yCheck += yOffset) {
                if (ChessBoard[x][yCheck] != 0)
                    return false;
            }
            return true;
         }
      }


    int xDelta = x1 - x;
    int yDelta = y1 - y;
    if (((xDelta >= -1) && (xDelta <= 1)) &&
        ((yDelta >= -1) && (yDelta <= 1)))
        return true;

    return false;
}


