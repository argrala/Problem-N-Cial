#ifndef ALGORYTM_H
#define ALGORYTM_H
#include "Cialo.h"
void uzupelnijTablice(Cialo *&T,int n,double t,double dt,double VxMin,double VxMax,double VyMin,double VyMax,double xMin,double xMax,double yMin,double yMax,double mMin,double mMax);
void zmienTablice(Cialo *T,int n,double dt);
#endif // ALGORYTM_H
