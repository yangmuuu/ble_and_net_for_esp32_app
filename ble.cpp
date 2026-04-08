#include "ble.h"

BLE::BLE(QObject *parent)
: QObject{parent}
{
}

void BLE::startDeviceDiscovery()
{
    // 创建蓝牙对象
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    // 绑定信号槽
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &BLE::deviceDiscovered);

    // 只找低功耗蓝牙
    discoveryAgent->start(QBluetoothDeviceDiscoveryAgent::LowEnergyMethod);
}

void BLE::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    // 扫描到的蓝牙设备列表
    QVector<BLE_DEVICE_INFO> bleDevices;
    // 如果信息齐全
    if (device.isValid())
    {
        BLE_DEVICE_INFO info;
        info.name = device.name();
        info.address = device.address();
        info.uuid = device.deviceUuid();
        info.rssi = device.rssi();

        emit deviceFound(info);
    }
}
