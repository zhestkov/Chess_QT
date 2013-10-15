#include "Pawn.h"

char Pawn::GetPiece() {
    return 'P';
}

bool Pawn::AreSquaresLegal(int x, int y, int x1, int y1, Figure* ChessBoard[8][8]) {
    Figure* movePosition = ChessBoard[x1][y1];
    // ���� ������ �����..
    if (movePosition == 0) {
        if (y == y1) {
            if (ChessBoard[x][y]->GetColor() == 'W') {
                // ��� �� 1 ������� ������ ��� ����� ������
                if (x1 == x + 1) {
                    return true;
                }
                // ��� �� 2 ������� ������, ���� ����� ������ �� ������� [1;y], �.�. � ��������� �������
                if ((x == 1)&&(x1 == x + 2)){
                    return true;
                }
            }else { //����������� ��� ������ �����
                if (x1 == x - 1){
                    return true;
                }
                if ((x == 6)&&(x1 == x -2)){
                    return true;
                }
            }
        }
    } else {
        if ((y1 == y + 1) || (y1 == y - 1)) {
            if (ChessBoard[x][y]->GetColor() == 'W') {
                if (x1 == x + 1) {
                    return true;
                }
            }else {
                if (x1 == x - 1) {
                        return true;
                }
            }
        }
    }
    return false;
}
