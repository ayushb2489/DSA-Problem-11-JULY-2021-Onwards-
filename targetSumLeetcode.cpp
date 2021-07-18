class Solution {
public:
    
    int targetSum (vector <int> arr, int n, int targetS, int** dp)
    {
        if (n == 0)
            if (targetS == 0)
                return 1;
            else
                return 0;
        if (dp[n][targetS] != -1)
            return dp[n][targetS];
        if (arr[n - 1] <= targetS)
            dp[n][targetS] = targetSum (arr, n - 1, targetS - arr[n - 1], dp) + targetSum (arr, n - 1, targetS, dp);
        else
            dp[n][targetS] = targetSum (arr, n - 1, targetS, dp);
        return dp[n][targetS];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];
        int targetS;
        if ((totalSum + target) % 2 == 0)
            targetS = (totalSum + target) / 2;
        else
            return 0;
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[targetS + 1];
            for (int j = 0; j <= targetS; j++)
                dp[i][j] = -1;
        }
        return targetSum (nums, n, targetS, dp);
    }
};