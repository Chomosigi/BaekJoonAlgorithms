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

int dfs(int** arr, bool* vis, int n, int x, int pos)
{
	if (x == n / 2)
	{
		int start, link;
		start = 0;
		link = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (vis[i] && vis[j])
					start += arr[i][j];
				if (!vis[i] && !vis[j])
					link += arr[i][j];
			}
		}
		return abs(start - link);
	}
	int ans = 1000000000;
	for (int i = pos; i < n; i++)
	{
		vis[i] = true;
		ans = min(dfs(arr, vis, n, x + 1, i + 1), ans);
		vis[i] = false;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	bool *vis = new bool[n];
	for (int i = 0; i < n; i++)
		vis[i] = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	cout << dfs(arr, vis, n, 0, 0);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
	delete[] vis;

	return 0;
}