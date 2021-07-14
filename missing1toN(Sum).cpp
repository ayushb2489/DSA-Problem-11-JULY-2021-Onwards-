#include <iostream>
#include <set>
using namespace std;

int missingNumber (int* arr, int n)
{
    int sumActual = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return abs(sumActual - sum);
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
