#include <iostream>

using namespace std;

int type[8][3] = { {0,1,2}, {0,1,3},{0,2,4},{0,3,4},{1,2,5},{1,3,5},{2,4,5},{3,4,5} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[6];

	long long ans, N;

	cin >> N;

	for (int i = 0; i < 6; i++)
		cin >> arr[i];
	
	int max, min;

	max = arr[0];
	min = arr[0];

	ans = arr[0];

	for (int i = 1; i < 6; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		ans += arr[i];
	}
	
	if (N == 1)
	{
		cout << ans - max;
		return 0;
	}

	int d2 = 0, d3 = 0;
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			int num = arr[i] + arr[j];
			if (d2 == 0)
				d2 = num;
			else if (d2 > num && i + j != 5)
				d2 = num;
		}
	}

	d3 = arr[type[0][0]] + arr[type[0][1]] + arr[type[0][2]];

	for (int i = 1; i < 8; i++)
	{
		int num = arr[type[i][0]] + arr[type[i][1]] + arr[type[i][2]];
		if (d3 > num)
			d3 = num;
	}

	ans = 4 * min * (N - 1) * (N - 2);
	ans += 4 * d2 * (N - 1);
	ans += 4 * d3 + 4 * d2 * (N - 2);
	ans	+= min * (N - 2) * (N - 2);
	cout << ans;
}