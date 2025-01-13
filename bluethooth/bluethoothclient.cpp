#include "bluethoothclient.h"

#include <QDebug>
#include <QBluetoothDeviceDiscoveryAgent>

BluethoothClient::BluethoothClient(QObject *parent)
    : QObject{parent}
{}

void BluethoothClient::startDeviceDiscovery()
{
    this->devices = new QMap<QString, Device>();

    // Create a discovery agent and connect to its signals
    this->discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    connect(discoveryAgent, SIGNAL(finished()), this, SIGNAL(finished()));

    this->serviceDiscoveryAgent = new QList<QBluetoothServiceDiscoveryAgent*>;

    // Start a discovery
    discoveryAgent->start();
}

QMap<QString, Device> *BluethoothClient::getDevices()
{
    return this->devices;
}

// In your local slot, read information about the found devices
void BluethoothClient::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    QString name = device.name();
    QString address = device.address().toString();
    this->devices->insert(address, Device(name, address));

    qDebug() << "Found new device:" << name << '(' << address << ')'
             << "is valid ->" << device.isValid()
             << "major device ->" << device.majorDeviceClass()
             << "minor device ->" << device.minorDeviceClass()
             << "service class ->" << this->serviceClassToString(device.serviceClasses());

    QHash<quint16, QByteArray> m = device.manufacturerData();
    if (m.size() > 0) {
        //qDebug() << "== manufacturer data ==";
        for (auto i = m.cbegin(), end = m.cend(); i != end; ++i) {
            //qDebug() << "   - key: " << i.key() << "value: " <<  i.value();
        }
    }

    /*QBluetoothServiceDiscoveryAgent *agent = new QBluetoothServiceDiscoveryAgent(this);
    this->serviceDiscoveryAgent->append(agent);
    connect(agent, &QBluetoothServiceDiscoveryAgent::serviceDiscovered, this, &BluethoothClient::serviceDiscovered);
    //connect(agent, &QBluetoothServiceDiscoveryAgent::finished, this, &BluethoothClient::finishedServiceDiscovered);

    // Start service discovery for this device
    agent->setRemoteAddress(device.address());
    agent->start();*/
}

void BluethoothClient::finishedDiscovered() {
    qDebug() << "== FINISHED ==";
    QList<QBluetoothDeviceInfo> devices = this->discoveryAgent->discoveredDevices();
    foreach (QBluetoothDeviceInfo device, devices) {
        qDebug() << "Device:" << device.name() << '(' << device.address().toString() << ')'
                 << "major device ->" << device.majorDeviceClass()
                 << "minor device ->" << device.minorDeviceClass()
                 << "service class ->" << device.serviceClasses();

        QHash<quint16, QByteArray> m = device.manufacturerData();
        if (m.size() > 0) {
            qDebug() << "== manufacturer data ==";
            for (auto i = m.cbegin(), end = m.cend(); i != end; ++i) {
                qDebug() << "   - key: " << i.key() << "value: " <<  i.value();
            }
        }

        QBluetoothServiceDiscoveryAgent *agent = new QBluetoothServiceDiscoveryAgent(this);
        this->serviceDiscoveryAgent->append(agent);
        connect(agent, &QBluetoothServiceDiscoveryAgent::serviceDiscovered, this, &BluethoothClient::serviceDiscovered);
        //connect(agent, &QBluetoothServiceDiscoveryAgent::finished, this, &BluethoothClient::finishedServiceDiscovered);

        // Start service discovery for this device
        agent->setRemoteAddress(device.address());
        agent->start();
    }
}

void BluethoothClient::serviceDiscovered(const QBluetoothServiceInfo &serviceInfo)
{
    QString serviceName = serviceInfo.serviceName();
    if (serviceName.isEmpty()) {
        serviceName = "Unknown Service";
    }

    QString serviceUuid = serviceInfo.serviceUuid().toString();
    qDebug() << "   ----  Service(" << serviceInfo.device().address() << ") : " << serviceName << " (" << serviceUuid << ")";

    QList<quint16> attrs = serviceInfo.attributes();
    for(quint16 a : attrs) {
        qDebug() << "        ----  Attr: " << serviceInfo.attribute(a);
    }
}

void BluethoothClient::finishedServiceDiscovered()
{

}

QString BluethoothClient::majorDeviceClassToString(const QBluetoothDeviceInfo::MajorDeviceClass majorDevice) {
    switch (majorDevice) {
    case QBluetoothDeviceInfo::MiscellaneousDevice:
        return QString("MiscellaneousDevice");
    case QBluetoothDeviceInfo::ComputerDevice:
        return QString("ComputerDevice");
    case QBluetoothDeviceInfo::PhoneDevice:
        return QString("PhoneDevice");
    case QBluetoothDeviceInfo::LANAccessDevice:
        return QString("LANAccessDevice");
    case QBluetoothDeviceInfo::AudioVideoDevice:
        return QString("LANAccessDevice");
    case QBluetoothDeviceInfo::PeripheralDevice:
        return QString("LANAccessDevice");
    case QBluetoothDeviceInfo::ImagingDevice:
        return QString("LANAccessDevice");
    case QBluetoothDeviceInfo::WearableDevice:
        return QString("LANAccessDevice");
    case QBluetoothDeviceInfo::ToyDevice:
        return QString("LANAccessDevice");
    case QBluetoothDeviceInfo::HealthDevice:
        return QString("LANAccessDevice");
    case QBluetoothDeviceInfo::UncategorizedDevice:
        return QString("LANAccessDevice");
    }

    return QString("Uncategorized");
}

QString BluethoothClient::serviceClassToString(const QBluetoothDeviceInfo::ServiceClasses serviceClass) {
    QString s = "Uncategorized";
    switch (serviceClass) {
    case QBluetoothDeviceInfo::NoService:
        s = "NoService";
        break;
    case QBluetoothDeviceInfo::PositioningService:
        s = "PositioningService";
        break;
    case QBluetoothDeviceInfo::NetworkingService:
        s = "NetworkingService";
        break;
    case QBluetoothDeviceInfo::RenderingService:
        s = "RenderingService";
        break;
    case QBluetoothDeviceInfo::CapturingService:
        s = "CapturingService";
        break;
    case QBluetoothDeviceInfo::ObjectTransferService:
        s = "ObjectTransferService";
        break;
    case QBluetoothDeviceInfo::AudioService:
        s = "AudioService";
        break;
    case QBluetoothDeviceInfo::TelephonyService:
        s = "TelephonyService";
        break;
    case QBluetoothDeviceInfo::AllServices:
        s = "AllServices";
        break;
    }

    return s;
}
