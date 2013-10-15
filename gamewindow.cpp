#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QtGui>
#include <QButtonGroup>
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->setPalette(Qt::white);
    this->setWindowTitle("Chess");
    X=-1;
    Y=-1;

}
GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::paintEvent(QPaintEvent *){

    QPainter painter;
    painter.begin(this);
    int X=this->height();
    int Y=this->width();


    QPixmap pawn_black("pawn_black.jpg");
    QPixmap bishop_black("bishop_black.jpg");
    QPixmap knight_black("knight_black.jpg");
    QPixmap rook_black("rook_black.jpg");
    QPixmap queen_black("queen_black.jpg");
    QPixmap king_black("king_black.jpg");

    QPixmap pawn_white("pawn_white.jpg");
    QPixmap bishop_white("bishop_white.jpg");
    QPixmap knight_white("knight_white.jpg");
    QPixmap rook_white("rook_white.jpg");
    QPixmap queen_white("queen_white.jpg");
    QPixmap king_white("king_white.jpg");

    for (int i=0;i<8;++i){
        for (int j=0;j<8;++j){
            if (g.GameBoard.ChessBoard[i][j] != 0){
                if (g.GameBoard.ChessBoard[i][j]->GetColor() == 'W'){
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'P')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, pawn_white);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'B')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, bishop_white);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'N')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, knight_white);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'R')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, rook_white);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'Q')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, queen_white);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'K')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, king_white);
            }
                if (g.GameBoard.ChessBoard[i][j]->GetColor() == 'B'){
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'P')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, pawn_black);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'B')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, bishop_black);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'N')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, knight_black);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'R')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, rook_black);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'Q')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, queen_black);
                    if (g.GameBoard.ChessBoard[i][j]->GetPiece() == 'K')
                    painter.drawPixmap(j*X/8, i*Y/8, X/8, Y/8, king_black);
               }
            }
        }
    }

    for (int i=0; i<8; ++i){
        for (int j=0; j<8; ++j){
            painter.drawLine(j*X/8,0,j*X/8,Y);
        }
        painter.drawLine(0,i*Y/8,X,i*Y/8);
  }
    //painter.drawPixmap(1*X/8 + X/64 , 1*Y/8 + Y/64 , X/10, Y/10, queen_black);

    painter.end();
}


void GameWindow::mousePressEvent(QMouseEvent *event){
    if (X != -1){
        int X1 = event->y()/(this->height()/8);
        int Y1 = event->x()/(this->width()/8);

        if (!g.IsGameOver()){
            g.GetNextMove(X,Y,X1,Y1,g.GameBoard.ChessBoard);

            cout<<X<<"  "<<Y<<endl;
            cout<<X1<<" "<<Y1<<endl;
            // проверка возможности поставить новую фигуру вместо пешки
            if (g.CheckNew(g.GameBoard.ChessBoard)){

                connect(d.b1,SIGNAL(clicked()),SLOT(slotChangeFigure()));
                connect(d.b2,SIGNAL(clicked()),SLOT(slotChangeFigure()));
                connect(d.b3,SIGNAL(clicked()),SLOT(slotChangeFigure()));
                connect(d.b4,SIGNAL(clicked()),SLOT(slotChangeFigure()));

                connect(d.b1,SIGNAL(clicked()),&d,SLOT(close()));
                connect(d.b2,SIGNAL(clicked()),&d,SLOT(close()));
                connect(d.b3,SIGNAL(clicked()),&d,SLOT(close()));
                connect(d.b4,SIGNAL(clicked()),&d,SLOT(close()));

                QHBoxLayout* l = new QHBoxLayout;
                l->addWidget(d.b1);
                l->addWidget(d.b2);
                l->addWidget(d.b3);
                l->addWidget(d.b4);
                d.setLayout(l);
                d.exec();

            }

            repaint();

        }
    }
    if (g.IsGameOver())
        endGame();

    X=event->y()/(this->height()/8);
    Y=event->x()/(this->width()/8);

    cout<<X<<" "<<Y<<endl;
    cout<<g.cPlayerTurn<<" ";

    repaint();
}



