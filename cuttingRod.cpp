

#include <bits/stdc++.h>
using namespace std;
  
int rodCutting (int* price, int* length, int n, int counter, int** dp)
    {
    if (n == 0)
        return 0;
    if (counter == 0)
        return 0;
    if (dp[n][counter] != -1)
        return dp[n][counter];
    if (length[counter - 1] <= n)
        dp[n][counter] =  max (price [counter - 1] + rodCutting (price, length, n - length[counter - 1], counter, dp),
                     rodCutting (price, length, n, counter - 1, dp));
    else
        dp[n][counter] = rodCutting (price, length, n, counter - 1, dp);
    return dp[n][counter];
    }  
int cutRod(int price[], int n) 
        {
        int length[n];
        for (int i = 0; i < n; i++)
            length[i] = i + 1;
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        }
        return rodCutting (price, length, n, n, dp);
        }



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  