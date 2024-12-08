#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, w;

	cin >> n >> w;
	
	for (int i = 0; i < n; i++)
	{
		int num, cost;
		cin >> num >> cost;
		v.push_back(make_pair(num, cost));
	}

	int dp[101][100001] = { 0, };

	for (int i = 1; i <= n; i++)
	{
		int cur_w = v[i - 1].first;
		int cur_cost = v[i - 1].second;
		for (int j = 1; j <= w; j++)
		{
			if (cur_w <= j)
				dp[i][j] = max(dp[i - 1][j - cur_w] + cur_cost, dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][w];

	return 0;
}