#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long ans = 1;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		while (ans % 10 == 0)
			ans /= 10;
		ans = ans % 1000000000000;
	}

	ans = ans % 100000;

	printf("%05lld", ans);
}