class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector <int> res (s.size(), INT_MAX);
        bool start = false;
        int counter = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c)
            {
                start = true;
                res[i] = 0;
                counter = 1;
            }
            else if (start)
                res[i] = counter++;
        }
        start = false;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == c)
            {
                start = true;
                res[i] = 0;
                counter = 1;
            }
            else if (start)
                res[i] = min (counter++, res[i]);
        }
        return res;
    }
};