#pragma once

#include <QWidget>
#include "ble.h"
#include "ble_devices_scan_list.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

enum CONNECT_TYPE 
{ 
    CONNECT_TYPE_BLE = 0,
    CONNECT_TYPE_RJ45 = 1
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    BLE *ble;
    BLEDevicesScanList bleDevicesScanList;
};
