class Solution{
  public:
    
    bool inter (string a, int as, int ai, string b, int bs, int bi, string c, int cs, int ci, unordered_map <string, bool> dp)
    {
        if (cs == ci)
            return true;
        
        if (ai >= as && bi >= bs)
            return false;
        
        string key = to_string (ai) + "*" + to_string (bi) + "*" + to_string (ci);
        
        if (dp.find (key) != dp.end())
            return dp[key];
        
        bool temp1 = false;
        bool temp2 = false;
        
        if (ai < as && a[ai] == c[ci])
            temp1 = inter (a, as, ai + 1, b, bs, bi, c, cs, ci + 1, dp);
        
        if (bi < bs && b[bi] == c[ci])
            temp2 = inter (a, as, ai, b, bs, bi + 1, c, cs, ci + 1, dp);
        
        dp[key] = temp1 || temp2;
        
        return temp1 || temp2;
    }
    
    bool isInterleave(string a, string b, string c) 
    {
        int as = a.size();
        int bs = b.size();
        int cs = c.size();
        unordered_map <string, bool> dp;
        
        return inter (a, as, 0, b, bs, 0, c, cs, 0, dp);
    }
};