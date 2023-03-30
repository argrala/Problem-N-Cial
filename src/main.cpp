#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <iostream>
using namespace std;
/*! \mainpage Problem N cial dokumentacja
 *
 * \section intro_sec Wstep
 *
 * Problem n ciał odnosi się do sytuacji, w której mamy do czynienia z wieloma ciałami oddziałującymi na siebie siłami grawitacji. W zagadnieniu tym każde ciało przyciąga pozostałe ciała z siłą, która zależy od ich mas oraz odległości między nimi.
 *
 * W praktyce problem n ciał jest rozwiązywany poprzez zastosowanie numerycznego algorytmu, który pozwala na określenie trajektorii ruchu każdego ciała w czasie. W przypadku aplikacji, która symuluje ten problem, algorytm numeryczny został zaimplementowany w języku C++ zgodnie z paradygmatem programowania strukturalnego, co pozwala na dokładne odwzorowanie ruchu ciał w przestrzeni 2D.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

