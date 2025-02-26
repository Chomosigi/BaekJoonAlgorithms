#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int p[100001] = { 0 };

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int find_root(int a)
{
	if (p[a] == a)
		return a;
	else
		return p[a] = find_root(p[a]);
}

void union_root(int a, int b) {
	a = find_root(a);
	b = find_root(b);

	if (a != b)
		p[b] = a;
}

int main() {
	int N, M, ans = 0, max_path = 0;
	cin >> N >> M;
	for (int i = 1; i < N; i++)
		p[i] = i;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({c, { a, b }});
	}

	while (!pq.empty())
	{
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (find_root(a) == find_root(b))
			continue;
		ans += cost;
		max_path = max(max_path, cost);
		union_root(a, b);
	}
	cout << ans - max_path;
}