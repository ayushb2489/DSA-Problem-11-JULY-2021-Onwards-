class Solution {
public:
    
    bool subsetSum (vector <int> nums, int n, int targetSum, int** dp)
    {
        if (targetSum == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][targetSum] != -1)
            return dp[n][targetSum];
        if (nums[n - 1] <= targetSum)
            dp[n][targetSum] = subsetSum (nums, n - 1, targetSum - nums[n - 1], dp) || subsetSum (nums, n - 1, targetSum, dp);
        else
            dp[n][targetSum] = subsetSum (nums, n - 1, targetSum, dp);
        return dp[n][targetSum];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (auto i : nums)
            totalSum += i;
        if (totalSum % 2 != 0)
            return false;
        int targetSum = totalSum / 2;
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[targetSum + 1];
            for (int j = 0; j <= targetSum; j++)
                if (j == 0)
                    dp[i][j] = 1;
                else if (n == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -1;
        }
        return subsetSum (nums, n, targetSum, dp);
    }
};