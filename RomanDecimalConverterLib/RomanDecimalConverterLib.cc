/**
 * The Rules:
 *
 * 1. When a symbol appears after a larger (or equal) symbol it is added.
 *
 *      Example: VI = V + I = 5 + 1 = 6
 *      Example: LXX = L + X + X = 50 + 10 + 10 = 70
 *
 * 2. But if the symbol appears before a larger symbol it is subtracted.
 *
 *      Example: IV = V − I = 5 − 1 = 4
 *      Example: IX = X − I = 10 − 1 = 9
 *
 * To Remember: After Larger is Added:
 *
 *      Don't use the same symbol more than three times in a row,
 *      but IIII is sometimes used for 4, particularly on clocks.
 *
 */

#include "RomanDecimalConverterLib.h"

#include <map>
#include <vector>
#include <algorithm>

#define VECTOR_INDEX(/* int */ x) (static_cast<std::vector<int>::size_type>(x))

struct RomanSymbolsCombination
{
    const std::string roman;
    const unsigned int decimal;
};

std::map<char, int> RomanSymbols
{
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 },
};

std::map<std::string, int> Combinations
{
};

const std::vector<std::string> RomanOnesCombinations = {
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};

const std::vector<std::string> RomanTensCombinations = {
    "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
};

const std::vector<std::string> RomanHundredCombinations = {
    "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
};

bool RomanDecimalConverterLib::IsRomanNumber(const std::string& roman)
{
    if (roman.empty())
    {
        return false;
    }

    for (const char& c : roman)
    {
        if (RomanSymbols[c] == 0)
        {
            return false;
        }
    }
    return true;
}

bool RomanDecimalConverterLib::IsDecimalNumber(const std::string& decimal)
{
    try
    {
        std::stod(decimal);
        return true;
    }
    catch (std::exception&)
    {
        return false;
    }
}

std::string RomanDecimalConverterLib::ConvertToRoman(const std::string& decimal)
{
    try
    {
        auto decimalValue = static_cast<unsigned int>(std::stod(decimal));

        std::string romalValue(decimalValue / 1000, 'M');
        decimalValue = (decimalValue % 1000);

        int index = (decimalValue / 100) - 1;
        if (RomanHundredCombinations.size() > VECTOR_INDEX(index))
        {
            romalValue += RomanHundredCombinations[index];
            decimalValue = decimalValue % 100;
        }

        index = (decimalValue / 10) - 1;
        if (RomanTensCombinations.size() > VECTOR_INDEX(index))
        {
            romalValue += RomanTensCombinations[index];
            decimalValue = decimalValue % 10;
        }

        index = decimalValue - 1;
        if (RomanOnesCombinations.size() > VECTOR_INDEX(index))
        {
            romalValue += RomanOnesCombinations[index];
        }

        return romalValue;
    }
    catch (std::exception& e)
    {
        return e.what();
    }
}

double RomanDecimalConverterLib::ConvertToDecimal(const std::string& roman)
{
    int decimal = 0;

    for (int i = 0; i < roman.length() - 1; ++i)
    {
        if (RomanSymbols[roman[i]] < RomanSymbols[roman[i + 1]])
        {
            decimal -= RomanSymbols[roman[i]];
        } else
        {
            decimal += RomanSymbols[roman[i]];
        }
    }
    decimal += RomanSymbols[roman[roman.length() - 1]];

    return  decimal;
}
