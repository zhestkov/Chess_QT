#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "Board.h"
#include "Chess.h"
#include "Figure.h"
#include "dialog.h"
#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);



    ~GameWindow();

public slots:
    void slotChangeFigure();

private:
   // Board f;
    int X;
    int Y;
    Chess g;
    Dialog d;
    void restart();
    void endGame();
    int setValue();
    Ui::GameWindow *ui;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);


};

#endif // GAMEWINDOW_H
