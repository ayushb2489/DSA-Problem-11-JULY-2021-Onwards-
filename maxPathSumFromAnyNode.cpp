class Solution {
  public:
    
    int go (Node* root, int &maxSum)
    {
        if (root == NULL)
            return 0;
        int left = go (root -> left, maxSum);
        int right = go (root -> right, maxSum);
        //maxSum = max (maxSum, left + right + root -> data);
        int temp = max (max (left, right) + root -> data, root -> data);
        int temp1 = max (temp, left + right + root -> data);
        maxSum = max (maxSum, temp1);
        return temp;
    }
    
    int findMaxSum(Node* root)
    {
        int maxSum = INT_MIN;
        int temp = go (root, maxSum);
        return maxSum;
    }
};