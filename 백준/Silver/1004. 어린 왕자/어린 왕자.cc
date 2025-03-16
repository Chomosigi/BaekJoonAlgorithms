#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <map>

#define INF 9999999

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int x1, y1, x2, y2, ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		int p;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			int cx, cy, cr;
			cin >> cx >> cy >> cr;
			bool dest, start;
			if ((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) <= cr * cr)
				start = true;
			else
				start = false;
			if ((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) <= cr * cr)
				dest = true;
			else
				dest = false;
			if (dest != start)
				ans++;
		}
		cout << ans << '\n';
	}
}