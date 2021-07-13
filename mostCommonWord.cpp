class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int len = paragraph.size();
        for (int i = 0; i < len; i++)
            if (!isalpha (paragraph[i]))
                paragraph[i] = ' ';
            else
                paragraph[i] = tolower (paragraph[i]);
        map <string, int> bannedMap;
        for (auto i : banned)
            bannedMap[i]++;
        map <string, int> newMap;
        stringstream ss (paragraph);
        string maxFreqString;
        int maxFreq = INT_MIN;
        string words;
        while (ss >> words)
        {
            if (bannedMap[words] == 0)
            {
                //cout << words << '\t';
                newMap[words]++;
                if (newMap[words] > maxFreq)
                {
                    maxFreq = newMap[words];
                    maxFreqString = words;
                }
            }
        }
        return maxFreqString;
    }
};