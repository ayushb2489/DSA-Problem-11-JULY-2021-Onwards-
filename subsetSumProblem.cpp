class Solution{   
public:

    bool solve (int* arr, int n, int sum, int** dp)
    {
        if (sum == 0)
            return true;
        if (n == 0)
            return false;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (arr[n - 1] <= sum)
            dp[n][sum] = solve (arr, n - 1, sum - arr[n - 1], dp) || solve (arr, n - 1, sum, dp);
        else
            dp[n][sum] = solve (arr, n - 1, sum, dp);
        return dp[n][sum];
            
    }
    
    bool isSubsetSum(int n, int arr[], int k){
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[k + 1];
            for (int j = 0; j <= k; j++)
                dp[i][j] = -1;
        }
        return solve (arr, n, k, dp);
    }
};