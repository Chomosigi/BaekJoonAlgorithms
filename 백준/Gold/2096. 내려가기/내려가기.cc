#include <iostream>
#include <algorithm>

using namespace std;

int dp_max[3], dp_min[3], arr[3];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int hi = 0, lo = 900000;
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
		dp_max[i] = arr[i];
		dp_min[i] = arr[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[j];
		dp_max[0] = max(dp_max[0], dp_max[1]) + arr[0];
		dp_min[0] = min(dp_min[0], dp_min[1]) + arr[0];
		dp_max[2] = max(dp_max[1], dp_max[2]) + arr[2];
		dp_min[2] = min(dp_min[1], dp_min[2]) + arr[2];
		dp_max[1] = max(dp_max[0] - arr[0], dp_max[2] - arr[2]) + arr[1];
		dp_min[1] = min(dp_min[0] - arr[0], dp_min[2] - arr[2]) + arr[1];
	}
	for (int i = 0; i < 3; i++)
	{
		if (hi < dp_max[i])
			hi = dp_max[i];
		if (lo > dp_min[i])
			lo = dp_min[i];
	}

	cout << hi << " " << lo;
}