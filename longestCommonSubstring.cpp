class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int mainCounter = 0;
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[m + 1];
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                dp[i][j] = -1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    mainCounter = max (dp[i][j], mainCounter);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return mainCounter;
    }
};