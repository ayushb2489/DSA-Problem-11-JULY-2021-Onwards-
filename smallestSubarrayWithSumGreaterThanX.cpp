class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        int sum = 0;
        int minS = INT_MAX;
        int i = 0;
        int j = -1;
        while (j < n)
        {
            while (sum <= x)
            {
                j++;
                if (j == n)
                    break;
                sum += arr[j];
            }
            while (sum > x)
            {
                minS = min (minS, j - i + 1);
                sum -= arr[i];
                i++;
            }
        }
        return minS;
    }
};