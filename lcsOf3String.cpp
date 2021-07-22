int LCSof3 (string a, string b, string c, int x, int y, int z)
{
    int dp[x + 1][y + 1][z + 1];
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            for (int k = 0; k <= z; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                    dp[i][j][k] =  dp[i - 1][j - 1][z - 1] + 1;
                else
                    dp[i][j][k] = max (max (dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
            }
        }
    }
    return dp[x][y][z];
}