class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    
    bool getPath (Node* root, int n, vector <Node*> &arr)
    {
        if (root == NULL)
            return false;
        if (root -> data == n)
        {
            arr.push_back (root);
            return true;
        }
        if (getPath (root -> left, n, arr))
        {
            arr.push_back (root);
            return true;
        }
        if (getPath (root -> right, n, arr))
        {
            arr.push_back (root);
            return true;
        }
        return false;
    }
    
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector <Node*> arr1;
       vector <Node*> arr2;
        bool temp1 = getPath (root, n1, arr1);
        bool temp2 = getPath (root, n2, arr2);
        int counter = 0;
        int retValue;
        bool got = true;
        reverse (arr1.begin(), arr1.end());
        reverse (arr2.begin(), arr2.end());
       /* for (auto i : arr1)
            cout << i -> data << "\t";
        cout << "\n";
        for (auto i : arr2)
            cout << i -> data << "\t";
        cout << "\n";*/
        while (counter < arr1.size() && counter < arr2.size())
        {
            if (arr1[counter] -> data != arr2[counter] -> data)
            {
                if (counter == 0)
                    return arr1[counter];
                else 
                    return arr1[counter  - 1];
            }   
            counter++;
        }
        return arr1[counter - 1];
    }
};