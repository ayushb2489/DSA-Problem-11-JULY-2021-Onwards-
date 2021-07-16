class Solution{
    public:
    
    bool valid (vector <vector <int> > maze, int n, int i, int j, int** path)
    {
        if (i >= 0 && i < n && j >= 0 && j < n)
            if (maze[i][j] == 1 && path[i][j] == -1)
                return true;
        return false;
    }
    
    void getPath (vector <vector <int> > maze, int n, int i, int j, string maintainedString, vector <string> &retVector, int** path)
    {
        if (i == n - 1 && j == n - 1)
        {
            retVector.push_back (maintainedString);
            return;
        }
        path[i][j] = 1;
        if (valid (maze, n, i + 1, j, path))
            getPath (maze, n, i + 1, j, maintainedString + "D", retVector, path);
        if (valid (maze, n, i, j + 1, path))
            getPath (maze, n, i, j + 1, maintainedString + "R", retVector, path);
        if (valid (maze, n, i - 1, j, path))
            getPath (maze, n, i - 1, j, maintainedString + "U", retVector, path);
        if (valid (maze, n, i, j - 1, path))
            getPath (maze, n, i, j - 1, maintainedString + "L", retVector, path);
        path[i][j] = -1;
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        int** path = new int*[n];
        for (int i = 0; i < n; i++)
        {
            path[i] = new int[n];
            for (int j = 0; j < n; j++)
                path[i][j] = -1;
        }
    vector <string> retVector;
    if (valid (maze, n, 0, 0, path))
        getPath (maze, n, 0, 0, "", retVector, path);
    sort (retVector.begin(), retVector.end());
    return retVector;
    }
};