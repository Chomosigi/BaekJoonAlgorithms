#include <iostream>

using namespace std;

int arr[3];
int dp[3];
int temp[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp[j] = dp[j];
			cin >> arr[j];
		}
		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
				dp[j] = arr[j];
		}
		else
		{
			dp[0] = min(temp[1], temp[2]) + arr[0];
			dp[1] = min(temp[0], temp[2]) + arr[1];
			dp[2] = min(temp[0], temp[1]) + arr[2];
		}
	}

	int answer = dp[0];

	for (int i = 1; i < 3; i++)
	{
		if (answer > dp[i])
			answer = dp[i];
	}

	cout << answer;

	return 0;
}