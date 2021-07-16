#include <iostream>
#include <vector>
using namespace std;

void displayVector (vector <int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << '\t';
}

void reverseArray (vector <int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < (n / 2); i++)
        swap (arr[i], arr[n - 1 - i]);
}

int main()
{
    int n;
    cin >> n;
    vector <int> arr;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back (temp);
    }
    reverseArray (arr);
    displayVector (arr);
    return 0;
}
