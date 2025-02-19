#include <iostream>

using namespace std;

int main() {
	int height = -1, sec = 99999999;
	int board[500][500];

	int n, m, b;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	for (int k = 0; k <= 256; k++)
	{
		int blocks = b;
		int tsec = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] > k)
				{
					blocks += (board[i][j] - k);
					tsec += 2 * (board[i][j] - k);
				}
				else if (board[i][j] == k)
					continue;
				else if (board[i][j] < k)
				{
					blocks -= (k - board[i][j]);
					tsec += (k - board[i][j]);
				}
			}
		}
		if (blocks < 0)
			continue;
		if (sec >= tsec)
		{
			sec = tsec;
			height = k;
		}
	}
	cout << sec << " " << height;
}