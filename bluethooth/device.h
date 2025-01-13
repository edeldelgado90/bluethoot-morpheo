#ifndef DEVICE_H
#define DEVICE_H

#include <QString>


class Device
{
public:
    Device(QString name, QString address);

    QString getName() const;

    QString getAddress() const;

private:
    QString name;
    QString address;
};

#endif // DEVICE_H
