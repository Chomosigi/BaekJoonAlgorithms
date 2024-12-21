#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	deque<pair<int, int>> dq;

	int num;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		dq.push_back(make_pair(i + 1, num));
	}

	while (!dq.empty())
	{
		int cur = dq.front().second;
		cout << dq.front().first << " ";
		dq.pop_front();

		if (dq.empty())
			break;

		if (cur > 0)
		{
			for (int i = 0; i < cur - 1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < (-1) * cur; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

}