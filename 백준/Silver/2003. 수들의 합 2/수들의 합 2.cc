#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		int j = i;
		while (sum < m && j < n)
		{
			sum += arr[j];
			j++;
		}
		if (sum == m)
			ans++;
	}
	delete []arr;

	cout << ans;

	return 0;
}