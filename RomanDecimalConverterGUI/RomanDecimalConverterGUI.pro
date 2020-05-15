TEMPLATE = app
TARGET = "Roman Decimal Converter GUI"

outdir = "../bin/"

CONFIG(debug, debug|release) {
  DESTDIR = "$$outdir/x64/Debug/Roman Decimal Converter GUI"
}

CONFIG(release, debug|release) {
  DESTDIR = "$$outdir/x64/Release/Roman Decimal Converter GUI"
}

QT += core
QT += widgets

LIBS += -L"."
INCLUDEPATH += ./Include
PRECOMPILED_HEADER = stdafx.h
OBJECTS_DIR += ../bin/int
DEPENDPATH += .
MOC_DIR += .
UI_DIR += .
RCC_DIR += .

include(RomanDecimalConverterGUI.pri)
