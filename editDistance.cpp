class Solution {
  public:
    
    int dp[101][101];
    
    int edit (string s, int n, string t, int m)
    {
        if (n == 0 && m == 0)
            return 0;
            
        if (n == 0 || m == 0)
            return abs (m - n);
            
        if (dp[n][m] != -1)
            return dp[n][m];
        
        int temp1 = INT_MAX;
        int temp2 = INT_MAX;
        int temp3 = INT_MAX;
        int temp4 = INT_MAX;
        
        if ( s[n - 1] == t[m - 1])
            temp1 = edit (s, n - 1, t, m - 1);
        else
        {
            temp2 = 1 + edit (s, n, t, m - 1);
            temp3 = 1 + edit (s, n - 1, t, m);
            temp4 = 1 + edit (s, n - 1, t, m - 1);
        }
        
        dp[n][m] = min (min (temp1, temp4), min (temp2, temp3));
        
        return dp[n][m];
    }
    
    int editDistance(string s, string t) {
        int m = t.size();
        int n = s.size();
        
        memset (dp, -1, sizeof (dp));
        
        return edit (s, n, t, m);
    }
};