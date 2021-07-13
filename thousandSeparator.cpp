class Solution {
public:
    string thousandSeparator(int n) {
        stringstream ss;
        ss << n;
        string newN;
        ss >> newN;
        int len = newN.size();
        int counter = 0;
        string retString = "";
        for (int i = len - 1; i >= 0; i--)
        {
            retString = newN[i] + retString;
            counter++;
            if (counter == 3 && i != 0)
            {
                retString = '.' + retString;
                counter = 0;
            }
        }
        return retString;
    }
};