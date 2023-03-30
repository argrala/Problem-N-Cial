#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QDialog>
#include "Rysuj.h"
#include "Cialo.h"
using namespace std;

//void Dialog::paintEvent(QPaintEvent*, Cialo *T, int N, double t, double dt)
void Dialog::paintEvent(QPaintEvent*)
{
QPainter painter(this);
rysujLinie(&painter,n,t,dt,VxMin,VxMax,VyMin,VyMax,xMin,xMax,yMin,yMax,mMin,mMax);
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
Dialog::Dialog(QWidget *parent,int n,double t,double dt,double VxMin,double VxMax,double VyMin,double VyMax,double xMin,double xMax,double yMin,double yMax,double mMin,double mMax) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->n=n;
    this->t=t;
    this->dt=dt;
    this->VxMin=VxMin;
    this->VxMax=VxMax;
    this->VyMin=VyMin;
    this->VyMax=VyMax;
    this->xMin=xMin;
    this->xMax=xMax;
    this->yMin=yMin;
    this->yMax=yMax;
    this->mMin=mMin;
    this->mMax=mMax;
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
     this->update();
}
