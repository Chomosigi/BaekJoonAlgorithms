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

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < num; i++)
	{
		int N;
		cin >> N;
		pq.push(N);
	}

	while (!pq.empty())
	{
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}