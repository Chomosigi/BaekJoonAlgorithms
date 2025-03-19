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

struct point {
	int x, y;

	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

double gause(point p1, point p2, point p3)
{
	double area;
	area = (double)(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y);
	area -= (double)(p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
	return abs(area) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(1);

	int N;
	cin >> N;

	vector<point> v;

	double ans = 0;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		point p(x, y);
		v.push_back(p);
	}

	for (int i = 0; i < N - 2; i++)
	{
		point p1(v[i].x, v[i].y);
		for (int j = i + 1; j < N - 1; j++)
		{
			point p2(v[j].x, v[j].y);
			for (int k = j + 1; k < N; k++)
			{
				point p3(v[k].x, v[k].y);
				ans = max(ans, gause(p1, p2, p3));
			}
		}
	}
	cout << ans;
}