void GameWindow::endGame(){
     QMessageBox msg;
     msg.setText("<b>The winner</b>: " + QString(g.cPlayerTurn) + " player");
     msg.setInformativeText("\n <i>Do you want to start new match?</i>");
     msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
     msg.setDefaultButton(QMessageBox::Yes);
     int t = msg.exec();
     if (t == QMessageBox::Yes)
         restart();
     if (t == QMessageBox::No)
         QApplication::quit();
}

void GameWindow::restart(){
    g.cnt = 0;
    g.cntEnpB = 0;
    g.cntEnpW = 0;
    for (int x = 0; x < 8; ++x){
        for (int y = 0; y < 8; ++y){
            delete g.GameBoard.ChessBoard[x][y];
            g.GameBoard.ChessBoard[x][y] = 0;

        }
    }



    // –асставл€ем черные фигуры
    for (int y = 0; y < 8; ++y)
        g.GameBoard.ChessBoard[6][y] = new Pawn('B');
    g.GameBoard.ChessBoard[7][0] = new Rook('B');
    g.GameBoard.ChessBoard[7][1] = new Knight('B');
    g.GameBoard.ChessBoard[7][2] = new Bishop('B');
    g.GameBoard.ChessBoard[7][3] = new King('B');
    g.GameBoard.ChessBoard[7][4] = new Queen('B');
    g.GameBoard.ChessBoard[7][5] = new Bishop('B');
    g.GameBoard.ChessBoard[7][6] = new Knight('B');
    g.GameBoard.ChessBoard[7][7] = new Rook('B');

    // –асставл€ем белые фигуры
    for (int y = 0; y < 8; ++y)
        g.GameBoard.ChessBoard[1][y] = new Pawn('W');
    g.GameBoard.ChessBoard[0][0] = new Rook('W');
    g.GameBoard.ChessBoard[0][1] = new Knight('W');
    g.GameBoard.ChessBoard[0][2] = new Bishop('W');
    g.GameBoard.ChessBoard[0][3] = new King('W');
    g.GameBoard.ChessBoard[0][4] = new Queen('W');
    g.GameBoard.ChessBoard[0][5] = new Bishop('W');
    g.GameBoard.ChessBoard[0][6] = new Knight('W');
    g.GameBoard.ChessBoard[0][7] = new Rook('W');
}

void GameWindow::slotChangeFigure(){
    if (g.CheckNew(g.GameBoard.ChessBoard) == 1){
        switch(d.slotButtonClicked()){
        case 0:
            g.GameBoard.ChessBoard[g.k1][g.k2] = new Bishop('W');d.b1->setChecked(false);break;
        case 1:
            g.GameBoard.ChessBoard[g.k1][g.k2] = new Knight('W');d.b2->setChecked(false);break;
        case 2:
            g.GameBoard.ChessBoard[g.k1][g.k2] = new Rook('W');d.b3->setChecked(false);break;
        case 3:
            g.GameBoard.ChessBoard[g.k1][g.k2] = new Queen('W');d.b4->setChecked(false);break;
        }
    }
    if (g.CheckNew(g.GameBoard.ChessBoard) == 2){
        switch(d.slotButtonClicked()){
        case 0:
            g.GameBoard.ChessBoard[g.k3][g.k4] = new Bishop('B');d.b1->setChecked(false);break;
        case 1:
            g.GameBoard.ChessBoard[g.k3][g.k4] = new Knight('B');d.b2->setChecked(false);break;
        case 2:
            g.GameBoard.ChessBoard[g.k3][g.k4] = new Rook('B');d.b3->setChecked(false);break;
        case 3:
            g.GameBoard.ChessBoard[g.k3][g.k4] = new Queen('B');d.b4->setChecked(false);break;
        }
    }
}


