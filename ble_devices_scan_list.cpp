#include "ble_devices_scan_list.h"
#include "ui_ble_devices_scan_list.h"

BLEDevicesScanList::BLEDevicesScanList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BLEDevicesScanList)
{
    ui->setupUi(this);
}

BLEDevicesScanList::~BLEDevicesScanList()
{
    delete ui;
}
