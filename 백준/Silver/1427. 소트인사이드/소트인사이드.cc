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

	priority_queue<int, vector<int>, less<int>> pq;

	while (num != 0)
	{
		pq.push(num % 10);
		num /= 10;
	}

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}

	return 0;
}