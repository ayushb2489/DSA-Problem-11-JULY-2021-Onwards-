class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort (a, a + n);
        long long int sum = 0;
        long long int val = pow (10,9) + 7;
        for (long long int i = 0; i < n; i++)
            sum += (a[i] * i);           
        return (sum%val);
    }
};
