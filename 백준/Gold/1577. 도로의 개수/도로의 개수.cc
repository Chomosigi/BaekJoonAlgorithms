#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int time;
	cin >> time;
	long long arr[101][101] = { 0 };
	bool cons[202][202] = { false };
	int mx[2] = { 0, -1 };
	int my[2] = { -1, 0 };

	for (int i = 0; i < time; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cons[b + d][a + c] = true;
	}
	arr[0][0] = 1;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int nx = j + mx[k];
				int ny = i + my[k];

				if (nx >= 0 && ny >= 0 && nx <= n && ny <= m)
				{
					if (!cons[ny + i][nx + j])
						arr[i][j] += arr[ny][nx];
				}
			}
		}
	}
	cout << arr[m][n];
}