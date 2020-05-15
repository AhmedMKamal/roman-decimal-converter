#pragma once

#include <string>

#ifdef _WIN32
#   define LIBRARY_API __declspec(dllexport)
#else
#   define LIBRARY_API
#endif

namespace RomanDecimalConverterLib
{
    LIBRARY_API bool IsRomanNumber(const std::string& roman);
    LIBRARY_API bool IsDecimalNumber(const std::string& decimal);

    LIBRARY_API std::string ConvertToRoman(const std::string& decimal);
    LIBRARY_API double ConvertToDecimal(const std::string& roman);
};
