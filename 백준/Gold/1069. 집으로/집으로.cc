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
	cout << fixed;
	cout.precision(9);

	int x, y, D, T;
	double ans = 0.0;
	double ans1, ans2, ans3;
	double m;
	cin >> x >> y >> D >> T;

	double dist;
	dist = sqrt(pow(x, 2) + pow(y, 2));
	if (D < T)
	{
		cout << dist;
		return 0;
	}
	while(dist > 2 * (double)D)
	{
		dist -= (double)D;
		ans += T;
	}
	ans1 = ans + 2 * T;
	while (dist >= (double)D)
	{
		dist -= (double)D;
		ans += T;
	}
	ans2 = ans + dist;
	ans3 = ans + T + (D - dist);
	m = ans1;
	m = min(m, ans2);
	m = min(m, ans3);
	cout << m;
	return 0;
}