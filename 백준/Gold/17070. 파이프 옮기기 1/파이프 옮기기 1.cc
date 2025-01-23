#include <iostream>
#include <queue>

#define INF 2000000

using namespace std;

int n, arr[16][16], ans = 0;
int mx[3] = { 1, 0, 1 };
int my[3] = { 0, 1, 1 };

struct point {
	int x;
	int y;
};

void bt(point p1, point p2, int type)
{
	int flag = false;
	if (p2.x == n - 1 && p2.y == n - 1)
		ans++;
	for (int i = 0; i < 3; i++)
	{
		point np1, np2;
		np1.x = p2.x;
		np1.y = p2.y;
		np2.x = p2.x + mx[i];
		np2.y = p2.y + my[i];
		if (arr[np2.y][np2.x] == 1)
		{
			flag = true;
			continue;
		}
		if (type == 0 && i == 1)
			continue;
		if (type == 1 && i == 0)
			continue;
		if (np2.x > n - 1 || np2.y > n - 1)
			continue;
		if (flag == true && i == 2)
			continue;
		bt(np1, np2, i);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	bt({ 0,0 }, { 1,0 }, 0);
	cout << ans;
}