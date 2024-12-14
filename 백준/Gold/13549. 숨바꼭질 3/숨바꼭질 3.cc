#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	bool vis[200002] = { false };

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, n));
	vis[n] = true;
	while (!q.empty())
	{
		int cnt = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (cur == k)
		{
			cout << cnt;
			break;
		}

		if (cur * 2 <= 2 * k && !vis[cur * 2])
		{
			q.push(make_pair(cnt, cur * 2));
			vis[cur * 2] = true;
		}
		if (cur + 1 <= k && !vis[cur + 1])
		{
			q.push(make_pair(cnt + 1, cur + 1));
			vis[cur + 1] = true;
		}
		if (cur - 1 >= 0 && !vis[cur - 1])
		{
			q.push(make_pair(cnt + 1, cur - 1));
			vis[cur - 1] = true;
		}
	}
}