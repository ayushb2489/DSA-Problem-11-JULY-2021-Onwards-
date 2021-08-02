int stm (int* st, int* arr, int si, int left, int right)
{
    if (left == right)
    {
        st[si] = arr[left];
        return arr[left];
    }
    int mid = (left + right) / 2;
    st[si] = min (stm (st, arr, 2 * si + 1, left, mid), stm (st, arr, 2 * si + 2, mid + 1, right));
    return st[si];
}

int *constructST(int arr[],int n)
{
    int temp = (int)ceil (log2 (n + 1));
    int stl = 2 * (int)pow (2, temp ) - 1;
    
    int* st = new int[stl];
   /* for (int i = 0; i < n; i++)
        st[i] = INT_MAX;*/
    int temp1 = stm (st, arr, 0, 0, n - 1);
    return st;
}



 
 int getMin (int* st, int si, int left, int right, int leftQuery, int rightQuery)
 {
    if (leftQuery <= left && rightQuery >= right)
        return st[si];
    
    if (leftQuery > right || rightQuery < left)
        return INT_MAX;
    
    int mid = (left + right) / 2;
    return min (getMin(st, 2 * si + 1, left, mid, leftQuery, rightQuery), 
                getMin (st, 2 * si + 2, mid + 1, right, leftQuery, rightQuery));
 }
 
int RMQ(int st[] , int n, int a, int b)
{
    return getMin (st, 0, 0, n - 1, a, b);
}