#include <iostream>
#include <algorithm>
using namespace std;

int missingNumber (int* arr, int n)
{
    sort (arr, arr + n);
    for (int i = 0; i < n; i++)
        if (arr[i] != i)
            return i;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << missingNumber (arr, n);
    return 0;
}
