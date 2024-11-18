#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		int x, y;
		cin >> x >> y;
		pq.push(make_pair(y, x));
	}
	while (!pq.empty())
	{
		cout << pq.top().second << " " << pq.top().first << "\n";
		pq.pop();
	}

	return 0;
}