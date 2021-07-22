int minDeletions(string s, int n) { 
	string t = s;
	reverse (s.begin(), s.end());
	int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return n - dp[n][n];
} 