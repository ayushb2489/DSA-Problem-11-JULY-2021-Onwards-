class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        map <int, pair <int, int> > prefixSum;
        int ps = 0;
        int maxS = 0;
        
        for (int i = 0; i < n; i++)
        {
            ps += arr[i];
            
            if (prefixSum[ps].first == 0)
                prefixSum[ps] = {1, i};
            
            if (ps == k)
                maxS = max (maxS, i + 1);
            
            if (prefixSum[ps - k].first > 0)
                maxS = max (maxS, i - prefixSum[ps - k].second);
        }
        return maxS;
    } 

};