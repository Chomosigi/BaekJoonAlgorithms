#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, ans = 100000000;

int dist[1001];

vector<pair<int, int>> v[1001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start)
{
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > dist[cur])
			continue;
		for (auto iter = v[cur].begin(); iter < v[cur].end(); ++iter)
		{
			int next = iter->first;
			int nCost = iter->second;

			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
		dist[i] = 2147483647;

	cin >> M;

	int start, end, val;

	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> val;
		v[start].push_back(make_pair(end, val));
	}

	cin >> start >> end;

	dijkstra(start);

	cout << dist[end];
}  