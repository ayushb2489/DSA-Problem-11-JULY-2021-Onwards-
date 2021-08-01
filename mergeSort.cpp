void merge(int arr[], int l, int m, int r)
    {
         int temp[r - l + 1];
         int i = l, k = 0, j = m + 1;
         while (i <= m && j <= r)
         {
            if (arr[i] < arr[j])
                temp[k++] = arr[i++];
            else 
                temp[k++] = arr[j++];
         }
        while (i <= m)
            temp[k++] = arr[i++];
        while (j <= r)
            temp[k++] = arr[j++];
        k = 0;
        for (int i = l; i <= r; i++)
            arr[i] = temp[k++];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int mid = r - (r - l) / 2;
            mergeSort (arr, l, mid);
            mergeSort (arr, mid + 1, r);
            merge (arr, l, mid, r);
        }
    }