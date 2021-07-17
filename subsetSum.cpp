#include <iostream>
using namespace std;

bool subset (int* arr, int n, int sum, int** dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    if (arr[n - 1] <= sum)
        dp[n][sum] = subset (arr, n - 1, sum - arr[n - 1], dp) || subset (arr, n - 1, sum, dp);
    else
        dp[n][sum] = subset (arr, n - 1, sum, dp);
    return dp[n][sum];
}

bool subsetDP (int* arr, int n, int sum, int** dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n,sum;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sum;
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[sum + 1];
        for (int j = 0; j <= sum; j++)
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
    }
    if (subsetDP (arr, n, sum, dp))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
