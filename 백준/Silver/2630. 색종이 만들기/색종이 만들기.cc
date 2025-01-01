#include <iostream>

using namespace std;

int arr[128][128];

int blue = 0, white = 0;

void fc(int x, int y, int n)
{
	int first = arr[x][y];
	bool dif = false;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (first != arr[i][j])
			{
				dif = true;
				break;
			}
		}
	}
	if (dif)
	{
		fc(x, y, n / 2);
		fc(x + n / 2, y, n / 2);
		fc(x, y + n / 2, n / 2);
		fc(x + n / 2, y + n / 2, n / 2);
	}
	else
	{
		if (first == 1)
			blue++;
		else
			white++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	fc(0, 0, n);
	cout << white << "\n";
	cout << blue << "\n";
}