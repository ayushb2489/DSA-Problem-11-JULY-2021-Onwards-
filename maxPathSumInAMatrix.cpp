class Solution{
public:
    
   
    int maximumPath(int n, vector<vector<int>> arr)
    {
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > 0 && j < n - 1)
                    arr[i][j] += max (arr[i - 1][j - 1], max (arr[i - 1][j], arr[i - 1][j + 1]));
                else if (j == 0 && j != n - 1)
                    arr[i][j] += max (arr[i - 1][j], arr[i - 1][j + 1]);
                    
                else if (j == n - 1 && j != 0)
                    arr[i][j] += max (arr[i - 1][j - 1], arr[i - 1][j]);
                    
                else
                    arr[i][j] += arr[i - 1][j];
            }
        }
        int maxV = INT_MIN;
        for (int j = 0; j < n; j++)
            maxV = max (maxV, arr[n - 1][j]);
        
        return maxV;
    }
};