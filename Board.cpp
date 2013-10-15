#include "Board.h"


Board::Board() {
    for (int x = 0; x < 8; ++x){
        for (int y = 0; y < 8; ++y){
            ChessBoard[x][y] = 0;
        }
    }

    // Расставляем черные фигуры
    for (int y = 0; y < 8; ++y)
        ChessBoard[6][y] = new Pawn('B');
    ChessBoard[7][0] = new Rook('B');
    ChessBoard[7][1] = new Knight('B');
    ChessBoard[7][2] = new Bishop('B');
    ChessBoard[7][3] = new King('B');
    ChessBoard[7][4] = new Queen('B');
    ChessBoard[7][5] = new Bishop('B');
    ChessBoard[7][6] = new Knight('B');
    ChessBoard[7][7] = new Rook('B');

    // Расставляем белые фигуры
    for (int y = 0; y < 8; ++y)
        ChessBoard[1][y] = new Pawn('W');
    ChessBoard[0][0] = new Rook('W');
    ChessBoard[0][1] = new Knight('W');
    ChessBoard[0][2] = new Bishop('W');
    ChessBoard[0][3] = new King('W');
    ChessBoard[0][4] = new Queen('W');
    ChessBoard[0][5] = new Bishop('W');
    ChessBoard[0][6] = new Knight('W');
    ChessBoard[0][7] = new Rook('W');
}

Board::~Board() {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            delete ChessBoard[x][y];
            ChessBoard[x][y] = 0;
        }
    }
}



bool Board::IsInCheck(char cColor) {
    // Находим короля
    int xKing;
    int yKing;
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (ChessBoard[x][y] != 0) {
                if (ChessBoard[x][y]->GetColor() == cColor) {
                    if (ChessBoard[x][y]->GetPiece() == 'K') {
                        xKing = x;
                        yKing = y;
                    }
                }
            }
        }
    }


    // Проверяем фигуры соперника, может ли хотя бы одна 'срубить' короля
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (ChessBoard[x][y] != 0) {
                if (ChessBoard[x][y]->GetColor() != cColor) {
                    if (ChessBoard[x][y]->IsLegalMove(x, y, xKing, yKing, ChessBoard)) {
                        //cout<<"Check for "<<ChessBoard[x][y]->GetColor()<<"'s King!"<<endl;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}



bool Board::CanMove(char cColor) {
    // Проверяем все фигуры
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (ChessBoard[x][y] != 0) {
                // Если это фигура текущего игрока, может ли она сделать ход
                if (ChessBoard[x][y]->GetColor() == cColor) {
                    for (int xMove = 0; xMove < 8; ++xMove) {
                        for (int yMove = 0; yMove < 8; ++yMove) {
                            if (ChessBoard[x][y]->IsLegalMove(x, y, xMove, yMove, ChessBoard)) {
                                // Делаем ход и проверяем будет ли шах королю
                                Figure* temp = ChessBoard[xMove][yMove];
                                ChessBoard[xMove][yMove] = ChessBoard[x][y];
                                ChessBoard[x][y] = 0;
                                bool bCanMove = !IsInCheck(cColor);
                                // Отменяем ход
                                ChessBoard[x][y] = ChessBoard[xMove][yMove];
                                ChessBoard[xMove][yMove] = temp;
                                if (bCanMove) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}



// проверка ничьи
bool Board::Stalemate(){
    int cnt1 = 62;
    int cnt2 = 61;
    for (int x = 0; x<8; ++x){
        for (int y = 0; y<8; ++y){
            if (ChessBoard[x][y] == 0){
                cnt1--;
                cnt2--;
            }else{
                if (ChessBoard[x][y]->GetPiece() == 'K'){
                    cnt1++;
                    cnt2++;
                }
                if ((ChessBoard[x][y]->GetPiece() == 'B')||(ChessBoard[x][y]->GetPiece() == 'N'))
                    cnt2++;
            }
        }
    }

    if ((cnt1 == 2)||(cnt2 == 3)){
        return true;
    }
    return false;
}

void Board::setfigure(int x, int y, int c, char color ){
    switch(c){
    case 0:
        ChessBoard[x][y] = new Bishop(color);
        break;
    case 1:
        ChessBoard[x][y] = new Knight(color);
        break;
    case 2:
        ChessBoard[x][y] = new Rook(color);
        break;
    case 3:
        ChessBoard[x][y] = new Queen(color);
        break;

    }
}
