class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
        string retString = "";
        while (n > 0 && m > 0)
        {
            if (str1[n - 1] == str2[m - 1])
            {
                retString = str1[n - 1] + retString;
                n--;
                m--;
            }
            else if (dp[n][m - 1] > dp[n - 1][m])
            {
                retString = str2[m - 1] + retString;
                m--;
            }
            else
            {
                retString = str1[n - 1] + retString;
                n--;
            }
        }
        while (n > 0)
        {
            retString = str1[n - 1] + retString;
            n--;
        }
        while (m > 0)
        {
            retString = str2[m - 1] + retString;
            m--;
        }
        return retString;
    }
};