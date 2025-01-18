#include <iostream>

using namespace std;

int n, m;

bool used[52] = { false };

char arr[20][20];

int ans = 0, cur = 1;

void dfs(int x, int y)
{
	ans = max(ans, cur);
	if (y + 1 < n && !used[arr[y + 1][x] - 'A'])
	{
		cur++;
		used[arr[y + 1][x] - 'A'] = true;
		dfs(x, y + 1);
		used[arr[y + 1][x] - 'A'] = false;
		cur--;
	}
	if (x + 1 < m && !used[arr[y][x + 1] - 'A'])
	{
		cur++;
		used[arr[y][x + 1] - 'A'] = true;
		dfs(x + 1, y);
		used[arr[y][x + 1] - 'A'] = false;
		cur--;
	}
	if (y - 1 >= 0 && !used[arr[y - 1][x] - 'A'])
	{
		cur++;
		used[arr[y - 1][x] - 'A'] = true;
		dfs(x, y - 1);
		used[arr[y - 1][x] - 'A'] = false;
		cur--;
	}
	if (x - 1 >= 0 && !used[arr[y][x - 1] - 'A'])
	{
		cur++;
		used[arr[y][x - 1] - 'A'] = true;
		dfs(x - 1, y);
		used[arr[y][x - 1] - 'A'] = false;
		cur--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j];
	}
	used[arr[0][0] - 'A'] = true;
	dfs(0, 0);
	cout << ans;
}