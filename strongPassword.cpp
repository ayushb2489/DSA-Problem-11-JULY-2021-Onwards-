#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    bool lower = false, upper = false, digit = false, special = false;
    for (int i = 0; i < n; i++)
    {
        if (islower (str[i]))
            lower = true;
        else if (isupper (str[i]))
            upper = true;
        else if (isdigit (str[i]))
            digit = true;
        else
            special = true;
    }
    int sum = 0;
    if (!lower)
        sum += 1;
    if (!upper)
        sum += 1;
    if (!digit)
        sum += 1;
    if (!special)
        sum += 1;
    if (6 - n > sum)
        cout << 6 - n;
    else
        cout << sum;
    return 0;
}
