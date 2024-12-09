#include <iostream>

using namespace std;

long long int a, b, c, ans;

long long power(long long time)
{
    if (time == 0)
        return 1;
    if (time == 1)
        return a % c;
    ans = power(time / 2) % c;
    if (time % 2 == 0)
        return ans * ans % c;
    return ans * ans % c * a % c;

}

int main()
{
    cin >> a >> b >> c;

    cout << power(b);
}