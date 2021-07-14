#include <iostream>
#include <algorithm>
using namespace std;

bool powerOf4 (int n)
{
    if (n % 4 != 0)
        return false;
    if (n == 4 || n == 0)
        return true;
    return powerOf4 (n / 4);
}

int main()
{
    int n;
    cin >> n;
    if (powerOf4 (n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
