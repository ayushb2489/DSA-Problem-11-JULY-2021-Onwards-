class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int temp, counter;
        for (int i = 0; i < n; i++)
        {
            temp = nums[i];
            counter = 0;
            for (int j = 0; j < n; j++)
                if (nums[j] == temp)
                    counter++;
            if (counter == 1)
                return nums[i];
        }
        return nums[0];
    }
};