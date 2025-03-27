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

int mr[4] = { -1, 0, 1, 0 };
int mc[4] = { 0, 1, 0, -1 };

struct Point
{
	int r;
	int c;
};

int searchRoom(int** arr, bool** vis, Point p, int m, int n, int d)
{
	for (int i = 0; i < 4; i++)
	{
		int nd = (d + 3 - i) % 4;
		int nr = p.r + mr[nd];
		int nc = p.c + mc[nd];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] == 1)
			continue;
		if (!vis[nr][nc])
			return nd;
	}
	return -1;
}

Point goBack(int** arr, Point p, int m, int n, int d)
{
	int nr = mr[(d + 2) % 4] + p.r;
	int nc = mc[(d + 2) % 4] + p.c;
	if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] == 1)
	{
		p.r = -1;
		p.c = -1;
	}
	else
	{
		p.r = nr;
		p.c = nc;
	}
	return p;
}

int moving(int** arr, bool** vis, Point p, int m, int n, int d)
{
	int ans = 0;
	bool flag = true;
	while (flag)
	{
		if (!vis[p.r][p.c])
		{
			vis[p.r][p.c] = true;
			ans++;
		}
		int nd = searchRoom(arr, vis, p, m, n, d);

		if (nd == -1)
		{
			p = goBack(arr, p, m, n, d);
			if (p.r == -1 && p.c == -1)
				flag = false;
		}
		else
		{
			p.r += mr[nd];
			p.c += mc[nd];
			d = nd;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	bool** vis = new bool* [n];
	for (int i = 0; i < n; i++)
		vis[i] = new bool[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			vis[i][j] = false;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	Point p({ r, c });

	cout << moving(arr, vis, p, m, n, d);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}