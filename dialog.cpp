#include "dialog.h"
#include "iostream"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->resize(150,50);

    b1 = new QPushButton("&Bishop");
    b2 = new QPushButton("&Knight");
    b3 = new QPushButton("&Rook");
    b4 = new QPushButton("&Queen");

    b1->setCheckable(true);
    b2->setCheckable(true);
    b3->setCheckable(true);
    b4->setCheckable(true);


}

Dialog::~Dialog()
{

}

int Dialog::slotButtonClicked(){

    if (b1->isChecked())
        return 0;
    if (b2->isChecked())
        return 1;
    if (b3->isChecked())
        return 2;
    if (b4->isChecked())
        return 3;

}


