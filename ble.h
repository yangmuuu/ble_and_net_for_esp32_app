#pragma once

#include <QObject>
#include <QBluetoothDeviceInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QDebug>
#include <QVector>

typedef struct BLE_DEVICE_INFO
{
    QString name;
    QBluetoothAddress address;
    QBluetoothUuid uuid;
    qint16 rssi;
} BLE_DEVICE_INFO;

class BLE: public QObject
{
    Q_OBJECT

public:
    explicit BLE(QObject *parent = nullptr);

    /**
     * @brief 初始化蓝牙对象，开始扫描
     * 
     * @param discoveryAgent 
     */
    void startDeviceDiscovery();

private:
    // 蓝牙对象
    QBluetoothDeviceDiscoveryAgent *discoveryAgent; 


private slots:
    /**
    * @brief 扫描BLE设备槽函数
    * 
    * @param device 
    */
    void deviceDiscovered(const QBluetoothDeviceInfo &device);

signals:
    /**
     * @brief 发送扫描到的BLE设备信息
     * 
     * @param info 
     */
    void deviceFound(const BLE_DEVICE_INFO &info);
};
