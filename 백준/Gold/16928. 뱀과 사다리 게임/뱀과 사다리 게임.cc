#include <iostream>
#include <queue>
#include <map>

using namespace std;

map<int, int> path;

bool vis[100] = { false };

queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		path[start - 1] = end - 1;
	}
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		path[start - 1] = end - 1;
	}

	int ans = 0;

	q.push(make_pair(0, 0));
	vis[0] = true;

	while (ans == 0)
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int next_num = num + i;
			if (path[next_num])
			{
				vis[next_num] = true;
				next_num = path[next_num];
			}
			if (next_num == 99)
			{
				ans = cnt + 1;
				break;
			}
			else if (!vis[next_num] && next_num < 100)
			{
				q.push(make_pair(next_num, cnt + 1));
				vis[next_num] = true;
			}
		}
	}
	cout << ans;
}