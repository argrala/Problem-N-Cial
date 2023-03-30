#include "Cialo.h"
#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QPainter>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
private:
    Ui::Dialog *ui;

    int n;
    double t;
    double dt;

     double VxMin,VxMax,VyMin,VyMax,xMin,xMax,yMin,yMax,mMin,mMax;
public:
    explicit  Dialog(QWidget *parent = 0);
    Dialog(QWidget *parent = 0,int n=3,double t=992,double dt=1,double VxMin=-1,double VxMax=1,double VyMin=-1,double VyMax=1,double xMin=300,double xMax=400,double yMin=400,double yMax=600,double mMin=1,double mMax=600);
    ~Dialog();
    void paintEvent(QPaintEvent*);

private slots:
    void on_pushButton_clicked();
};

#endif // DIALOG_H
