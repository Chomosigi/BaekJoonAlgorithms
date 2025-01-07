#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1e9

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v1[1001];
	vector<pair<int, int>> v2[1001];

	bool vis[1001] = { false };

	int come[1001];
	int back[1001];

	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++)
	{
		come[i] = INF;
		back[i] = INF;
	}

	priority_queue <pair<int, int>> pq;

	for (int i = 0; i < m; i++)
	{
		int start, dest, time;
		cin >> start >> dest >> time;
		v1[start].push_back(make_pair(dest, time));
		v2[dest].push_back(make_pair(start, time));
	}

	pq.push(make_pair(0, x));

	while (!pq.empty())
	{
		int cur_val = -pq.top().first;
		int cur_node = pq.top().second;
		vis[cur_node] = true;
		come[cur_node] = min(come[cur_node], cur_val);
		pq.pop();
		for (auto iter = v2[cur_node].begin(); iter < v2[cur_node].end(); iter++)
		{
			int next_val = iter->second;
			int next_node = iter->first;
			if (!vis[next_node])
				pq.push(make_pair( (-1) * (cur_val + next_val), next_node));
		}
	}
	
	for (int i = 1; i <= n; i++)
		vis[i] = false;

	pq.push(make_pair(0, x));

	while (!pq.empty())
	{
		int cur_val = -pq.top().first;
		int cur_node = pq.top().second;
		vis[cur_node] = true;
		back[cur_node] = min(back[cur_node], cur_val);
		pq.pop();
		for (auto iter = v1[cur_node].begin(); iter < v1[cur_node].end(); iter++)
		{
			int next_val = iter->second;
			int next_node = iter->first;
			if (!vis[next_node])
				pq.push(make_pair((-1) * (cur_val + next_val), next_node));
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++)
		ans = max(ans, come[i] + back[i]);

	cout << ans;

}