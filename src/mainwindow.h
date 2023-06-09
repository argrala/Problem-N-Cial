#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include <QMainWindow>
#include <QPainter>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pbu_clicked();
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    Dialog *mdialog;
};
#endif // MAINWINDOW_H
