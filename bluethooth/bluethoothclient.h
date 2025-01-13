#ifndef BLUETHOOTHCLIENT_H
#define BLUETHOOTHCLIENT_H

#include "device.h"

#include <QBluetoothServiceDiscoveryAgent>
#include <QObject>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothdeviceinfo.h>

class BluethoothClient : public QObject
{
    Q_OBJECT

public:
    explicit BluethoothClient(QObject *parent = nullptr);

    void startDeviceDiscovery();
    QMap<QString, Device> *getDevices();

public slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
    void finishedDiscovered();
    void serviceDiscovered(const QBluetoothServiceInfo &serviceInfo);
    void finishedServiceDiscovered();

protected:
    QString majorDeviceClassToString(const QBluetoothDeviceInfo::MajorDeviceClass majorDevice);
    QString extracted();
    QString serviceClassToString(const QBluetoothDeviceInfo::ServiceClasses serviceClass);

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QList<QBluetoothServiceDiscoveryAgent*> *serviceDiscoveryAgent;

    QMap<QString, Device> *devices;

signals:
    void finished();
};

#endif // BLUETHOOTHCLIENT_H
