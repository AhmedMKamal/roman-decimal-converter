#include "stdafx.h"
#include "RomanDecimalConverter.h"

int bootstrap(int argc, char* argv[])
{
    QApplication::setApplicationName("Roman Decimal Converter");
    QApplication::setApplicationVersion("1.0.0");

    QApplication app(argc, argv);

    RomanDecimalConverter window;
    window.show();

    return QApplication::exec();
}

#ifdef _WIN32

INT WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR lpCmdLine,
    INT nCmdShow
)
{
    (void)(hInstance);
    (void)(hPrevInstance);
    (void)(lpCmdLine);
    (void)(nCmdShow);

    return bootstrap(__argc, __argv);
}

#else
int main(int argc, char* argv[])
{
    return bootstrap(argc, argv);
}
#endif
