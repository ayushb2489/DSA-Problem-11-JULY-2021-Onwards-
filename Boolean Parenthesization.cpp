class Solution{
public:

    int mcm (string str, int left, int right, bool target, int*** dp)
    {
        if (left > right)
            return 0;
        if (dp[left][right][target] != -1)
            return dp[left][right][target];
        if (left == right)
        {
            if (str[left] == 'T')
                if (target == true)
                {
                    dp[left][right][target] = 1;
                    return 1;
                }
                else
                {
                    dp[left][right][target] = 0;
                    return 0;
                }
            else
                if (target == false)
                {
                    dp[left][right][target] = 1;
                    return 1;
                }
                else
                {
                    dp[left][right][target] = 0;
                    return 0; 
                }
        }
        int ans = 0;
        for (int k = left + 1; k < right; k = k + 2)
        {
            int lt, rt, lf, rf;
            if (dp[left][k - 1][1] != -1)
                lt = dp[left][k - 1][1];
            else
                lt = mcm (str, left, k - 1, true, dp);
            if (dp[k + 1][right][1] != -1)
                rt = dp[k + 1][right][1];
            else
                rt = mcm (str, k + 1, right, true, dp);
            if (dp[left][k - 1][0] != -1)
                lf = dp[left][k - 1][0];
            else
                lf = mcm (str, left, k - 1, false, dp);
            if (dp[k + 1][right][0] != -1)
                rf = dp[k + 1][right][0];
            else
                rf = mcm (str, k + 1, right, false, dp);
            if (str[k] == '^')
            {
                if (target == true)
                    ans += lt * rf + lf * rt;
                else 
                    ans += lt * rt + lf * rf;
            }
            else if (str[k] == '&')
            {
                if (target == true)
                    ans += lt * rt;
                else
                    ans += lf * rt + lt * rf + lf * rf;
            }
            else if (str[k] == '|')
            {
                if (target == true)
                    ans += lt * rf + lf * rt + lt * rt;
                else
                    ans += lf * rf;
            }
        }
        dp[left][right][target ? 1 : 0] = ans % 1003;
        return dp[left][right][target ? 1 : 0];
    }
    
    int countWays(int N, string S){
        int*** dp = new int**[N + 1];
        for (int i = 0; i <= N; i++)
        {
            dp[i] = new int*[N + 1];
            for (int j = 0; j <= N; j++)
            {
                dp[i][j] = new int[2];
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        return mcm (S, 0, N - 1, true, dp);
    }
};