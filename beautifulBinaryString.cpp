#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str.size() >= 3)
    {
        int counter = 0;
        string subS;
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            subS = str.substr (i, 3);
            if (subS == "010")
            {
                counter++;
                str[i + 2] = 'g 1';
                i = i + 2;
            }
        }
        cout << counter;
    }
    else
        cout << 0;
    return 0;
}
