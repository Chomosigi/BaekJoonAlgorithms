#include <iostream>
#include <queue>
#include <map>


using namespace std;


priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
map<int, int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int prev = -1;
	int cnt = -1;

	for (int i = 0; i < T; i++)
	{
		int num;
		
		cin >> num;
		pq.push(make_pair(num, i));
	}

	while (!pq.empty())
	{
		if (prev != pq.top().first || cnt == -1)
		{
			prev = pq.top().first;
			cnt++;
		}
		arr[pq.top().second] = cnt;
		pq.pop();
	}

	for (int i = 0; i < T; i++)
		cout << arr[i] << " ";

	return 0;
}
