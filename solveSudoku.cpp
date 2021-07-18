class Solution 
{
    public:
    
    bool valid (int grid[N][N], int ii, int ji, int value)
    {
        for (int i = 0; i < 9; i++)
            if (grid[i][ji] == value)
                return false;
        for (int j = 0; j < 9; j++)
            if (grid[ii][j] == value)
                return false;
        for (int i = 3 * (ii / 3); i < 3 * ((ii / 3) + 1); i++)
            for (int j = 3 * (ji / 3); j < 3 * ((ji / 3) + 1); j++)
                if (grid[i][j] == value)
                    return false;
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    bool temp;
                    for (int k = 1; k <= 9; k++)
                    {
                        if (valid (grid, i, j, k))
                        {
                            grid[i][j] = k;
                            temp = SolveSudoku (grid);
                            if (temp)
                                return true;
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void printGrid (int grid[N][N]) 
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << grid[i][j] << " ";
        }
    
    }
};