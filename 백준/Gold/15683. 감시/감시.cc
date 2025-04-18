#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <map>

#define INF 9999999
#define MAX -9999999999

using namespace std;

int n, m;

int mx[4] = {0, -1, 0, 1};
int my[4] = {1, 0, -1, 0};

vector<pair<int, int>> cctv;

int ans = INF;

int** check(int** arr, int x, int y, int dir)
{
	dir %= 4;
	while (true)
	{
		x += mx[dir];
		y += my[dir];
		if (x < 0 || y < 0 || x >= n || y >= m)
			break;
		if (arr[x][y] == 6)
			break;
		if (arr[x][y] != 0)
			continue;
		arr[x][y] = -1;
	}
	return arr;
}

void dfs(int** arr, int idx)
{
	if (idx == cctv.size())
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (arr[i][j] == 0)
					cnt++;
		}
		ans = min(cnt, ans);
		return;
	}

	int x = cctv[idx].first;
	int y = cctv[idx].second;

	int** tmp = new int* [n];
	for (int i = 0; i < n; i++)
		tmp[i] = new int [m];
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp[i][j] = arr[i][j];

		if (arr[x][y] == 1)
			tmp = check(tmp, x, y, k);
		else if (arr[x][y] == 2)
		{
			tmp = check(tmp, x, y, k);
			tmp = check(tmp, x, y, k + 2);
		}
		else if (arr[x][y] == 3)
		{
			tmp = check(tmp, x, y, k);
			tmp = check(tmp, x, y, k + 1);
		}
		else if (arr[x][y] == 4)
		{
			tmp = check(tmp, x, y, k);
			tmp = check(tmp, x, y, k + 1);
			tmp = check(tmp, x, y, k + 2);
		}
		else if (arr[x][y] == 5)
		{
			tmp = check(tmp, x, y, k);
			tmp = check(tmp, x, y, k + 1);
			tmp = check(tmp, x, y, k + 2);
			tmp = check(tmp, x, y, k + 3);
		}

		dfs(tmp, idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int [m];


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6)
				cctv.push_back(make_pair(i, j));
		}
	}

	dfs(arr, 0);
	cout << ans;

	return 0;
}