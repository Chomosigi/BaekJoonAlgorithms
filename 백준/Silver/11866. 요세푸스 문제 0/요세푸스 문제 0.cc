#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);
	cout << '<';
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		int cur = q.front();
		cout << cur;
		q.pop();
		if (!q.empty())
			cout << ", ";
	}
	cout << ">";
}