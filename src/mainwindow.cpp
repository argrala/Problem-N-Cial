#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "Cialo.h"
#include "Algorytm.h"
#include "fstream"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pbu_clicked
 *  Funkcja "on_pbu_clicked" reaguje na wcisniecie przycisku "Wprowadz wlasne dane".
 *  Rozpoczyna sie od ustanienia domyslnych parametrow.
 *  Nastepnie wczytuje wpisane dane z okna "mainwindow" ,gdy nie spelniaja wymogow
 *  pozostaja parametry domyslne.
 *  Po tym procesie nastempuje wykonanie funkcji "uzupelnijTablice" i otworzenie okna "dialog".
 */
void MainWindow::on_pbu_clicked()
{
    int iCial;
    double t,dt,VxMin,VxMax,VyMin,VyMax,xMin,xMax,yMin,yMax,mMin,mMax;
    iCial=3;t=9992;dt=1;VxMin=-1;VxMax=1;VyMin=-1;VyMax=1;xMin=300;xMax=400;yMin=400;yMax=600;mMin=1;mMax=600;

        QString lE1=ui->iCialE->text();
        if(lE1.toInt()>=0)
        { iCial=lE1.toInt();}
        QString lE2=ui->timeE->text();
        if(lE2.toDouble()>0)
        { t=lE2.toDouble();}
        QString lE3=ui->dTimeE->text();
        if(lE3.toDouble()<t&&lE3.toDouble()>0)
        {    dt=lE3.toDouble();}
        QString lE4=ui->VxMinE->text();
        QString lE5=ui->VxMaxE->text();
        if(lE5.toDouble()>lE4.toDouble())
        {  VxMin=lE4.toDouble();
           VxMax=lE5.toDouble();
        }
        QString lE6=ui->VyMinE->text();
        QString lE7=ui->VyMaxE->text();
        if(lE7.toDouble()>lE6.toDouble())
        {  VyMin=lE6.toDouble();
           VyMax=lE7.toDouble();
        }
        QString lE8=ui->yMinE->text();
        QString lE9=ui->yMaxE->text();
        if(lE9.toDouble()>lE8.toDouble())
        {  yMin=lE8.toDouble();
           yMax=lE9.toDouble();
        }
        QString lE10=ui->xMinE->text();
        QString lE11=ui->xMaxE->text();
        if(lE11.toDouble()>lE10.toDouble())
        {  xMin=lE10.toDouble();
           xMax=lE11.toDouble();
        }
        QString lE12=ui->mMinE->text();
        QString lE13=ui->mMaxE->text();
        if(lE13.toDouble()>lE12.toDouble()&&lE12.toDouble()>0)
        {  mMin=lE12.toDouble();
           mMax=lE13.toDouble();
        }
                     mdialog= new Dialog(0,iCial,t,dt,VxMin,VxMax,VyMin,VyMax,xMin,xMax,yMin,yMax,mMin,mMax);
                     mdialog->show();
}

/**
 * @brief MainWindow::on_pushButton_clicked
 *  Funkcja "on_pbu_clicked" reaguje na wcisniecie przycisku "Wczytaj usawienia z pliku".
 *  Rozpoczyna sie od ustanienia domyslnych parametrow.
 *  Nastepnie wczytuje wpisane dane z pliku "UstawieniaPoczatkowe2.txt, gdy nie spelniaja wymogow
 *  pozostaja parametry domyslne.
 *  Po tym procesie nastempuje wykonanie funkcji "uzupelnijTablice" i otworzenie okna "dialog".
 */
void MainWindow::on_pushButton_clicked()
{
//    Cialo *T;
    int iCial;
    double t,dt,VxMin,VxMax,VyMin,VyMax,xMin,xMax,yMin,yMax,mMin,mMax;

    ifstream plik3("UstawieniaPoczatkowe2.txt");
    if(plik3.good())
    {
        iCial=2;t=3600;dt=0.1;VxMin=0;VxMax=0;VyMin=0;VyMax=0;xMin=0;xMax=10;yMin=0;yMax=0;mMin=1;mMax=10;
        double MAX,MIN;
        plik3>>MAX;
        if(MAX>=0)
            iCial=MAX;
        plik3>>MAX;
        plik3>>MIN;
        if(MAX>MIN&&MIN>0)
        {t=MAX;
            dt=MIN;
        }
        plik3>>MIN;
        plik3>>MAX;
        if(MAX>MIN)
        {
            VxMin=MIN;VxMax=MAX;
        }
        plik3>>MIN;  plik3>>MAX;

        if(MAX>MIN)
        {
            VyMin=MIN;VyMax=MAX;
        }

        plik3>>MIN;plik3>>MAX;
        if(MAX>MIN)
        {
            xMin=MIN;xMax=MAX;
        }

        plik3>>MIN; plik3>>MAX;
        if(MAX>MIN)
        {
            yMin=MIN;yMax=MAX;
        }

        plik3>>MIN; plik3>>MAX;
        if(MAX>MIN&&MIN>0)
        {mMax=MAX;
            mMin=MIN;
        }
    }
    plik3.close();

    mdialog= new Dialog(0,iCial,t,dt,VxMin,VxMax,VyMin,VyMax,xMin,xMax,yMin,yMax,mMin,mMax);
    mdialog->show();
}
