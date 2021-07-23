class Solution{
public:

    int mcm (int* arr, int start, int end, int** dp)
    {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int minO = INT_MAX;
        for (int k = start; k < end; k++)
        {
            int temp = mcm (arr, start, k, dp) + mcm (arr, k + 1, end, dp) + arr[start - 1] * arr[k] * arr[end];
            if (temp < minO)
                minO = temp;
        }
        dp[start][end] = minO;
        return dp[start][end];
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        int** dp = new int*[n + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        }
        return mcm (arr, 1, n - 1, dp);
    }
};