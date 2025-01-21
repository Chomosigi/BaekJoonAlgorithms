#include <iostream>
#include <algorithm>
#include <queue>

#define INF 2000000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int arr[1000][1000] = { 0 };
	int vis[1000][1000][2] = { 0 };
	int move_x[4] = { 0, 0, -1, 1 };
	int move_y[4] = { -1, 1, 0, 0 };

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j] - '0';
	}

	queue<pair<int, pair<int, int>>> q;

	if(arr[0][0] == 0)
		q.push(make_pair(0, make_pair(0, 0)));
	else
		q.push(make_pair(1, make_pair(0, 0)));
	vis[0][0][0] = 1;

	while (!q.empty())
	{
		int broken = q.front().first;
		int cur_x = q.front().second.first;
		int cur_y = q.front().second.second;
		q.pop();

		if (cur_x == m - 1 && cur_y == n - 1)
		{
			cout << vis[cur_y][cur_x][broken];
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + move_x[i];
			int next_y = cur_y + move_y[i];
			if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n)
			{
				if (arr[next_y][next_x] == 0 && vis[next_y][next_x][broken] == 0)
				{
					vis[next_y][next_x][broken] = vis[cur_y][cur_x][broken] + 1;
					q.push(make_pair(broken, make_pair(next_x, next_y)));
				}

				if (arr[next_y][next_x] == 1 && broken == 0)
				{
					vis[next_y][next_x][1] = vis[cur_y][cur_x][0] + 1;
					q.push(make_pair(1, make_pair(next_x, next_y)));
				}
			}
		}
	}

	cout << -1;
	return 0;
}