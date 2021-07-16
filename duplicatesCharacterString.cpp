#include <iostream>
#include <map>
using namespace std;

void duplicates (string str)
{
    int n = str.size();
    map <char, int> freq;
    for (int i = 0; i < n; i++)
        freq[str[i]]++;
    for (auto i : freq)
        if (i.second > 1)
            cout << i.first << " -> " << i.second << "\n";
}

int main()
{
    string str;
    cin >> str;
    duplicates (str);
    return 0;
}
