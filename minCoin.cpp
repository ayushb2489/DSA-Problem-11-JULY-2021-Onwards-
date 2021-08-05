class Solution{
	public:
	
	map <string, int> dp;
	
    int minCoin (vector <int> nums, int n, int sum)
    {
        if (sum == 0)
            return 0;
            
        if (n == 0)
            return INT_MAX;
        
        string key = to_string (n) + "*" + to_string (sum);
        
        if (dp.find (key) != dp.end())
            return dp[key];
        
        int temp1 = 1000000;
        int temp2 = 1000000;
        
        if (nums[n - 1] <= sum)
            temp1 = 1 + minCoin (nums, n, sum - nums[n - 1]);
            
        temp2 = minCoin (nums, n - 1, sum);
        
        dp[key] = min (temp1, temp2);
        
        return dp[key];
    }
	
	int MinCoin(vector<int>nums, int amount)
	{
	    int temp = INT_MAX;
	    int n = nums.size();
	    
	    temp = minCoin (nums, n, amount);
	    
	    //cout << temp << "\n";
	    
	    if (temp >= 1000000)
	        return -1;
	   
	    return temp;
	}
};