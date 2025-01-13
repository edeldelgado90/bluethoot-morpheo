#include "devicewidget.h"
#include "qdebug.h"

#include <QProcess>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

DeviceWidget::DeviceWidget() {
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->name = new QLabel("Name", this);
    this->address = new QLabel("Address", this);

    QPushButton *button = new QPushButton("Force Sleep", this);
    connect(button, SIGNAL(clicked(bool)), this, SLOT(forceSleep()));

    layout->addWidget(name);
    layout->addWidget(address);
    layout->addWidget(button);
    setLayout(layout);
}

QString DeviceWidget::getName() const
{
    return this->name->text();
}

void DeviceWidget::setName(QString name)
{
    this->name->setText(name);
}

QString DeviceWidget::getAddress() const
{
    return this->address->text();
}

void DeviceWidget::setAddress(QString address)
{
    this->address->setText(address);
}

void DeviceWidget::forceSleep()
{
    qDebug() << "Force sleep:" << this->getAddress();
    QProcess *process = new QProcess(this);
    connect(process, &QProcess::readyReadStandardOutput, this, &DeviceWidget::readOutput);
    connect(process, &QProcess::readyReadStandardError, this, &DeviceWidget::readError);
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &DeviceWidget::processFinished);
    process->start("l2ping", QStringList() << "-i" << "hci0" << "-s" << "100" << "-f" << this->getAddress());
}

void DeviceWidget::readOutput() {
    QProcess *process = qobject_cast<QProcess*>(sender());
    if (process) {
        QByteArray output = process->readAllStandardOutput();
        qDebug() << "Result:" << output;
    }
}

void DeviceWidget::readError() {
    QProcess *process = qobject_cast<QProcess*>(sender());
    if (process) {
        QByteArray error = process->readAllStandardError();
        qDebug() << "Error:" << error;
    }
}

void DeviceWidget::processFinished(int exitCode, QProcess::ExitStatus exitStatus) {
    if (exitStatus == QProcess::CrashExit) {
        qDebug() << "Process crashed";
    } else if (exitCode != 0) {
        qDebug() << "Process exited with error code: " << QString::number(exitCode);
    } else {
        qDebug() << "Process finished successfully";
    }
}
