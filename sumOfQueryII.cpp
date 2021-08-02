
class Solution{
public:

    int stm (int* st, int* arr, int si, int left, int right)
    {
        if (left == right)
        {
            st[si] = arr[left];
            return arr[left];
        }
        
        int mid = (left + right) / 2;
        
        st[si] = stm (st, arr, 2 * si + 1, left, mid) + stm (st, arr, 2 * si + 2, mid + 1, right);
        return st[si];
    }

    int sumQuery (int* st, int si, int left, int right, int leftQuery, int rightQuery)
    {
        if (leftQuery <= left && rightQuery >= right)
            return st[si];
            
        if (leftQuery > right || rightQuery < left)
            return 0;
        
        int mid = (left + right) / 2;
        
        return sumQuery (st, 2 * si + 1, left, mid, leftQuery, rightQuery) + sumQuery (st, 2 * si + 2, mid + 1, right, leftQuery, rightQuery);
    }

    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        int temp = (int)ceil (log2 (n));
        int stl = (int)pow (2, temp + 1) - 1;
        
        int st[stl] = {0};
        
        int temp1 = stm (st, arr, 0, 0, n - 1);
        
        int left;
        int right;
        vector <int> retVector;
        int tempPush;
        for (int i  = 0; i < 2 * q; i = i + 2)
        {
            left = queries[i];
            right = queries[i + 1];
            
            tempPush = sumQuery (st, 0, 0, n - 1, left - 1, right - 1);
            
            retVector.push_back (tempPush);
        }
        return retVector;
    }
};