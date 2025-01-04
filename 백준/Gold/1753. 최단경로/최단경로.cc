#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 9999999

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	vector<pair<int, int>> graph[20001];
	int dis[20001];

	bool vis[20001];

	cin >> n >> m;

	fill_n(dis, n + 1, INF);

	int start;
	cin >> start;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
	dis[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (auto iter = graph[cur].begin(); iter < graph[cur].end(); ++iter)
		{
			int dest = iter->first;
			int val = iter->second;
			if (dis[dest] > cost + val)
			{
				dis[dest] = cost + val;
				pq.push(make_pair(dis[dest], dest));
			}
			
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] != INF)
			cout << dis[i] << "\n";
		else
			cout << "INF\n";
	}
}