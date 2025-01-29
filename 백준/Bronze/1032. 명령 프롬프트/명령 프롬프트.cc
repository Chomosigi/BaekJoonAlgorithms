#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (s == "")
            s = temp;
        else
        {
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] != temp[j])
                    s[j] = '?';
            }
        }
    }
    cout << s;
}