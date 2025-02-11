#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];
int acnt[625] = { 0 };

int mx[4] = { -1, 1, 0 ,0 };
int my[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int num)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = mx[i] + x;
		int ny = my[i] + y;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (arr[ny][nx] == 1)
		{
			acnt[num - 2]++;
			arr[ny][nx] = num;
			dfs(nx, ny, num);
		}
	}
}

int main()
{
	int cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j] - '0';
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				cnt++;
				acnt[cnt - 2]++;
				arr[i][j] = cnt;
				dfs(j, i, cnt);
			}
		}
	}
	sort(acnt, acnt + (cnt - 1));
	cout << cnt - 1 << '\n';
	for (int i = 0; i < cnt - 1; i++)
		cout << acnt[i] << '\n';
}