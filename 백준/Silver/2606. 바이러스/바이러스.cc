#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
queue<int> q;
bool vis[101];

int N, cnt = 0;

void bfs()
{
	q.push(1);
	vis[1] = true;
	int cur;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (!vis[graph[cur][i]])
			{
				vis[graph[cur][i]] = true;
				q.push(graph[cur][i]);
				cnt++;
			}
		}
	}
}

int main()
{
	cin >> N;
	int time;
	cin >> time;
	int a, b;
	for (int i = 0; i < time; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();

	cout << cnt;
}