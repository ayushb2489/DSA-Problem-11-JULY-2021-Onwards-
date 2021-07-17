#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subsequence (string str, int index, string maintainedString, vector <string> &stringVector)
{
    if (index == str.size())
    {
        if (maintainedString.size() > 0)
            stringVector.push_back (maintainedString);
        return ;
    }
    subsequence (str, index + 1, maintainedString + str[index], stringVector);
    subsequence (str, index + 1, maintainedString, stringVector);
}

int main()
{
    string str;
    cin >> str;
    vector <string> stringVector;
    subsequence (str, 0, "", stringVector);
    sort (stringVector.begin(), stringVector.end());
    for (auto i : stringVector)
        cout << i << "\n";
    return 0;
}
