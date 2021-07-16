#include <iostream>
#include <vector>
using namespace std;

void maxMinArray (vector <int> arr)
{
    int minE = INT_MAX;
    int maxE = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < minE)
            minE = arr[i];
        if (arr[i] > maxE)
            maxE = arr[i];
    }
    cout << "MAX = " << maxE << "\n";
    cout << "MIN = " << minE;
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
    maxMinArray (arr);
    return 0;
}
