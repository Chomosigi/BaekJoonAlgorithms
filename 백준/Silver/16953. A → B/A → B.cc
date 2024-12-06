#include <iostream>
#include <queue>

using namespace std;

queue<pair<long long int, int>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, target;

	cin >> n >> target;

	if (n == target)
	{
		cout << 1;
		return 0;
	}

	q.push(make_pair(n, 1));

	while (!q.empty())
	{
		
		long long int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur * 2 < target)
			q.push(make_pair(cur * 2, cnt + 1));
		if (cur * 10 + 1 < target)
			q.push(make_pair(cur * 10 + 1, cnt + 1));
		if (cur * 2 == target || cur * 10 + 1 == target)
		{
			cout << cnt + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}