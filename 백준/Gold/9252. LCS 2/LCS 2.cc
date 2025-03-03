#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>

#define INF 9999999

using namespace std;


int main() {
	int dp[1001][1001] = { 0 };
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int n = s1.size();
	int m = s2.size();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	string ans = "";
	while (n > 0 && m > 0)
	{
		if (dp[n][m] == dp[n - 1][m])
			n--;
		else if (dp[n][m] == dp[n][m - 1])
			m--;
		else
		{
			ans.push_back(s1[n - 1]);
			n--;
			m--;
		}
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
}