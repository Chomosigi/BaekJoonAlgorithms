#include <iostream>
#include <queue>
#include <string>

using namespace std;


priority_queue<pair<pair<int, int>, string>, vector<pair<pair<int, int>, string>>, greater<pair<pair<int, int>, string>>> pq;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int num;
		string s;
		cin >> num >> s;

		pq.push(make_pair(make_pair(num, i), s));
	}

	while (!pq.empty())
	{
		cout << pq.top().first.first << " " << pq.top().second << "\n";
		pq.pop();
	}

	return 0;
}
