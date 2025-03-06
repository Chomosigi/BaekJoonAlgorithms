#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <stdlib.h>

#define INF 9999999

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = INF;
	cin >> n;
	int** arr;
	int** dp;
	arr = (int**)malloc(sizeof(int*) * (n + 1));
	dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 1; i <= n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * 3);
		dp[i] = (int*)malloc(sizeof(int) * 3);
	}
	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				dp[1][j] = arr[1][j];
			else
				dp[1][j] = INF;
		}
		for (int j = 2; j <= n; j++)
		{
			dp[j][0] = arr[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = arr[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = arr[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				continue;
			else
				ans = min(ans, dp[n][j]);
		}
	}
	cout << ans;
	for (int i = 1; i <= n; i++)
	{
		free(arr[i]);
		free(dp[i]);
	}
	free(dp);
	free(arr);
}
