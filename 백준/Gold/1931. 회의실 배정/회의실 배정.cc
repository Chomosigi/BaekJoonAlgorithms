#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		pq.push(make_pair(end, start));
	}
	int endTime = 0;
	int courseCnt = 0;
	while (!pq.empty())
	{
		int curEnd = pq.top().first;
		int curStart = pq.top().second;
		pq.pop();
		if (curStart >= endTime)
		{
			courseCnt++;
			endTime = curEnd;
		}
	}
	cout << courseCnt;
}