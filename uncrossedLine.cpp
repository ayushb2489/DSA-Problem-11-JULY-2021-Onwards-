class Solution {
public:
    
    unordered_map <string, int> dp;
    
    int maxLines (vector <int> arr1, int n, vector <int> arr2, int m)
    {
        if (n == 0 || m == 0)
            return 0;
        
        string key = to_string (n) + "*" + to_string (m);
        
        if (dp.find (key) != dp.end())
            return dp[key];
        
        if (arr1[n - 1] == arr2[m - 1])
            dp[key] = 1 + maxLines (arr1, n - 1, arr2, m - 1);
        else
            dp[key] = max (maxLines (arr1, n - 1, arr2, m), maxLines (arr1, n, arr2, m - 1));
        
        return dp[key];
    } 
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        
        /*
        ITERATIVE BOTTOM-UP EXTREMELY FASTER THAN RECURSIVE
        
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
        
        
        */
        
        return maxLines (nums1, n, nums2, m);
    }
};