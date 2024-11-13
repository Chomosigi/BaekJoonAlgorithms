#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>>graph[1001];
bool vis[1001];

int answer = 0;

void dfs(int num, int target, int sum)
{
	vis[num] = true;

	if (num == target)
	{
		answer = sum;
		return;
	}
	else
	{
		for (int i = 0; i < graph[num].size(); i++)
		{
			int len = sum + graph[num][i].second;
			int next = graph[num][i].first;

			if (vis[next])
				continue;
			dfs(next, target, len);
		}
	}
	vis[num] = false;
}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i < N; i++)
	{
		int x, y, len;
		cin >> x >> y >> len;
		graph[x].push_back(make_pair(y, len));
		graph[y].push_back(make_pair(x, len));
	}

	for (int i = 1; i <= M; i++)
	{
		int start, des;
		cin >> start >> des;
		dfs(start, des, 0);
		memset(vis, 0, sizeof(vis));
		cout << answer << "\n";
	}
}