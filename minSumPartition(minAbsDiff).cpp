class Solution{

  public:
  
    void solve (int* arr, int n, int sum, int** dp, int &minS, int totalSum)
    {
        if (n == 0)
        {
            minS = min (minS, abs (sum - (totalSum - sum)));
            dp[n][sum] = 1;
            return ;
        }
        if (dp[n][sum] != -1)
            return ;
        
        solve (arr, n - 1, sum, dp, minS, totalSum);
        solve (arr, n - 1, sum + arr[n - 1], dp, minS, totalSum);
        dp[n][sum] = 1;
    }
  
	int minDifference(int arr[], int n)  { 
	    
	    int totalSum = 0;
	    for (int i = 0; i < n; i++)
	        totalSum += arr[i];
	    
	    int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[totalSum + 1];
            for (int j = 0; j <= totalSum; j++)
                dp[i][j] = -1;
        }
        int minS = INT_MAX;
        solve (arr, n, 0, dp, minS, totalSum);
        return minS;
	} 
};