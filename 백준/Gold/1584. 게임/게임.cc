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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[501][501] = { 0, };
	bool danger[501][501] = { false };
	bool vis[501][501] = { false };
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = min(y1, y2); j <= max(y1, y2); j++)
		{
			for (int k = min(x1, x2); k <= max(x1, x2); k++)
				danger[j][k] = true;
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = min(y1, y2); j <= max(y1, y2); j++)
		{
			for (int k = min(x1, x2); k <= max(x1, x2); k++)
				vis[j][k] = true;
		}
	}
	
	priority_queue<pair<int, pair<int, int>>> pq;

	pq.push(make_pair(0, make_pair(0, 0)));

	bool flag = false;

	int mx[4] = { -1, 1, 0, 0 };
	int my[4] = { 0, 0, -1, 1 };

	while (!pq.empty())
	{
		int damage = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (x == 500 && y == 500)
		{
			cout << damage;
			flag = true;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + mx[i];
			int ny = y + my[i];
			int ndamage = damage;
			if (nx > 500 || ny > 500 || nx < 0 || ny < 0 || vis[ny][nx])
				continue;
			vis[ny][nx] = true;
			if (danger[ny][nx])
				ndamage++;
			pq.push(make_pair(-ndamage, make_pair(nx, ny)));
		}
	}

	if (flag == false)
		cout << -1;
}