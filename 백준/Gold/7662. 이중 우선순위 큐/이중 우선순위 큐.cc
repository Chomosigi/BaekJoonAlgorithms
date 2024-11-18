#include <iostream>
#include <queue>
#include <map>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq1;
priority_queue<int> pq2;

map<int, int> cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;


	for (int i = 0; i < T; i++)
	{

		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			char c;
			int num;
			cin >> c >> num;
			if (c == 'I')
			{
				pq1.push(num);
				pq2.push(num);
				cnt[num]++;
			}
			else
			{
				if (num == 1)
				{
					if (!pq2.empty())
					{
						cnt[pq2.top()]--;
						pq2.pop();
					}
				}
				else
				{
					if (!pq1.empty())
					{
						cnt[pq1.top()]--;
						pq1.pop();
					}
				}
				while (!pq1.empty() && cnt[pq1.top()] == 0) pq1.pop();
				while (!pq2.empty() && cnt[pq2.top()] == 0) pq2.pop();
			}
		}

		if (pq1.empty() || pq2.empty())
			cout << "EMPTY" << "\n";
		else
			cout << pq2.top() << " " << pq1.top() << "\n";
		cnt.clear();
	}

	return 0;
}
