#ifndef RYSUJ_H
#define RYSUJ_H
#include <QPainter>
#include <fstream>
#include "dialog.h"
void rysujLinie(QPainter *painter,int n,double t,double dt,double VxMin,double VxMax,double VyMin,double VyMax,double xMin,double xMax,double yMin,double yMax,double mMin,double mMax);
#endif // RYSUJ_H
