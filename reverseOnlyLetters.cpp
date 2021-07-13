class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            int counter = 0;
            if (!isalpha (s[i]))
            {
                i++;
                counter++;
            }
            if (!isalpha (s[j]))
            {
                j--;
                counter++;
            }
            if (!counter)
            {
                swap (s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};