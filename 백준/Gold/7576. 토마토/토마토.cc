#include <iostream>
#include <queue>

using namespace std;

queue<pair<pair<int, int>, int>> q;

int m, n;

int arr[1000][1000];

int next_x[4] = { -1, 1, 0, 0 };
int next_y[4] = { 0, 0, -1, 1 };

void bfs()
{
	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + next_x[i];
			int ny = cur_y + next_y[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (arr[ny][nx] == 0)
				{
					arr[ny][nx] = cnt + 1;
					q.push(make_pair(make_pair(nx, ny), cnt + 1));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push(make_pair(make_pair(j, i), 1));
		}
	}

	bfs();

	bool check = true;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
				check = false;
			if (ans < arr[i][j])
				ans = arr[i][j];
		}
	}
	if (!check)
		cout << -1;
	else
		cout << ans - 1;
}