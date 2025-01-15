#include <iostream>
#include <queue>

using namespace std;

int move_x[4] = { -1, 1, 0, 0 };
int move_y[4] = { 0, 0, -1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int arr[101][101];
	bool vis[101][101] = { false, };
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	vis[0][0] = true;
	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (cur_x == m - 1 && cur_y == n - 1)
		{
			cout << dist + 1;
			return 0;
		}
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + move_x[i];
			int next_y = cur_y + move_y[i];
			if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
				continue;
			if (arr[next_y][next_x] == 1 && !vis[next_y][next_x])
			{
				q.push(make_pair(make_pair(next_x, next_y), dist + 1));
				vis[next_y][next_x] = true;
			}
		}
	}
}