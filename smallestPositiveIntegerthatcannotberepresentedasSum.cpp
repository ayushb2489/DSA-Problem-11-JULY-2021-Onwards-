class Solution
{   
public:
    long long smallestpositive(vector<long long> arr, int n)
    { 
        long long missing = 1;
        sort (arr.begin(), arr.end());
        
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > missing)
                return missing;
            missing += arr[i];
        }
        return missing;
    } 
};