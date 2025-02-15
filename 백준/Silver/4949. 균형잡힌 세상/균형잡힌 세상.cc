#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    while (true)
    {
        string str;
        getline(cin, str);
        stack<char> s;
        bool ans = true;
        
        if (str.length() == 1 && str[0] == '.')
            break;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '[' || str[i] == '(')
                s.push(str[i]);
            if (str[i] == ']')
            {
                if (!s.empty() && s.top() == '[')
                    s.pop();
                else
                {
                    ans = false;
                    break;
                }
            }
            if (str[i] == ')')
            {
                if (!s.empty() && s.top() == '(')
                    s.pop();
                else
                {
                    ans = false;
                    break;
                }
            }
        }

        if (s.empty() && ans)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}