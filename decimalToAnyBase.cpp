#include <iostream>
#include <algorithm>
using namespace std;

string decimalToAnyBase (float number, int base)
{
    string retString = "";
    int beforeDot = number;
    float afterDot = number - beforeDot;
    while (beforeDot != 0)
    {
        retString += to_string(beforeDot % base);
        beforeDot = beforeDot / base;
    }
    reverse (retString.begin(), retString.end());
    retString += '.';
    int precision = 8;
    while (precision--)
    {
        if (afterDot == 0)
            break;
        while (afterDot < 1)
        {
            afterDot *= base;
            if (afterDot < 1)
                retString += '0';
        }
        retString += to_string((int)afterDot);
        afterDot -= (int)afterDot;
    }
    return retString;
}

int main()
{
    int base;
    cin >> base;
    float number;
    cin >> number;
    cout << decimalToAnyBase (number, base);
    return 0;
}
