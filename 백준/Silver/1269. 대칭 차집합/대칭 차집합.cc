#include <iostream>
#include <queue>

using namespace std;

int N, M, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> a;
	priority_queue<int, vector<int>, greater<int>> b;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		a.push(num);
	}

	for (int j = 0; j < M; j++)
	{
		int num;
		cin >> num;
		b.push(num);
	}

	while (!a.empty() || !b.empty())
	{
		if (a.empty())
		{
			cnt++;
			b.pop();
			continue;
		}
		if (b.empty())
		{
			cnt++;
			a.pop();
			continue;
		}
		if (a.top() < b.top())
		{
			cnt++;
			a.pop();
		}
		else if (a.top() > b.top())
		{
			cnt++;
			b.pop();
		}
		else
		{
			a.pop();
			b.pop();
		}
	}
	cout << cnt;
}  