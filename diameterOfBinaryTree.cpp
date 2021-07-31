class Solution {
  public:

    int getHeight (Node* root, int &height)
    {
        if (root == NULL)
            return 0;
        int left = getHeight (root -> left, height);
        int right = getHeight (root -> right, height);
        height = max (height, left + right + 1);
        int temp = max (left, right) + 1;
        return temp;
    }
    
    int diameter(Node* root) {
        int height = 0;
        int temp = getHeight (root, height);
        return height;
    }
};