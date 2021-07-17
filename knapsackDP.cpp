#include <iostream>
#include <limits>
using namespace std;

bool prime (long long int n)
{
    if (n == 1)
        return false;
    if ( n== 2 )
        return true;
    for (long long int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

long long int minMovesToPrime (int n)
{
    //if (n == 1 )
     //   return 3;
    for (long long int i = n + 1;; i++)
        if (prime (i))
            return i - n;
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    long long int minMoves[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            minMoves[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!prime (arr[i][j]))
                minMoves[i][j] = minMovesToPrime (arr[i][j]);
    long long int mm = 1000000000000;
    for (int i = 0; i < n; i++)
    {
        long long int tempSum = 0;
        for (int j = 0; j < m; j++)
            tempSum += minMoves[i][j];
        if (tempSum < mm)
            mm = min(tempSum, mm);
    }
    for (int i = 0; i < m; i++)
    {
        long long int tempSum = 0;
        for (int j = 0; j < n; j++)
            tempSum += minMoves[j][i];
        if (tempSum < mm)
            mm = min(tempSum, mm);
    }
    cout << mm;

}