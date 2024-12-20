#include <iostream>
#include <vector>

using namespace std;

int dp[100001] = { 0, };

vector<int> v[100001];

bool vis[100001];

void dfs(int node)
{
	vis[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		int nextNode = v[node][i];
		if (!vis[nextNode])
		{
			dfs(nextNode);
			dp[node] += dp[nextNode];
		}
	}
	dp[node]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, Q;
	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(R);

	for (int i = 0; i < Q; i++)
	{
		int q;
		cin >> q;
		cout << dp[q] << "\n";
	}
}