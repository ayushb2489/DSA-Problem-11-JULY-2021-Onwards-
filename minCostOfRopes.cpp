class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue <long long , vector <long long>, greater <long long> > q;
        for (int i = 0; i < n; i++)
            q.push (arr[i]);
        long long  temp1, temp2;
        long long mainSum = 0;
        long long tempSum ;
        while (!q.empty())
        {
            temp1 = q.top();
            q.pop();
            if (q.empty())
                return mainSum;
            temp2 = q.top();
            q.pop();
            tempSum = temp1 + temp2;
            q.push (tempSum);
            mainSum += tempSum;
        }
        return mainSum;
    }
};