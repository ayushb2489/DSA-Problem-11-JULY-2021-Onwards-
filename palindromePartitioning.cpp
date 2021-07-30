class Solution{
public:

    bool isPalindrome (string str, int start, int end)
    {
        int wait = (start + end) / 2;
        while (start <= wait)
        {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    int noOfPartition (string &str, int start, int end, int** dp)
    {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            dp[start][end];
        if (isPalindrome (str, start, end))
        {
            dp[start][end] = 0;
            return 0;
        }
        int minP = INT_MAX;
        for (int k = start; k < end; k++)
        {
            int tempAns = 1;
            if (dp[start][k] != -1)
                tempAns += dp[start][k];
            else 
                tempAns += noOfPartition (str, start, k, dp);
            if (dp[k + 1][end] != -1)
                tempAns += dp[k + 1][end];
            else
                tempAns += noOfPartition (str, k + 1, end, dp);
            minP = min (tempAns, minP);
        }
        dp[start][end] = minP;
        return dp[start][end];
    }

    int palindromicPartition(string &str)
    {
        int n = str.size();
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        }
        return noOfPartition (str, 0, n - 1, dp);
    }
};