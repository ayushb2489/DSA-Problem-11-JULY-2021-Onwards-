class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int sNumber = 0;
        for (int i = 0; i < n; i++)
            sNumber ^= nums[i];
        return sNumber;
    }
};