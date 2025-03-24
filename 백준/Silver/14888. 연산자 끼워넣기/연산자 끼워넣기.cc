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

int* dfs(int* arr, int* cal, int cur, int* op, int cnt, int n)
{
	if (cnt == n)
	{
		cal[0] = max(cal[0], cur);
		cal[1] = min(cal[1], cur);
		return cal;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (op[i] != 0)
			{
				op[i]--;
				if (i == 0)
					cal = dfs(arr, cal, cur + arr[cnt], op, cnt + 1, n);
				else if (i == 1)
					cal = dfs(arr, cal, cur - arr[cnt], op, cnt + 1, n);
				else if (i == 2)
					cal = dfs(arr, cal, cur * arr[cnt], op, cnt + 1, n);
				else if (i == 3)
					cal = dfs(arr, cal, cur / arr[cnt], op, cnt + 1, n);
				op[i]++;
			}
		}
		return cal;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int op[4];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	int* cal = new int[2];
	cal[0] = -2000000000;
	cal[1] = 2000000000;
	cal = dfs(arr, cal, arr[0], op, 1, n);
	cout << cal[0] << '\n';
	cout << cal[1];
}