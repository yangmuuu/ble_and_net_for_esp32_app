#include "ble.h"

ble::ble(QObject *parent)
    : QObject{parent}
{
}


void MyClass::startDeviceDiscovery()
{
    // 创建蓝牙代理
    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    // Start a discovery
    discoveryAgent->start();
    //...
}
// In your local slot, read information about the found devices
void MyClass::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
        qDebug() << "Found new device:" << device.name() << '(' << device.address().toString() << ')';
}

