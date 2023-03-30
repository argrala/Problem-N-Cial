#include "Algorytm.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <iostream>
#include "Cialo.h"
using namespace std;
/**
 * @brief The noweV struct Struktura opisujaca predkosc
 */
struct noweV
{
    double nVx;
    double nVy;
};
/**
 * @brief losuj Funkcja losujaca liczby z zakresu <a,b>
 * @param a dolna granica losowania
 * @param b gorna granica losowania
 * @return wylosowana liczba
 */
double losuj(double a,double b)
{
    return a+(b-a)*double(rand())/RAND_MAX;
}

/**
 * @brief zapamietajUstawieniaPoczatkowe
 *Funkcja zapisujaca do pliku tekstowego "UstawieniaPoczatkowe.txt"
 *Sluzyla glownie do sprawdzania funkcjonalnosci projektu
 *w fazie konsolowej.
 * @param T Jednowymiarowa tablica dynamiczna
 * @param n liczba cial
 */
void zapamietajUstawieniaPoczatkowe(Cialo *T,int n)
{
    ofstream plik("UstawieniaPoczatkowe.txt");
    plik<<"Ilosc cial"<<n;
     plik<<endl;
    for(int i=0;i<n;i++)
    {
        plik<<T[i].Vx<<" ";
        plik<<T[i].Vy<<" ";
        plik<<T[i].x<<" ";
        plik<<T[i].y<<" ";
        plik<<T[i].m<<endl;
    }


    plik.close();
}
/**
 * @brief uzupelnijTablice
 *Funkcja losujaca z zakresu parametry cial
 *wywoluje funkcje "zapamietajUstawieniaPoczatkowe"
 *oraz zapisuje adres tablicy dynamicznej, liczbe cial,krok czasu i czas
 *do pliku tekstowego "adres.txt"
 * @param T Jednowymiarowa tablica dynamiczna
 * @param n liczba cial
 * @param t czas
 * @param dt krok czasu
 * @param VxMin zakres losowanego parametru Vx
 * @param VxMax zakres losowanego parametru Vx
 * @param VyMin zakres losowanego parametru Vy
 * @param VyMax zakres losowanego parametru Vy
 * @param xMin zakres losowanego parametru x
 * @param xMax zakres losowanego parametru x
 * @param yMin zakres losowanego parametru y
 * @param yMax zakres losowanego parametru y
 * @param mMin zakres losowanego parametru m
 * @param mMax zakres losowanego parametru m
 */
void uzupelnijTablice(Cialo *&T,int n,double t,double dt,double VxMin,double VxMax,double VyMin,double VyMax,double xMin,double xMax,double yMin,double yMax,double mMin,double mMax)
{

    T=new Cialo [n];
    for(int i=0;i<n;i++)
    {
        T[i].Vx=losuj(VxMin,VxMax);
        T[i].Vy=losuj(VyMin,VyMax);
        T[i].x=losuj(xMin,xMax);
        T[i].y=losuj(yMin,yMax);
        T[i].m=losuj(mMin,mMax);
    }
    zapamietajUstawieniaPoczatkowe(T,n);

    ofstream plik_a("adres.txt");
    plik_a<<T<<endl;
    plik_a<<n<<endl;
    plik_a<<t<<endl;
    plik_a<<dt<<endl;
    plik_a.close();

}
/**
 * @brief cosinus Funkcja zwraca cosinus kata miadzy punktami x i y wzgledem ukladu wspolrzednych.
 * @param x pozycja 1
 * @param y pozycja 2
 * @return cosinus
 */
double cosinus(double x,double y)
{
    return x/pow(x*x+y*y,0.5);
}
/**
 * @brief fGrawitacji Funkcja zwracajaca sile grawitacji . Dodane do funkcji jest organiczenie tej sily gdy ciala sa blisko.
 * @param m1 masa ciala 1
 * @param m2 masa ciala 2
 * @param rPow2 odlegosc miedzy cialami
 * @return Zwraca sile grawitacji
 */
double fGrawitacji(double m1,double m2,double rPow2)
{   if (rPow2<10)
        rPow2=10;
    double const G=66.7;
    return G*m1*m2/rPow2;
}
/**
 * @brief predkosc funkcja liczaca nowa predkosc dla pojedyczego ciala po kroku czasowym i zwracajaca ta wartosc
 * @param numerCiala numer ciala
 * @param T tablica dynamiczna
 * @param n ilosc cial
 * @param dt krok czsowy
 * @return Zwraca nowa predkosc
 */
noweV predkosc(int numerCiala,Cialo *T,int n,double dt)
{   noweV v;
    double Fx=0;
    double Fy=0;
    double cos,Fg,x0,y0;
    for(int i=0;i<n;i++)
    {
        if(i!=numerCiala)
        {
            x0=T[numerCiala].x-T[i].x;
            y0=T[numerCiala].y-T[i].y;
            cos=cosinus(x0,y0);
            Fg=fGrawitacji(T[numerCiala].m,T[i].m,pow(x0,2)+pow(y0,2));
            Fx+=-Fg*cos;
                    if(y0>0)
                    {
                        Fy+=-Fg*pow(1-cos*cos,0.5);
                    }
                    else
                    {
                        Fy+=+Fg*pow(1-cos*cos,0.5);
                    }
        }
    }
    v.nVx=Fx*dt/T[numerCiala].m;
    v.nVy=Fy*dt/T[numerCiala].m;
    return v;
}
/**
 * @brief zmienTablice Funkcja "zmienTablice" oblicza pozycje i predkosc dla n cial po kroku czasowym.
 * @param T adres do tablicy dynamicznej
 * @param n liczba cial
 * @param dt krok czasowy
 */
void zmienTablice(Cialo *T,int n,double dt)
{
    for(int i=0;i<n;i++)
    {   noweV vn=predkosc(i,T,n,dt);
        T[i].x=T[i].x+T[i].Vx*dt+vn.nVx*dt/2;
        T[i].y=T[i].y+T[i].Vy*dt+vn.nVy*dt/2;
        T[i].Vx+=vn.nVx;
        T[i].Vy+=vn.nVy;
    }
}

