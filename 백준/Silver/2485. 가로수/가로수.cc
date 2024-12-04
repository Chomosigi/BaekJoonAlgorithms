#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, first, end;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}
	
	int before = q.top();
	first = before;
	end = before;
	q.pop();
	int cur = q.top();
	q.pop();
	int interval = cur - before;
	while (!q.empty())
	{
		before = cur;
		cur = q.top();
		end = cur;
		q.pop();
		int cur_interval = cur - before;
		if (cur_interval != interval)
			interval = gcd(cur_interval, interval);
	}
	cout << (end - first) / interval + 1 - n;
}