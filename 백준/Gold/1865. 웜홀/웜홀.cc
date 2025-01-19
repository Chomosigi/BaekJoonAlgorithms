#include <iostream>
#include <vector>

using namespace std;

#define INF 999999

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		vector<pair<pair<int, int>, int>> v;
		int arr[501];
		int n, m, w;
		cin >> n >> m >> w;
		string ans = "NO";
		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			v.push_back(make_pair(make_pair(s, e), t));
			v.push_back(make_pair(make_pair(e, s), t));
		}
		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			v.push_back(make_pair(make_pair(s, e), -t));
		}
		for (int i = 1; i <= n; i++)
			arr[i] = INF;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				int start = v[j].first.first;
				int dest = v[j].first.second;
				int dist = v[j].second;

				if (arr[dest] > arr[start] + dist)
					arr[dest] = arr[start] + dist;
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			int start = v[i].first.first;
			int dest = v[i].first.second;
			int dist = v[i].second;

			if (arr[dest] > arr[start] + dist)
			{
				ans = "YES";
				break;
			}
		}
		cout << ans << "\n";
		v.clear();
	}

	return 0;
}