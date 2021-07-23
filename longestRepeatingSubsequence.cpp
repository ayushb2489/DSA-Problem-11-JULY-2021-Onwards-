int n = s.size();
		    int m = t.size();
		    int** dp = new int*[n + 1];
		    for (int i = 0; i <= n; i++)
		    {
		        dp[i] = new int[m + 1];
		        for (int j = 0; j <= m; j++)
		        {
		            if (i == 0 || j == 0)
		                dp[i][j] = 0;
		            else if (s[i - 1] == t[j - 1])
		                dp[i][j] = 1 + dp[i - 1][j - 1];
		            else
		                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
		        }
		    }