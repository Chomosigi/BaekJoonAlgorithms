#include <iostream>

using namespace std;

bool pat[4][19][19];

int move_x[4] = { 0, 1, 1, 1 };
int move_y[4] = { 1, 0, -1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[19][19];

	int cnt = 0;
	int prev = 0;
	int start_x = -1;
	int start_y = -1;

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			prev = arr[j][i];
			if (prev == 0)
			{
				for (int k = 0; k < 4; k++)
					pat[k][j][i] = 1;
			}
			else
			{
				start_x = i;
				start_y = j;
				
				for (int k = 0; k < 4; k++)
				{
					int cur_x = start_x;
					int cur_y = start_y;
					if (pat[k][cur_y][cur_x] == true)
						continue;
					cnt = 0;
					while (arr[cur_y][cur_x] == prev)
					{
						pat[k][cur_y][cur_x] = true;
						cur_x += move_x[k];
						cur_y += move_y[k];
						cnt++;
					}

					if (cnt == 5)
					{
						cout << prev << "\n";
						cout << start_y + 1 << " " << start_x + 1;
						return 0;
					}
				}
			}

		}
	}
	if (cnt != 5)
	{
		cout << "0";
		return 0;
	}
}