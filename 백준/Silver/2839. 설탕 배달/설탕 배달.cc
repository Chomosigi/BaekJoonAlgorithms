#include <iostream>

using namespace std;

int answer = -1;

void dfs(int cur, int target, int cnt)
{
	if (cur == target)
		answer = cnt;
	else if (cur < target && answer == -1)
	{
		dfs(cur + 5, target, cnt + 1);
		dfs(cur + 3, target, cnt + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	dfs(0, T, 0);

	cout << answer;

	return 0;
}