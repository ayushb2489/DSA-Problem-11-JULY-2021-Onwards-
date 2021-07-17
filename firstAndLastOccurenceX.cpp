int binarySearch (int* arr, int n, int x)
{
    int lower = 0, higher = n - 1;
    while (lower <= higher)
    {
        int mid = higher - (higher - lower) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            higher = mid - 1;
        else
            lower = mid + 1;
    }
    return -1;
}

vector <int> find (int* arr, int n, int x)
{
    vector <int> tempVector;
    int temp;
    temp = binarySearch (arr, n, x);
    if (temp == -1)
    {
        tempVector.push_back (-1);
        tempVector.push_back (-1);
    }
    else
    {
        int right = temp;
        while (right + 1 < n && arr[right + 1] == x)
            right++;
        int left = temp;
        while (left - 1 >= 0 && arr[left - 1] == x)
            left--;
        tempVector.push_back (left);
        tempVector.push_back (right);
    }
    return tempVector;
}