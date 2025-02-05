#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b - c << "\n";
    if(b < 10)
        cout << 10 * a + b - c;
    else if(b < 100)
        cout << 100 * a + b - c;
    else if(b < 1000)
        cout << 1000 * a + b - c;
    else if(b == 1000)
        cout << 10000 * a + b - c;
}