# Roman Numeral to Decimal numbers Converter

The numeric system represented by Roman numerals originated in ancient Rome and
remained the usual way of writing numbers throughout Europe well into the Late
Middle Ages. Roman numerals, as used today, employ seven symbols, each with a
fixed integer value.

See the below table the Symbol — Value pairs:

- I — 1
- V — 5
- X — 10
- L — 50
- C — 100
- D — 500
- M — 1000


## User Stories

![Screenshot][SCREENSHOT]

- A user should be able to enter one Roman number in an input field.
- A user could see the results in a single output field containing the decimal
(base 10) equivalent of the roman number that was entered by pressing a button.
- If a wrong symbol is entered, the User should see an error.


## Bonus features

- A user could see the conversion to be made automatically as they type.
- A user should be able to convert from decimal to Roman (vice-versa).


## What's included in this repository

This repository contains two C++ projects, one is the DLL library which
responsible for the Roman-Decimal conversion, and the other project is a
QT5 GUI application in which a user can interact and use the library.


## Bonus features

This codebase is configured to be built using either Visual Studio in Windows
or QMake across platforms.

See [`Roman Decimal Converter.sln`][SOLUTION_FILE] or [RomanDecimalConverterGUI.pro][PRO_FILE]

[SCREENSHOT]: https://raw.githubusercontent.com/AhmedMKamal/roman-decimal-converter/master/.github/roman-decimal-converter-gui.png
[SOLUTION_FILE]: https://github.com/AhmedMKamal/roman-decimal-converter/blob/master/Roman%20Decimal%20Converter.sln
[PRO_FILE]: https://github.com/AhmedMKamal/roman-decimal-converter/blob/master/RomanDecimalConverterGUI.pro

## Note

This project was originally made as a side/practical project, so, feel free to fork/edit/use it as you need :relaxed:.
