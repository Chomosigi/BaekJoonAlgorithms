#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int val[100001]{ 0, };

	int n, m;
	cin >> n >> m;

	queue<int> q;

	val[n] = 1;

	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur + 1 <= 100000)
		{
			if (val[cur + 1] == 0 || val[cur + 1] > val[cur] + 1)
			{
				val[cur + 1] = val[cur] + 1;
				q.push(cur + 1);
			}
		}
		if (cur - 1 >= 0)
		{
			if (val[cur - 1] == 0 || val[cur - 1] > val[cur] + 1)
			{
				val[cur - 1] = val[cur] + 1;
				q.push(cur - 1);
			}
		}
		if (2 * cur <= 100000)
		{
			if (val[cur * 2] == 0 || val[cur * 2] > val[cur] + 1)
			{
				val[cur * 2] = val[cur] + 1;
				q.push(cur * 2);
			}
		}
	}
	cout << val[m] - 1;
}