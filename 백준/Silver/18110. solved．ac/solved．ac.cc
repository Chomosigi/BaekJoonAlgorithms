#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ians = 0;
	int arr[300001];
	int trim;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	double ans = 0;
	double rate;
	rate = n * 0.15;
	trim = rate;
	if (rate - trim >= 0.5)
		trim += 1;
	for (int i = trim; i < n - trim; i++)
		ans += (double)arr[i];
	ans = ans / (n - 2 * trim);
	ians = ans;
	if (ans - ians >= 0.5)
		ians += 1;
	cout << ians << endl;
}