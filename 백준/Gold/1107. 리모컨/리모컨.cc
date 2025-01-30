#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool broken[10] = { false };

bool pos(int n)
{
    if (n == 0)
        return !(broken[n]);
    while (n != 0)
    {
        if (broken[n % 10] == true)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    int ans;
    int n;
    cin >> n;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        broken[num] = true;
    }
    ans = abs(n - 100);
    int start = n - ans;
    int end = n + ans;
    if (start < 0)
        start = 0;
    
    for (int i = start; i <= end; i++)
    {
        if (pos(i))
            ans = min(ans, (int)(abs(n - i) + to_string(i).length()));
    }
    cout << ans;
}