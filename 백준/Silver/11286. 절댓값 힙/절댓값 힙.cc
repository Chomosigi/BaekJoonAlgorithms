#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (!pq.empty()) {
				cout << pq.top().second << "\n";
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
			pq.push(make_pair(abs(num), num));
	}
		
}