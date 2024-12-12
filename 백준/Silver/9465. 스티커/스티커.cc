#include <iostream>
#include <algorithm>

int arr[2][100000];
int dp[2][100000];

using namespace std;

int n;

int main()
{

	int time;
	cin >> time;
	for (int i = 0; i < time; i++)
	{
		cin >> n;

		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < n; k++)
				cin >> arr[j][k];
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];

		for (int j = 2; j < n; j++)
		{
			dp[0][j] = arr[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
			dp[1][j] = arr[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
	}
}