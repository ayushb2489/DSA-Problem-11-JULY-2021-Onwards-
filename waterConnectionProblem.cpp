class Solution
{
    public:
    
    bool is (int value, vector <int> b)
    {
        for (int i = 0; i < b.size(); i++)
            if (b[i] == value)
                return true;
        return false;
    }
    
    int getFinal (int value, map <int, int> way, int &minDiameter, map <int, int> pipeSize)
    {
        if (way[value] == 0)
            return value;
        if (pipeSize[way[value]] < minDiameter)
            minDiameter = pipeSize[way[value]];
        return getFinal (way[value], way, minDiameter, pipeSize);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        map <int, int> way;
        map <int, int> pipeSize;
        for (int i = 0; i < a.size(); i++)
            way[a[i]] = b[i];
        for (int i = 0; i < b.size(); i++)
            pipeSize[b[i]]= d[i];
        vector <int> uniq;
        for (int i = 0; i < a.size(); i++)
            if (!is (a[i],b))
                uniq.push_back (a[i]);
        vector < vector <int> > resVector;
        vector <int> tempVector;
        for (int i = 0; i < uniq.size(); i++)
        {
            tempVector.push_back (uniq[i]);
            int minDiameter = INT_MAX;
            int temp = getFinal (uniq[i], way, minDiameter, pipeSize);
            tempVector.push_back (temp);
            tempVector.push_back (minDiameter);
            resVector.push_back (tempVector);
            tempVector.clear();
        }
        sort (resVector.begin(), resVector.end());
        return resVector;
    }
};