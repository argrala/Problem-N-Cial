#include <ctime>
#include "Rysuj.h"
#include <cstdlib>
#include <fstream>
#include <QColor>
#include "Cialo.h"
#include "Algorytm.h"
#include "dialog.h"
using namespace std;
/**
 * @brief The RGBq struct
 *Struktura RGB sluzy do zapisywania parametrow koloru
 */
struct RGBq{
    int R,G,B;
};
/**
 * @brief The pkt struct
 *Struktura pkt sluzy do zapisywania informacji na temat lini rysowanych
 *punkt poczatkowy ,koncowy i kolor.
 */
struct pkt{
    double x0,y0,x1,y1;
    RGBq kolor;
};
/**
 * @brief The lista struct
 *  Struktura wykorzystana do
 *stworzenia listy dynamiczej.
 */
struct lista{
    pkt parametry;
    lista *next;
};
/**
 * @brief usunListe
 * @param glowa
 *Funkcja usuwa liste przez co
 *uwalnia pamiec.
 */
void usunListe(lista*&glowa)
{
    lista *help;
    if(glowa!=NULL)
    {
        help=glowa;
        glowa=NULL;
        delete help;
    }
}
/**
 * @brief rysujLinie
 * @param painter
 *Funkcja rysuje trajektorie cial po oknie dialogu
 *do funkcji jest przekazywana tablica dynamiczna
 *poprzez plik "adres.txt".
 *W funkcji do rysowania wykorzystana jest lista.
 *Funkcja losuje dla kazdego ciala kolor i go zapamientuje w liscie.
 *Funkcja "rysujLinie" wykorzystuje funkcje "zmienTablice"
 *obliczania pozycji cial po kroku czasowym.
 */

void rysujLinie(QPainter *painter,int N,double t,double dt,double VxMin,double VxMax,double VyMin,double VyMax,double xMin,double xMax,double yMin,double yMax,double mMin,double mMax)//nowa zmienna kolor
{
    Cialo *T;
    uzupelnijTablice(T,N,t,dt,VxMin,VxMax,VyMin,VyMax,xMin,xMax,yMin,yMax,mMin,mMax);

    srand(time(0));
    lista *aktualny,*ogon,*glowa;
    glowa=NULL;aktualny=NULL;


    for(int i=0;i<N;i++)
    {
        ogon=aktualny;
        aktualny=new lista;
        aktualny->parametry.x0=T[i].x;
        aktualny->parametry.y0=T[i].y;
        aktualny->parametry.kolor.R=256*double(rand())/RAND_MAX;
        aktualny->parametry.kolor.G=256*double(rand())/RAND_MAX;
        aktualny->parametry.kolor.B=256*double(rand())/RAND_MAX;
        aktualny->next=NULL;
        if(ogon==NULL)
        {glowa=aktualny;}
        else
        {ogon->next=aktualny;}
    }


       ///Petla odpowiedzialna za rysowanie
        for(int j=0;j*dt<t;j++)
        {
            aktualny=glowa;
            zmienTablice(T,N,dt);
            for(int i=0;i<N;i++)
        {
            aktualny->parametry.x1=T[i].x;
            aktualny->parametry.y1=T[i].y;
            painter->setPen(QColor(aktualny->parametry.kolor.R,aktualny->parametry.kolor.G,aktualny->parametry.kolor.B,255));
            painter->drawLine(aktualny->parametry.x0,aktualny->parametry.y0,aktualny->parametry.x1,aktualny->parametry.y1);



            aktualny->parametry.x0=aktualny->parametry.x1;
            aktualny->parametry.y0=aktualny->parametry.y1;


            aktualny=aktualny->next;
        }
        }

    usunListe(glowa);
    delete []T;

}
