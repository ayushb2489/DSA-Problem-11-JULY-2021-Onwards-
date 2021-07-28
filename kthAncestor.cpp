bool solve (Node* root, int key, vector <int> &arr)
{
    if (root == NULL)
        return false;
    if (root -> data == key)
    {
        arr.push_back (root -> data);
        return true;
    }
    if (solve (root -> left, key, arr))
    {
        arr.push_back (root -> data);
        return true;
    }
    if (solve (root -> right, key, arr))
    {
        arr.push_back (root -> data);
        return true;
    }
    else
        return false;
}

int kthAncestor(Node *root, int k, int node)
{
    vector <int> arr;
    if (solve (root, node, arr))
    {
        int n = arr.size();
        if (n - 1 < k)
            return -1;
        return  arr[k];
    }
}