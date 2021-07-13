#include <iostream>
using namespace std;

float toDecimal (string number, int base)
{
    int len = number.size();
    int index = len;
    for (int i = 0; i < len; i++)
        if (number[i] == '.')
        {
            index = i;
            break;
        }
    int positive = index - 1;
    int p = 0;
    float retNumber = 0.0;
    while (positive >= 0)
        retNumber += 1.0 * pow (base, p++) * ((int)number[positive--] - '0');
    int negative = index + 1;
    p = -1;
    while (negative < len)
        retNumber += 1.0 * pow (base, p--) * ((int)number[negative++] - '0');
    return retNumber;
}

int main()
{
    int base;
    cin >> base;
    string number;
    cin >> number;
    cout << toDecimal (number, base);
    return 0;
}
