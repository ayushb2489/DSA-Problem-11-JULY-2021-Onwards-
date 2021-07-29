class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        int leftMin[n];
        leftMin[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMin[i] = max (leftMin[i - 1], height[i]);
        int rightMin[n];
        rightMin[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMin[i] = max (rightMin[i + 1], height[i]);
        int water = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int temp = min (leftMin[i], rightMin[i]);
            if (temp > height[i])
                water += temp - height[i];
        }
        return water;
    }
};


[[12,13, 1,12],
 [13, 4,13,12],
 [13, 8,10,12],
 [12,13,12,12],
 [13,13,13,13]]