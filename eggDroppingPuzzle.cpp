class Solution
{
    public:
    int eggDrop1(int n, int k, int** dp) 
    {
        if (n == 1)
            return k;
        if (k == 0 || k == 1)
            return k;
        if (dp[n][k] != -1)
            return dp[n][k];
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            int temp = 1 + max (eggDrop1 (n - 1, i - 1, dp), eggDrop1 (n, k - i, dp));
            ans = min (ans, temp);
        }
        dp[n][k] = ans;
        return dp[n][k];
    }
    int eggDrop (int n, int k)
    {
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[k + 1];
            for (int j = 0; j <= k; j++)
                dp[i][j] = -1;
        }
        return eggDrop1 (n, k, dp);
    }
};