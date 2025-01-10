#include <iostream>
#include <algorithm>

using namespace std;

int n;

char arr[100][100];

bool vis[100][100]{ false };
bool vis_rg[100][100] = { false };

int mx[4] = { -1, 1, 0, 0 };
int my[4] = { 0, 0, -1, 1 };

void sep(int _x, int _y, char color)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = _x + mx[i];
		int ny = _y + my[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[ny][nx] || arr[ny][nx] != color)
			continue;
		else
		{
			vis[ny][nx] = true;
			sep(nx, ny, color);
		}
	}
}

void sep_rg(int _x, int _y, char color)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = _x + mx[i];
		int ny = _y + my[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis_rg[ny][nx])
			continue;
		if (arr[ny][nx] != color && (arr[ny][nx] == 'B' || color == 'B'))
			continue;
		else
		{
			vis_rg[ny][nx] = true;
			sep_rg(nx, ny, color);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans1 = 0, ans2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j])
			{
				vis[i][j] = true;
				ans1++;
				sep(j, i, arr[i][j]);
			}
			if (!vis_rg[i][j])
			{
				vis_rg[i][j] = true;
				ans2++;
				sep_rg(j, i, arr[i][j]);
			}
		}
	}
	cout << ans1 << " " << ans2;
}