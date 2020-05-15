#pragma once

#include "ui_RomanDecimalConverter.h"

class RomanDecimalConverter : public QMainWindow
{
    Q_OBJECT

        QThread mWorkerThread;

public:
    explicit RomanDecimalConverter(QWidget* parent = Q_NULLPTR);

private:
    Ui::RomanDecimalConverterClass ui;

    bool mAutoUpdateOnInputChange;
    bool mSubmitConversionOnEnterKey;
    bool mBusy;

    void HandleDecimalToRomanConversion();
    void HandleRomanToDecimalConversion();
    void HandleDecimalInputChange();
    void HandleRomanInputChange();
    void HandleClearInputs();
};
