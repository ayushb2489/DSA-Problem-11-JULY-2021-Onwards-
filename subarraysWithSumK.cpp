class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
        map <int, int> prefixSum;
        int ps = 0;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            ps += arr[i];
            prefixSum[ps]++;
            if (ps == k)
                counter++;
            if (prefixSum [ps - k] > 0)
                counter += prefixSum[ps - k];
        }
        return counter;
    }
};