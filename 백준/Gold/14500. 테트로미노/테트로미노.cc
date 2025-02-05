#include <iostream>
#include <algorithm>

using namespace std;

int n, m, ans = -1;
int arr[500][500] = { 0 };
bool vis[500][500] = { false };
int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int cnt, int sum)
{
	if (cnt == 4)
	{
		ans = max(ans, sum);
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[ny][nx])
				continue;
			vis[ny][nx] = true;
			dfs(nx, ny, cnt + 1, sum + arr[ny][nx]);
			vis[ny][nx] = false;
		}
	}
}

void dfs_t(int cx, int cy)
{
	int sum = arr[cy][cx];
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = cx + mx[i];
		int ny = cy + my[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		sum += arr[ny][nx];
		cnt++;
	}
	if (cnt == 3)
		ans = max(sum, ans);
	if (cnt == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + mx[i];
			int ny = cy + my[i];
			int cur = sum - arr[ny][nx];
			ans = max(ans, cur);
		}
	}
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			vis[i][j] = true;
			dfs(j, i, 1, arr[i][j]);
			vis[i][j] = false;
			dfs_t(j, i);
		}
	}
	cout << ans;
}