#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    QPushButton* b1; // Bishop
    QPushButton* b2; // Knight
    QPushButton* b3; // Rook
    QPushButton* b4; // Queen
    ~Dialog();
public slots:
    int slotButtonClicked();


};


#endif // DIALOG_H
