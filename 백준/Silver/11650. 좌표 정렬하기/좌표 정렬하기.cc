#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < num; i++)
	{
		int x, y;
		cin >> x >> y;
		pq.push(make_pair(x, y));
	}

	while (!pq.empty())
	{
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();
		cout << x << " " << y << "\n";
	}

	return 0;
}