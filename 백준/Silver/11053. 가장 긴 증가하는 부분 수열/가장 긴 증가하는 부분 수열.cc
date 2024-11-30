#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[1000], dp[1000];

	int N, max_len = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
	}

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		int check = arr[i];

		for (int j = 0; j < i; j++)
		{
			if (arr[j] < check)
			{
				if(cnt < dp[j])
					cnt = dp[j];
			}
		}

		dp[i] = cnt + 1;
		if (dp[i] > max_len)
			max_len = dp[i];
	}

	cout << max_len;
}  