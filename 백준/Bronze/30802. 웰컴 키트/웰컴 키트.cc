#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[6];
	for (int i = 0; i < 6; i++)
		cin >> arr[i];

	int t, p;
	int ans = 0;
	cin >> t >> p;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] % t != 0)
			ans += arr[i] / t + 1;
		else
			ans += arr[i] / t;
	}
	cout << ans << '\n';
	cout << n / p << " " << n % p;
}