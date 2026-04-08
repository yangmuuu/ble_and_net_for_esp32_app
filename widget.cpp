#include "widget.h"
#include "ui_widget.h"
#include <QObject>

Widget::Widget(QWidget *parent)
: QWidget(parent)
, ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->comboBox, &QComboBox::activated, [this](int index) {
        if (index == CONNECT_TYPE_BLE)
        {
            qDebug() << "开始连接蓝牙设备";
        }
        else if (index == CONNECT_TYPE_RJ45)
        {
            qDebug() << "开始连接RJ45设备";
        }
    });

    connect(ui->startBleScan, &QPushButton::clicked, [this]() { bleDevicesScanList.show(); });

    ble = new BLE(this);

    connect(ble, &BLE::deviceFound, [](const BLE_DEVICE_INFO &info) {
        qDebug() << "发现设备:" << info.name << info.address.toString();
        // 这里可以添加到 UI 列表、打印、存储等
    });

    ble->startDeviceDiscovery();
}

Widget::~Widget() { delete ui; }
