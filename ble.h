#pragma once

#include <QObject>

class ble: public QObject
{
    Q_OBJECT

public:
    explicit ble(QObject *parent = nullptr);

signals:
};
