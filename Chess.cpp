#include "Chess.h"


void Chess::GetNextMove(int iStartX, int iStartY, int iEndX, int iEndY, Figure* ChessBoard[8][8]) {
    bool bValidMove = false;

        if ((iStartX >= 0 && iStartX <= 7) &&
            (iStartY >= 0 && iStartY <= 7) &&
            (iEndX >= 0 && iEndX <= 7) &&
            (iEndY >= 0 && iEndY <= 7)) {
            Figure* curPiece = ChessBoard[iStartX][iStartY];

            // �������� �����
            if ((curPiece != 0) && (curPiece->GetColor() == cPlayerTurn)) {
                // �������� ����������� ����
                if (curPiece->IsLegalMove(iStartX, iStartY, iEndX, iEndY, ChessBoard)) {
                    // �����...
                    Figure* temp = ChessBoard[iEndX][iEndY];
                    ChessBoard[iEndX][iEndY] = ChessBoard[iStartX][iStartY];
                    ChessBoard[iStartX][iStartY] = 0;
                    // ��������, ��� ������� ����� �� ����� ���
                    if (!GameBoard.IsInCheck(cPlayerTurn)) {
                        // �������� ������ �� �������
                        if (curPiece->GetColor()=='W' && curPiece->GetPiece() == 'P'){
                            if (iEndX == iStartX + 2)
                                cntEnpB = cnt;
                        }
                        if (curPiece->GetColor() == 'B' && curPiece->GetPiece() == 'P'){
                            if (iEndX == iStartX - 2)
                                cntEnpW == cnt;
                        }
                        cnt++; // ���� ��� ��������, �� ����������� ������� �����
                        curPiece->cnt++;
                        delete temp;
                        bValidMove = true;
                        //CheckCastl(GameBoard.ChessBoard);
                        AlternateTurn();
                    } else { // �����,���� ��� �������� � ����, �������� ��������� ���...
                        ChessBoard[iStartX][iStartY] = ChessBoard[iEndX][iEndY];
                        ChessBoard[iEndX][iEndY]		= temp;
                    }
                }
            }
        }




        if (!bValidMove) {
            cout << "Invalid Move!" << endl;
        }

    
}


void Chess::AlternateTurn() {
    cPlayerTurn = (cPlayerTurn == 'W') ? 'B' : 'W';
}

// ������� �������� ����������� ����������� ����� � ������ ������
int Chess::CheckNew(Figure* ChessBoard[8][8]){
    for (int x=0;x<8;++x){
        for (int y=0;y<8;++y){
            if (ChessBoard[x][y] != 0){
                if (ChessBoard[x][y]->GetColor() =='W')
                    if (ChessBoard[x][y]->GetPiece() == 'P')
                        if (x == 7){
                            k1 = x;
                            k2 = y;
                            return 1;
                            }  // ���� WhitePlayer ����� ��������� ����� ������ ������ �����



                if (ChessBoard[x][y]->GetColor() =='B')
                    if (ChessBoard[x][y]->GetPiece() == 'P')
                        if (x == 0){
                            k3 = x;
                            k4 = y;
                            return 2; //  ���� BlackPlayer ����� ��������� ����� ������ ������ �����
                  }
            }
        }
    }
    return 0;
}

void Chess::CheckCastl(Figure* ChessBoard[8][8]){
    if (cPlayerTurn == 'W'){
        if (ChessBoard[0][1]->GetPiece() == 'K' && ChessBoard[0][1]->cnt == 1)
            if (ChessBoard[0][0]->GetPiece() == 'R' && ChessBoard[0][0]->cnt == 0){
                ChessBoard[0][2] = ChessBoard[0][0];
                ChessBoard[0][0] = 0;

            }
        if (ChessBoard[0][5]->GetPiece() == 'K' && ChessBoard[0][5]->cnt == 1)
            if (ChessBoard[0][7]->GetPiece() == 'R' && ChessBoard[0][7]->cnt == 0){
                ChessBoard[0][4] = ChessBoard[0][7];
                ChessBoard[0][7] = 0;

            }
         }
    if (cPlayerTurn == 'B'){
        if (ChessBoard[7][1]->GetPiece() == 'K' && ChessBoard[7][1]->cnt == 1)
            if (ChessBoard[7][0]->GetPiece() == 'R' && ChessBoard[7][0]->cnt == 0){
                ChessBoard[7][2] = ChessBoard[7][0];
                ChessBoard[7][0] = 0;

            }
        if (ChessBoard[7][5]->GetPiece() == 'K' && ChessBoard[7][5]->cnt == 1)
            if (ChessBoard[7][7]->GetPiece() == 'R' && ChessBoard[7][7]->cnt == 0){
                ChessBoard[7][4] = ChessBoard[0][7];
                ChessBoard[7][7] = 0;

            }
         }
}

bool Chess::IsGameOver() {
    // ���������, ��� ������� ����� ����� ������
    // ���� ��� - ����� ��� ���
    bool bCanMove(false);
    bool bStalemate(false);
    bCanMove = GameBoard.CanMove(cPlayerTurn);
    bStalemate = GameBoard.Stalemate();
    if (bStalemate){
        cout<<"Stalemate!"<<endl;
        return bStalemate;
    }
    if (!bCanMove) {
        if (GameBoard.IsInCheck(cPlayerTurn)) {
            AlternateTurn();
            cout << "Checkmate, " << cPlayerTurn << " Wins!" <<endl;
        } else
            cout << "Stalemate!" <<endl;
    }
    return !bCanMove;
}
