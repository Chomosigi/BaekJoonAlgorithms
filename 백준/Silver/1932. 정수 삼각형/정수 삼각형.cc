#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
	int arr[500];
	int dp[500] = { 0, };
	int temp_dp[500] = { 0, };
	cin >> n;
	cin >> dp[0];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
			cin >> arr[j];
		temp_dp[0] = dp[0] + arr[0];
		for (int j = 1; j < i - 1; j++)
			temp_dp[j] = max(dp[j - 1], dp[j]) + arr[j];
		temp_dp[i - 1] = dp[i - 2] + arr[i - 1];
		for (int j = 0; j < i; j++)
			dp[j] = temp_dp[j];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans < dp[i])
			ans = dp[i];
	}
	cout << ans;
}