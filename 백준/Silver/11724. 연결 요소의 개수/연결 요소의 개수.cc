#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
bool vis[1001] = { false };

void dfs(int n)
{
	for (auto iter = v[n].begin(); iter != v[n].end(); ++iter)
	{
		int cur = *iter;
		if (!vis[cur])
		{
			vis[cur] = true;
			dfs(cur);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans = 0;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			dfs(i);
			ans++;
		}
	}
	cout << ans;
}