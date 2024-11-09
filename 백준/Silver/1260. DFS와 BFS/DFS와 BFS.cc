#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool node[1001][1001];
bool vis1[1001];
bool vis2[1001];

queue<int> q;

void dfs(int V, int N)
{
	cout << V << ' ';
	vis1[V] = true;

	for (int i = 1; i <= N; i++)
	{
		if (node[V][i] == true && !vis1[i])
			dfs(i, N);
	}
}

void bfs(int V, int N) 
{
	q.push(V);
	cout << V << ' ';
	vis2[V] = true;
	while (!q.empty())
	{
		V = q.front();
		q.pop();


		for (int i = 1; i <= N; i++)
		{
			if (node[V][i] && !vis2[i])
			{
				q.push(i);
				cout << i << ' ';
				vis2[i] = true;
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;

	int start, end;
	for (int i = 1; i <= M; i++)
	{
		cin >> start >> end;
		node[start][end] = 1;
		node[end][start] = true;
	}
	dfs(V, N);

	cout << '\n';

	bfs(V, N);
	return 0;
}