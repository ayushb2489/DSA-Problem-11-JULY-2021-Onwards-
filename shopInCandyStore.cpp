class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort (candies, candies + n);
        int minAmount = 0;
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            minAmount += candies[start++];
            end = end - k;
        }
        start = 0;
        int maxAmount = 0;
        end = n - 1;
        while (end >= start)
        {
            maxAmount += candies[end--];
            start = start + k;
        }
        vector <int> retVector;
        retVector.push_back (minAmount);
        retVector.push_back (maxAmount);
        return retVector;
    }
};