#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int arr[100001];

bool vis[100001];

void dfs(int n)
{
	vis[n] = true;
	for (int i = 0; i < v[n].size(); i++)
	{
		int next = v[n][i];
		if (!vis[next])
		{
			arr[next] = n;
			dfs(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << arr[i] << "\n";
}