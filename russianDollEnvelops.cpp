class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n = arr.size();
        
        sort (arr.begin(), arr.end());
        
        int dp[n];
        for (int i = 0; i < n; i++)
            dp[i] = 1;
        
        int maxE = dp[0];
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1] && dp[i] < dp[j] + 1)
                    dp[i] += 1;
                maxE = max (maxE, dp[i]);
            }
        }
        
        return maxE;
    }
};