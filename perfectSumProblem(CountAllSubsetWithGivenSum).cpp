class Solution{

	public:
	
	int solve (int* arr, int n, int sum, int** dp)
    {
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        if (arr[n - 1] <= sum)
            dp[n][sum] = (solve (arr, n - 1, sum - arr[n - 1], dp) % 1000000007 + solve (arr, n - 1, sum, dp) % 1000000007) % 1000000007;
        else
            dp[n][sum] = solve (arr, n - 1, sum, dp) % 1000000007;
        return dp[n][sum];
            
    }
	
	int perfectSum(int arr[], int n, int k)
	{
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