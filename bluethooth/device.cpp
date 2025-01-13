#include "device.h"

Device::Device(QString name, QString address) {
    this->name = name;
    this->address = address;
}

QString Device::getName() const
{
    return name;
}

QString Device::getAddress() const
{
    return address;
}
