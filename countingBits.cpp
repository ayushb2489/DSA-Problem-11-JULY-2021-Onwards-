class Solution {
public:

    int countOnes (int n)
    {
        if (n == 0)
            return 0;
        int iterator = 0;
        int counter = 0;
        while (n != 0 && iterator < 32)
            counter += (n >> iterator++) & 1;
        return counter;
    }

    vector<int> countBits(int n) {
        vector <int> retArray;
        for (int i = 0; i <= n; i++)
            retArray.push_back (countOnes (i));
        return retArray;
    }
};
