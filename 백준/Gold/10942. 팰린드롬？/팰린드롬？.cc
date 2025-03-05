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
	int n;
	int* arr;
	cin >> n;
	arr = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	bool** dp;
	dp = (bool**)malloc(sizeof(bool*) * (n + 1));
	for (int i = 0; i <= n; i++)
		dp[i] = (bool*)malloc(sizeof(bool) * (n + 1));
	for (int i = 0; i <= n; i++)
		memset(dp[i], false, sizeof(bool) * (n + 1));
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = true;
		if (i != 1 && arr[i - 1] == arr[i])
			dp[i - 1][i] = true;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i + 2; j <= n; j++)
		{
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == true)
				dp[i][j] = true;
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
	free(arr);
	for (int i = 0; i <= n; i++)
		free(dp[i]);
	free(dp);
}
