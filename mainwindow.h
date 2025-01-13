#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <bluethooth/bluethoothclient.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addDevicesUI();
    void bomb();

private:
    Ui::MainWindow *ui;
    BluethoothClient *client;
};
#endif // MAINWINDOW_H
