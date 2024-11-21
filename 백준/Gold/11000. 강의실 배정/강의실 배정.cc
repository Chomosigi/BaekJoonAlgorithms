#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> room;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n, m;
		cin >> n >> m;

		pq.push(make_pair(n, m));
	}
	while (!pq.empty())
	{
		int start, end;
		start = pq.top().first;
		end = pq.top().second;
		pq.pop();
		if (room.empty())
			room.push(end);
		else if (room.top() > start)
			room.push(end);
		else
		{
			room.pop();
			room.push(end);
		}
	}
	cout << room.size();
}