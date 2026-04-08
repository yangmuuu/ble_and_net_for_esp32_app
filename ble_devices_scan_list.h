#ifndef BLE_DEVICES_SCAN_LIST_H
#define BLE_DEVICES_SCAN_LIST_H

#include <QWidget>

namespace Ui {
class BLEDevicesScanList;
}

class BLEDevicesScanList : public QWidget
{
    Q_OBJECT

public:
    explicit BLEDevicesScanList(QWidget *parent = nullptr);
    ~BLEDevicesScanList();

private:
    Ui::BLEDevicesScanList *ui;
};

#endif // BLE_DEVICES_SCAN_LIST_H
