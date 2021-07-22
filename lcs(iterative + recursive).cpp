class Solution
{
    public:

    
    int lcsR (string s1, string s2, int x, int y, int** dp)
    {
        if (x == 0 || y == 0)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        if (s1[x - 1] == s2[y - 1])
            dp[x][y] = 1 + lcsR (s1, s2, x - 1, y - 1, dp);
        else
            dp[x][y] = max (lcsR (s1, s2, x - 1, y, dp), lcsR (s1,s2, x, y - 1, dp));
        return dp[x][y];
    }
    
    int lcsI (string s1, string s2, int x, int y, int** dp)
    {
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max (dp[i - 1][j] , dp[i][j - 1]);
            }
        }
        return dp[x][y];
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        int** dp = new int*[x + 1];
        for (int i = 0; i <= x; i++)
        {
            dp[i] = new int[y + 1];
            for (int j = 0; j <= y; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -1;
        }
        return lcsI (s1, s2, x, y, dp);
    }
};
