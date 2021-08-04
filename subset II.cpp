public:
    
    void getSubset (vector <int> arr, int n, int index, vector <int> sub, set <vector <int> > &uniq)
    {
        if (index == n)
        {
            uniq.insert (sub);
            return;
        }
        
        sub.push_back (arr[index]);
        getSubset (arr, n, index + 1, sub, uniq);
        
        sub.pop_back ();
        getSubset (arr, n, index + 1, sub, uniq);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector <int> sub;
        set <vector <int> > uniq;
        getSubset (nums, n, 0, sub, uniq);
        
        set <vector <int> > uniq1;
        for (auto i : uniq)
        { 
            sort (i.begin(), i.end());
            uniq1.insert (i);
        }
        
        vector <vector <int> > result;
        for (auto i : uniq1)
            result.push_back (i);
        return result;
    }
};