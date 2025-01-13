#include <iostream>

using namespace std;

long long arr[101] = { 0, 1, 1, };

long long p(int n)
{
	if (n < 3)
		return arr[n];
	else
	{
		if (arr[n] == 0)
			arr[n] = p(n - 2) + p(n - 3);
		return arr[n];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int n;
		cin >> n;
		cout << p(n) << '\n';
	}
}