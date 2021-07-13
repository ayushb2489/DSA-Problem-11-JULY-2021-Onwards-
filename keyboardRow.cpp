class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map <char, int> rows;
        rows['q'] = 1, rows['w'] = 1, rows['e'] = 1, rows['r'] = 1, rows['t'] = 1, rows['y'] = 1, 
        rows['u'] = 1, rows['i'] = 1, rows['o'] = 1, rows['p'] = 1, rows['a'] = 2, rows['s'] = 2, 
        rows['d'] = 2, rows['f'] = 2, rows['g'] = 2, rows['h'] = 2, rows['j'] = 2, rows['k'] = 2, 
        rows['l'] = 2,  rows['z'] = 3, rows['x'] = 3, rows['c'] = 3, rows['v'] = 3, 
        rows['b'] = 3, rows['n'] = 3, rows['m'] = 3;
        int len = words.size();
        vector <string> res;
        for (int i = 0; i < len; i++)
        {
            bool different = false;
            int wordLen = words[i].size(), startingRow = rows[tolower (words[i][0])];
            for (int j = 1; j < wordLen && !different; j++)
                if (rows[tolower (words[i][j])] != startingRow)
                    different = true;
            if (!different)
                res.push_back (words[i]);
        }
        return res;
    }
};