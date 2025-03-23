#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <map>

#define INF 9999999
#define MAX -9999999999

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;
		v.push_back(make_pair(t, p));
	}
	int* dp = new int[n];
	for (int i = 0; i < n; i++)
		dp[i] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int day = v[i].first;
		int cost = v[i].second;
		int temp_max = 0;
		if (i + day > n)
			continue;
		for (int j = i + day; j < n; j++)
			temp_max = max(temp_max, dp[j]);
		dp[i] = cost + temp_max;
	}
	int dp_max = 0;
	for (int i = 0; i < n; i++)
		dp_max = max(dp_max, dp[i]);
	cout << dp_max;
}