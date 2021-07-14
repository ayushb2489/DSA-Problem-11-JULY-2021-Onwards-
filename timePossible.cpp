#include <iostream>
using namespace std;

int countBits (int i, int j)
{
    int counter = 0, h = 0, m = 0;
    while (i != 0  && h < 4)
        counter += (i >> h++) & 1;
    while (j != 0 && m < 6)
        counter += (j >> m++) & 1;
    return counter;
}

int timePossible (int n)
{
    for (int i = 0; i <= 11; i++)
        for (int j = 0; j <= 59; j++)
            if (countBits (i, j) == n)
                if ( j < 10)
                    cout << i << " : 0" << j << '\n';
                else
                    cout << i << " : " << j << "\n";
}

int main()
{
    int n;
    cin >> n;
    cout << timePossible (n);
    return 0;
}
