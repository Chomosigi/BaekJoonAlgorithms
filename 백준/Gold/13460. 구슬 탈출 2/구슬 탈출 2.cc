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

int mx[4] = { -1, 0, 1, 0 };
int my[4] = { 0, 1, 0, -1 };

struct Point
{
	int bx, by;
	int rx, ry;
	int cnt;
};

int rolling(char** arr, int& x, int& y, int d)
{
	int dist = 0;
	while (arr[x + mx[d]][y + my[d]] != '#' && arr[x][y] != 'O')
	{
		x += mx[d];
		y += my[d];
		dist++;
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	Point p;

	bool vis[10][10][10][10] = { false };

	char** maze = new char* [n];
	for (int i = 0; i < n; i++)
		maze[i] = new char[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'R')
			{
				p.rx = i;
				p.ry = j;
				maze[i][j] = '.';
			}
			if (maze[i][j] == 'B')
			{
				p.bx = i;
				p.by = j;
				maze[i][j] = '.';
			}
		}
	}
	p.cnt = 0;
	
	queue<Point> q;

	q.push(p);
	while (!q.empty())
	{
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;
			int rd = 0, bd = 0;

			rd = rolling(maze, nrx, nry, i);
			bd = rolling(maze, nbx, nby, i);

			if (maze[nbx][nby] == 'O')
				continue;
			if (maze[nrx][nry] == 'O')
			{
				cout << cnt + 1;
				return 0;
			}
			if (nrx == nbx && nry == nby)
			{
				if (rd > bd)
				{
					nrx -= mx[i];
					nry -= my[i];
				}
				else
				{
					nbx -= mx[i];
					nby -= my[i];
				}
			}
			if (vis[nrx][nry][nbx][nby])
				continue;
			vis[nrx][nry][nbx][nby] = true;
			Point np;
			np.bx = nbx;
			np.by = nby;
			np.rx = nrx;
			np.ry = nry;
			np.cnt = cnt + 1;
			q.push(np);
		}
	}
	cout << -1;

	for (int i = 0; i < n; i++)
		delete[] maze[i];
	delete[] maze;
	return 0;
}