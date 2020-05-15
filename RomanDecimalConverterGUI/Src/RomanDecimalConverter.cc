#include "stdafx.h"
#include "RomanDecimalConverter.h"
#include "RomanDecimalConverterLib.h"

RomanDecimalConverter::RomanDecimalConverter(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.mButtonsLayout->setAlignment(Qt::AlignCenter);
    ui.statusBar->showMessage("Ready");

    mAutoUpdateOnInputChange = ui.mAutoUpdateOnInputChangeCheckbox->isChecked();
    mSubmitConversionOnEnterKey = ui.mSubmitConversionOnEnterKeyCheckbox->isChecked();

    connect(
        ui.mClearButton,
        &QPushButton::clicked,
        this,
        &RomanDecimalConverter::HandleClearInputs
    );

    connect(
        ui.mConvertToRomanButton,
        &QPushButton::clicked,
        this,
        &RomanDecimalConverter::HandleDecimalInputChange
    );

    connect(
        ui.mConvertToDecimalButton,
        &QPushButton::clicked,
        this,
        &RomanDecimalConverter::HandleRomanInputChange
    );

    connect(
        ui.mRomanInput,
        &QTextEdit::textChanged,
        this,
        &RomanDecimalConverter::HandleRomanInputChange
    );

    connect(
        ui.mDecimalInput,
        &QTextEdit::textChanged,
        this,
        &RomanDecimalConverter::HandleDecimalInputChange
    );

    connect(
        ui.mAutoUpdateOnInputChangeCheckbox,
        &QCheckBox::toggled,
        this,
        [&](bool checked) { mAutoUpdateOnInputChange = checked; }
    );

    connect(
        ui.mSubmitConversionOnEnterKeyCheckbox,
        &QCheckBox::toggled,
        this,
        [&](bool checked) { mSubmitConversionOnEnterKey = checked; }
    );

    connect(
        ui.actionAbout,
        &QAction::triggered,
        this,
        [&]()
        {
            QString message(qAppName());
            message += QString(" - v");
            message += QApplication::applicationVersion();
            QMessageBox::about(this, qAppName(), message);
        }
    );

    connect(
        ui.actionExit,
        &QAction::triggered,
        this,
        [&]() { close(); }
    );
}

void RomanDecimalConverter::HandleDecimalToRomanConversion()
{
    const auto decimal = ui.mDecimalInput->toPlainText()
        .remove("\n").remove(" ").toStdString();
    if (RomanDecimalConverterLib::IsDecimalNumber(decimal))
    {
        const auto roman = RomanDecimalConverterLib::ConvertToRoman(decimal);
        ui.mRomanInput->clear();
        ui.mRomanInput->setText(QString::fromStdString(roman));
    } else
    {
        ui.mRomanInput->setText("Invalid decimal value!");
    }
}

void RomanDecimalConverter::HandleRomanToDecimalConversion()
{
    const auto roman = ui.mRomanInput->toPlainText()
        .remove("\n").remove(" ").toStdString();
    if (RomanDecimalConverterLib::IsRomanNumber(roman))
    {
        const auto decimal = RomanDecimalConverterLib::ConvertToDecimal(roman);
        ui.mDecimalInput->clear();
        ui.mDecimalInput->setText(QString::number(decimal));
    } else
    {
        ui.mDecimalInput->setText("Invalid roman value!");
    }
}

void RomanDecimalConverter::HandleDecimalInputChange()
{
    if (mAutoUpdateOnInputChange ||
        (mSubmitConversionOnEnterKey &&
            ui.mDecimalInput->toPlainText().endsWith("\n")))
    {
        if (!mBusy)
        {
            ui.statusBar->showMessage("Calculating Roman value...");
            mBusy = true;
            HandleDecimalToRomanConversion();
            mBusy = false;
            ui.statusBar->showMessage("Ready");
        }
    }
}

void RomanDecimalConverter::HandleRomanInputChange()
{
    if (mAutoUpdateOnInputChange ||
        (mSubmitConversionOnEnterKey &&
            ui.mRomanInput->toPlainText().endsWith("\n")))
    {
        if (!mBusy)
        {
            ui.statusBar->showMessage("Calculating Decimal value...");
            mBusy = true;
            HandleRomanToDecimalConversion();
            mBusy = false;
            ui.statusBar->showMessage("Ready");
        }
    }
}

void RomanDecimalConverter::HandleClearInputs()
{
    mBusy = true;
    ui.mDecimalInput->clear();
    ui.mRomanInput->clear();
    mBusy = false;
}
