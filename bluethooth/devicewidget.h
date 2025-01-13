#ifndef DEVICEWIDGET_H
#define DEVICEWIDGET_H

#include <QLabel>
#include <qprocess.h>
#include <qwidget.h>


class DeviceWidget : public QWidget
{
    Q_OBJECT

public:
    DeviceWidget();

    QString getName() const;
    void setName(QString name);

    QString getAddress() const;
    void setAddress(QString address);

private slots:
    void forceSleep();
    void readOutput();
    void readError();
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QLabel *name;
    QLabel *address;
};

#endif // DEVICEWIDGET_H
