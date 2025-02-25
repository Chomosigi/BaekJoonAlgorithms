#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int m, n, x, y, ans = -1;
		cin >> m >> n >> x >> y;
		int last = m * n / gcd(m, n);
		while (x <= last && y <= last && ans == -1)
		{
			if (x < y)
				x += m;
			else if (x > y)
				y += n;
			else if (x == y)
				ans = x;
		}
		cout << ans << "\n";
	}
}