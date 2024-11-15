#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
queue<pair<int, int>> q;
bool vis[101];

int A, B, N, ans = -1;

void bfs(int num)
{
	int cnt = 0;
	q.push(make_pair(num, 0));

	while (!q.empty())
	{
		vis[num] = true;
		num = q.front().first;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < graph[num].size(); i++)
		{
			if (num == B)
				ans = cnt;
			else if(!vis[graph[num][i]])
				q.push(make_pair(graph[num][i], cnt + 1));
		}
	}
}

int main()
{
	cin >> N;
	cin >> A >> B;
	int time;
	cin >> time;
	int a, b;
	for (int i = 0; i < time; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(A);

	cout << ans;
}