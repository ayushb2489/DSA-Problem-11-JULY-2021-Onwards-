class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        map <int, pair <int, int> > prefixSum;
        int ps = 0;
        
        int totalSum = 0;
        for (int i = 0; i < n; i++)
            totalSum += nums[i];
        
        int targetSum = totalSum - x;
        int maxS = 0;
        for (int i = 0; i < n; i++)
        {
            ps += nums[i];
            prefixSum[ps] = {1, i};
            
            if (ps == targetSum)
                maxS = max (maxS, i + 1);
            
            if (prefixSum[ps - targetSum].first > 0)
                maxS = max (maxS, i - prefixSum[ps - targetSum].second);
        }
        
        if (maxS == 0 && targetSum != 0)
            return -1;
        
        return n - maxS;
    }
};