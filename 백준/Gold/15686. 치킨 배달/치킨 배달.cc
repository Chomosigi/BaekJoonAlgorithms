#include <iostream>
#include <algorithm>
#include <queue>

#define INF 2000000

using namespace std;

int n, m, ans = INF;

struct point {
	int x;
	int y;
};

vector<point> chicken;
vector<point> home;
vector<point> sChicken;

int distance(point a, point b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void bt(int idx, int cnt)
{
	if (m == cnt)
	{
		int cur_ans = 0;
		for (int i = 0; i < home.size(); i++)
		{
			int cur_dis = INF;
			for (int j = 0; j < sChicken.size(); j++)
				cur_dis = min(cur_dis, distance(home[i], sChicken[j]));
			cur_ans += cur_dis;
		}
		ans = min(cur_ans, ans);
	}
	for (int i = idx; i < chicken.size(); i++)
	{
		int ch_x = chicken[i].x;
		int ch_y = chicken[i].y;
		sChicken.push_back({ ch_x, ch_y });
		bt(i + 1, cnt + 1);
		sChicken.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int arr[50][50];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				home.push_back({ i, j });
			if (arr[i][j] == 2)
				chicken.push_back({ i, j });
		}
	}
	bt(0, 0);
	cout << ans;
}