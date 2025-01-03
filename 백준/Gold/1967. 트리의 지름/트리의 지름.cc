#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v[10001];

int n, ans = 0;


int dfs(int n)
{
	int len1 = 0, len2 = 0, biglen = 0;
	for (int i = 0; i < v[n].size(); i++)
	{
		int next = v[n][i].first;
		int val = v[n][i].second;
		int curlen = dfs(next) + val;
		if (curlen > biglen)
			biglen = curlen;
		if (curlen > len1)
		{
			len2 = len1;
			len1 = curlen;
		}
		else if (curlen > len2)
			len2 = curlen;
	}
	if (ans < len1 + len2)
		ans = len1 + len2;
	return biglen;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int start, end, val;
		cin >> start >> end >> val;
		v[start].push_back(make_pair(end, val));
	}
	dfs(1);
	cout << ans;
}