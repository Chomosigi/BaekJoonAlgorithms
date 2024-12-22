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

	deque<int> dq;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (s == "front")
		{
			if (!dq.empty())
				cout << dq.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (s == "back")
		{
			if (!dq.empty())
				cout << dq.back() << "\n";
			else
				cout << -1 << "\n";
		}
		else if (s == "pop")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (s == "size")
			cout << dq.size() << "\n";
		else if (s == "empty")
			cout << dq.empty() << "\n";
	}
}