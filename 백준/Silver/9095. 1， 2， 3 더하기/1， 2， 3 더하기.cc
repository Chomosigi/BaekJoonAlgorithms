#include <iostream>

using namespace std;

int N, dp[300];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	for (int i = 3; i < 11; i++)
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		cout << dp[num - 1] << "\n";
	}
}