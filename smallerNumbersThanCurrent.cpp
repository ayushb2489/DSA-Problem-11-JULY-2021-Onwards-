class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector <int> retVector;
        for (int i = 0; i < n; i++)
        {
            int counter = 0;
            for (int j = 0; j < n; j++)
                if (j != i && nums[j] < nums[i])
                    counter++;
            retVector.push_back (counter);
        }
        return retVector;
    }
};