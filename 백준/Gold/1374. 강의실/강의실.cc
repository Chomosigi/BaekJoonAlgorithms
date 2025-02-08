#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main()
{
	int n, room = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(b, c));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		int start = v[i].first;
		int end = v[i].second;

		if (pq.empty())
		{
			pq.push(end);
			room++;
		}
		else
		{
			if (pq.top() > start)
				room++;
			else
				pq.pop();
			pq.push(end);
		}
	}
	cout << room;
}