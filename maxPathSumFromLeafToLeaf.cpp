class Solution {
public:

    int go (Node* root, int &maxSum)
    {
        if (root == NULL)
            return 0;
        int left = go (root -> left, maxSum);
        int right = go (root -> right, maxSum);
        //maxSum = max (maxSum, left + right + root -> data);
        int temp = max (left, right) + root -> data;
        if (root -> left && root -> right)
        {
            maxSum = max (maxSum, left + right + root -> data);
            return temp;
        }
        if (root -> left == NULL)
            return right + root -> data;
        return left + root -> data;
    }

    int maxPathSum(Node* root)
    {
        int maxSum = INT_MIN;
        int temp = go (root, maxSum);
        if (maxSum == INT_MIN)
            return temp;
        return maxSum;
    }
};