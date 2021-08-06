class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    for (int i = 0; i < n; i++)
	        dp[i] = arr[i];
	        
	    int maxSum = dp[0];
	         
	    for (int i = 1; i < n; i++)
	    {
	        for (int j = 0; j < i; j++)
	        {
	            if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i])
	                dp[i] = dp[j] + arr[i];
	            maxSum = max (maxSum, dp[i]);
	        }
	    }
	    
	    return maxSum;
	}  
};