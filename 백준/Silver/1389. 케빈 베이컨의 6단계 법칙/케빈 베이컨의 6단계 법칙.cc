#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[101];

int bfs(int start, int end, bool* vis)
{
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	vis[start] = true;
	while (!q.empty())
	{
		int dest = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (dest == end)
			return cnt;

		for (int i = 0; i < v[dest].size(); i++)
		{
			if (!vis[v[dest][i]])
			{
				q.push(make_pair(v[dest][i], cnt + 1));
				vis[v[dest][i]] = true;
			}
		}
	}
}

int main() {
	int n, m, ans, num = 999999;
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
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			bool vis[101] = { 0 };
			if (i == j)
				continue;
			temp += bfs(i, j, vis);
		}
		if (num > temp)
		{
			num = temp;
			ans = i;
		}
	}
	cout << ans;
}